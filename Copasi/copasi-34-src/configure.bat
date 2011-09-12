@echo off 

echo @echo off > config.status.bat

echo echo running: configure.bat %* >> config.status.bat
echo configure.bat %* >> config.status.bat

set arguments="COPASI_SRC_PACKAGE=true"

:LOOP
if '%1' == ''                      goto QMAKE
if '%1' == '--enable-debug'        goto DEBUG
if '%1' == '--disable-debug'       goto RELEASE
if '%1' == '--enable-release'      goto RELEASE
if '%1' == '--disable-release'     goto DEBUG

set arguments=%arguments% %1
shift
goto LOOP

:DEBUG
:RELEASE
rem debug and release is ignored
shift
goto LOOP

:QMAKE
if '%QT4DIR%' == '' goto QT4DIR_NotSet
set QMAKE=%QT4DIR%\bin\qmake
goto CONFIGURE

:QT4DIR_NotSet
if '%QTDIR%' == '' goto QTDIR_NotSet
set QMAKE=%QTDIR%\bin\qmake
goto CONFIGURE

:QTDIR_NotSet
set QMAKE=qmake

:CONFIGURE

rem Clean
del /S Makefile*
del copasi\commandline\debug\CConfigurationFile.obj
del copasi\commandline\release\CConfigurationFile.obj
del copasi\UI\debug\copasiui3window.obj 
del copasi\UI\release\copasiui3window.obj 
del copasi\UI\debug\CQSplashWidget.obj 
del copasi\UI\release\CQSplashWidget.obj 
del copasi\CopasiUI\debug\main.obj 
del copasi\CopasiUI\release\main.obj 
del copasi\CopasiSE\debug\CopasiSE.obj
del copasi\CopasiSE\release\CopasiSE.obj

cd copasi
echo Executing in copasi:

copy copasi.pro tmp_win32.pro
echo   %QMAKE% -tp vc -r "CONFIG-=release" "CONFIG-=debug" %arguments% tmp_win32.pro
%QMAKE% -tp vc -r "CONFIG-=release" "CONFIG-=debug" %arguments% tmp_win32.pro
del tmp_win32*

echo   %QMAKE% "CONFIG-=release" "CONFIG-=debug" %arguments%
%QMAKE% "CONFIG-=release" "CONFIG-=debug" %arguments%

nmake qmake_all

cd libs
nmake qmake_all
cd ..

cd ..
