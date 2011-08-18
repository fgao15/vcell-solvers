#!/bin/bash

PATH=$PATH:/bin:/usr/bin:/usr/local/bin

for arg in $@; do
  SOURCE_FILE=$arg
done

TARGET_FILE=lex.${SOURCE_FILE/%.*/.c}

echo compiling $SOURCE_FILE '==>' ${SOURCE_FILE/%.*/_lex.cpp}

flex  -t $SOURCE_FILE | \
     sed -e 's?<FlexLexer.h>?"copasi/FlexLexer.h"?' \
         -e 's/include <fstream>/include <iostream>/' \
         -e 's/using std::istream;/using namespace std;/' \
         -e '/using std::ostream;/d' \
         -e '/#include <unistd.h>/d' \
         -e '/class istream/i \
#include <iostream> \
' \
         -e 's/class istream/using namespace std/' \
         > $TARGET_FILE

if [ x`uname -a | grep -ic cygwin` = x"1" ]; then
  unix2dos $TARGET_FILE
fi
