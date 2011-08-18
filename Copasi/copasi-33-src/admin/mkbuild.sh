#!/bin/bash

PATH=$PATH:/bin:/usr/bin:/usr/local/bin

SCP=${COPASI_SCP:-scp}
AWK=${COPASI_AWK:-gawk}

if [ x"$COPASI_UPLOAD" != x ]; then
  function UPLOAD () {
    SRC=""
    while [ x"$2" != x ]; do
      SRC="$SRC $1"
      shift
    done
    echo ${SCP} ${SRC} ${COPASI_UPLOAD}/$1
    ${SCP} ${SRC} ${COPASI_UPLOAD}/$1
  }
else
  function UPLOAD () {
    echo "Skipping upload (environment variable COPASI_UPLOAD not set)."
  }
fi

pushd ../..

if [ x"$#" = x1 ]; then
  major=`${AWK} -- '$2 ~ "VERSION_MAJOR" {print $3}' copasi/copasiversion.h`
  minor=`${AWK} -- '$2 ~ "VERSION_MINOR" {print $3}' copasi/copasiversion.h`
  build=`${AWK} -- '$2 ~ "VERSION_BUILD" {print $3}' copasi/copasiversion.h`

  license="US"

  rm Copasi-$build-$1*.*

  case x"$1" in 
  xWIN32)
    . admin/mkWIN32.sh
    ;;

  xDarwin)
    if otool -L ./copasi/CopasiUI/CopasiUI.app/Contents/MacOS/CopasiUI \
      | grep libqt 2>&1 > /dev/null ;then
        echo ""
        echo "CopasiUI is dynamicall linked against Qt."
        echo "Please link the binary statically before making an image."
        echo ""
        exit 1
    fi
    
    SETFILE=/Developer/Tools/SetFile

# Create temporary package image drive
    hdiutil create Copasi-tmp.dmg -megabytes 400 -volname Copasi-$build-$1 \
      -fs HFS+ -layout NONE

# Mount temporary package image drive
    drive=`hdid Copasi-tmp.dmg | ${AWK} -- '{print $1}'`
    TMPDIR=`df -l | ${AWK} -- '$1 ~ "'$drive'" {print $6}'`
    echo $drive '->' $TMPDIR

    echo "Copying application bundle."
    mkdir ${TMPDIR}/copasi
    cp -r copasi/CopasiUI/CopasiUI.app ${TMPDIR}/copasi/

    strip ${TMPDIR}/copasi/CopasiUI.app/Contents/MacOS/CopasiUI

# copy the commandline version if it exists
    if [ -e copasi/CopasiSE/CopasiSE.app/Contents/MacOS/CopasiSE ] ; then    
      cp copasi/CopasiSE/CopasiSE.app/Contents/MacOS/CopasiSE ${TMPDIR}/copasi/
      strip ${TMPDIR}/copasi/CopasiSE
      
      if [ x"$license" = xUS ]; then
        UPLOAD ${TMPDIR}/copasi/CopasiSE \
          $license/Copasi-AllSE/$1/CopasiSE-$build
       fi
    fi  
    
# copy the icon into the Resources directory
    echo "Creating Resources directory."
    mkdir -p ${TMPDIR}/copasi/CopasiUI.app/Contents/Resources
    echo "Copy the icon file to the bundle."
    cp copasi.icns ${TMPDIR}/copasi/CopasiUI.app/Contents/Resources/

# set the icon in the Info.plist file in the Contents directory
# the icon file name is located between <string></string> tags in the line after
# <key>CFBundleIconFile</key>
# Maybe this would better be done with a dom parser.
echo "Set the icon in the Info.plist file."
    LINE=`grep -n "CFBundleIconFile" ${TMPDIR}/copasi/CopasiUI.app/Contents/Info.plist \
      | cut -c1`
    LINE=$((LINE+1))
    sed -e "${LINE}s%<string>.*</string>%<string>copasi.icns</string>%" \
      ${TMPDIR}/copasi/CopasiUI.app/Contents/Info.plist > ${TMPDIR}/tmp.plist
    mv ${TMPDIR}/tmp.plist ${TMPDIR}/copasi/CopasiUI.app/Contents/Info.plist

# copy default configuration
    echo "Make directory for default configuration"
    mkdir -p ${TMPDIR}/copasi/config
    echo "Copy default configuration files"
    cp ./copasi/MIRIAM/MIRIAMResources.xml ${TMPDIR}/copasi/config

# copy the examples into the Resources directory
    echo "Make example directory."
    mkdir -p ${TMPDIR}/copasi/examples
    echo "Copy examples to example directory."
    cp ./TestSuite/distribution/* \
      ${TMPDIR}/copasi/examples/
# we have defer this to later so that we are able to chown
#    chmod 444 ${TMPDIR}/copasi/examples/

# copy the files for the wizard into the Resources directory
    echo "Making directory for wizard."
    mkdir -p ${TMPDIR}/copasi/CopasiUI.app/Contents/Resources/doc/html
    echo "Copying files for wizard."
    cp ./copasi/wizard/help_html/*.html \
      ${TMPDIR}/copasi/CopasiUI.app/Contents/Resources/doc/html/
    cp -r ./copasi/wizard/help_html/figures \
      ${TMPDIR}/copasi/CopasiUI.app/Contents/Resources/doc/html/

# copy the Qt Framework into the image
    echo "Copying Frameworks:"
    pushd ${TMPDIR}/copasi
    macdeployqt CopasiUI.app/ -no-plugins
    popd

# add the readme to the image
    echo "Copying readme file."
    cp README_MAC.rtf ${TMPDIR}/copasi/COPASI-README.rtf

# add the license to the image
    echo "Copying license file."
    cp ./copasi/ArtisticLicense.txt ${TMPDIR}/copasi/LICENSE.txt

# set the bundles flag with SetFile
    echo "Setting the bundle flag."
    ${SETFILE} -a b ${TMPDIR}/copasi/CopasiUI.app

    chown -R 99:99 ${TMPDIR}/copasi
# this had been deferred earlier
    chmod 444 ${TMPDIR}/copasi/examples/*.*

# Unmount temporary image
    sleep 10
    hdiutil eject ${drive} || (sleep 10; hdiutil eject ${drive} -force)

    [ -e Copasi-$build-$1.dmg ] && rm -rf Copasi-$build-$1.dmg
    hdiutil convert -format UDCO Copasi-tmp.dmg -o Copasi-$build-$1.dmg
    rm -rf Copasi-tmp.dmg
    ;;

  xLinux|xSunOS)
    [ -e $build-$1 ] && rm -rf $build-$1
    mkdir $build-$1
    cd $build-$1

    mkdir copasi
    mkdir copasi/bin
    mkdir copasi/share
    mkdir copasi/share/copasi
    mkdir copasi/share/copasi/doc
    mkdir copasi/share/copasi/doc/html
    mkdir copasi/share/copasi/doc/html/figures
    mkdir copasi/share/copasi/examples
    mkdir copasi/share/copasi/icons
    mkdir copasi/share/copasi/config
    chmod -R 755 copasi

    cp ../README.$1 copasi/README
    chmod 644 copasi/README

    cp ../copasi/ArtisticLicense.txt copasi/LICENSE
    chmod 644 copasi/LICENSE

    cp ../copasi/CopasiUI/CopasiUI  copasi/bin
    chmod 755 copasi/bin/CopasiUI

    cp ../copasi/CopasiSE/CopasiSE  copasi/bin
    chmod 755 copasi/bin/CopasiSE

    cp ../copasi/MIRIAM/MIRIAMResources.xml copasi/share/copasi/config
    chmod 444 copasi/share/copasi/config/*

    cp ../TestSuite/distribution/* copasi/share/copasi/examples
    chmod 444 copasi/share/copasi/examples/*

    cp ../copasi/CopasiUI/icons/Copasi??-Alpha.xpm copasi/share/copasi/icons
    cp ../copasi/CopasiUI/icons/CopasiDoc??-Alpha.xpm copasi/share/copasi/icons
    chmod 644 copasi/share/copasi/icons/*

    cp ../copasi/wizard/help_html/*.html copasi/share/copasi/doc/html
    chmod 644 copasi/share/copasi/doc/html/*.html

    cp ../copasi/wizard/help_html/figures/*.png \
       copasi/share/copasi/doc/html/figures
    chmod 644 copasi/share/copasi/doc/html/figures/*.png

    tar -czf ../Copasi-$build-$1.tar.gz copasi

    if [ x"$license" = xUS ]; then
      UPLOAD copasi/bin/CopasiSE \
        $license/Copasi-AllSE/$1/CopasiSE-$build
    fi

    cp ../copasi/CopasiUI/CopasiUI-dynamic  copasi/bin/CopasiUI
    chmod 755 copasi/bin/CopasiUI

    cp ../copasi/CopasiSE/CopasiSE-dynamic  copasi/bin/CopasiSE
    chmod 755 copasi/bin/CopasiSE

    tar -czf ../Copasi-$build-$1-Dynamic.tar.gz copasi

    if [ x"$license" = xUS ]; then
      UPLOAD copasi/bin/CopasiSE \
        $license/Copasi-AllSE/$1-Dynamic/CopasiSE-$build
    fi
    
    cd ..
    ;;
  esac

  UPLOAD Copasi-$build-$1*.* \
    $license

else
  echo usage: mkbuild.sh BUILD_OS
fi
popd
