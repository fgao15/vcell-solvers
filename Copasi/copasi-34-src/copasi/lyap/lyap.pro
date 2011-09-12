# Begin CVS Header 
#   $Source: /fs/turing/cvs/copasi_dev/copasi/lyap/lyap.pro,v $ 
#   $Revision: 1.8.2.2 $ 
#   $Name: Build-33 $ 
#   $Author: shoops $ 
#   $Date: 2010/11/13 16:55:56 $ 
# End CVS Header 

# Copyright (C) 2010 by Pedro Mendes, Virginia Tech Intellectual 
# Properties, Inc., University of Heidelberg, and The University 
# of Manchester. 
# All rights reserved. 

# Copyright (C) 2008 by Pedro Mendes, Virginia Tech Intellectual 
# Properties, Inc., EML Research, gGmbH, University of Heidelberg, 
# and The University of Manchester. 
# All rights reserved. 

######################################################################
# $Revision: 1.8.2.2 $ $Author: shoops $ $Date: 2010/11/13 16:55:56 $
######################################################################

LIB = lyap
DISTFILES = lyap.pro

# Input
HEADERS += CLyapWolfMethod.h \
           #CTimeSeries.h \
           CLyapMethod.h \
           CLyapProblem.h \
           CLyapTask.h

SOURCES += CLyapWolfMethod.cpp \
           #CTimeSeries.cpp \
           CLyapMethod.cpp \
           CLyapProblem.cpp \
           CLyapTask.cpp

include(../lib.pri)
include(../common.pri)
include(../srcDistribution.pri)
