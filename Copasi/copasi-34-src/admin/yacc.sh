#!/bin/bash

YACC=${COPASI_YACC:-byacc}
PATH=$PATH:/bin:/usr/bin:/usr/local/bin

for arg in $@; do
  SOURCE_FILE=$arg
done

FILE_PREFIX=${SOURCE_FILE/%.*/}

TARGET_FILE_C=${SOURCE_FILE/%.*/_yacc.cpp}
TARGET_FILE_H=${SOURCE_FILE/%.*/_yacc.h}

echo compiling $SOURCE_FILE '==>' $TARGET_FILE_C, $TARGET_FILE_H

echo ${YACC} -dt -b $FILE_PREFIX -p $FILE_PREFIX $SOURCE_FILE
${YACC} -dt -b $FILE_PREFIX -p $FILE_PREFIX $SOURCE_FILE

# We make sure that the file have the epected endings.
[ -e $FILE_PREFIX.tab.cpp ] && mv $FILE_PREFIX.tab.cpp $FILE_PREFIX.tab.c
[ -e $FILE_PREFIX.tab.hpp ] && mv $FILE_PREFIX.tab.hpp $FILE_PREFIX.tab.h

sed -e 's/'$FILE_PREFIX'parse/yyparse/g' \
    -e '/#define yylex/d' \
    -e '/int yyparse (.*);/d' \
    -e 's/'$FILE_PREFIX'.tab.c/'$TARGET_FILE_C'/g' \
    -e 's/int yydebug;/int yydebug = YYDEBUG;/' \
    -e '/getenv()/d' \
    $FILE_PREFIX.tab.c > $$.tmp && \
mv $$.tmp $FILE_PREFIX.tab.c

if [ x`uname -a | grep -ic cygwin` = x"1" ]; then
  unix2dos $FILE_PREFIX.tab.c
  mv $FILE_PREFIX.tab.c y.tab.c
  unix2dos $FILE_PREFIX.tab.h
  mv $FILE_PREFIX.tab.h y.tab.h
fi
