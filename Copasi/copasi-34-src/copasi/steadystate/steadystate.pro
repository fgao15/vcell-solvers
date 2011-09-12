# Begin CVS Header 
#   $Source: /fs/turing/cvs/copasi_dev/copasi/steadystate/steadystate.pro,v $ 
#   $Revision: 1.13.2.2 $ 
#   $Name: Build-33 $ 
#   $Author: shoops $ 
#   $Date: 2010/11/13 16:56:00 $ 
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
# $Revision: 1.13.2.2 $ $Author: shoops $ $Date: 2010/11/13 16:56:00 $
######################################################################

LIB = steadystate
DISTFILES = steadystate.pro

# Input
HEADERS += CEigen.h \
           CMCAMethod.h \
           CMCAProblem.h \
	   CMCATask.h \
       	   CNewtonMethod.h \
           CSteadyStateMethod.h \
           CSteadyStateProblem.h \
           CSteadyStateTask.h

SOURCES += CEigen.cpp \
           CMCAMethod.cpp \
           CMCAProblem.cpp \
	   CMCATask.cpp \
           CNewtonMethod.cpp \
           CSteadyStateMethod.cpp \
           CSteadyStateProblem.cpp \
           CSteadyStateTask.cpp

include(../lib.pri)
include(../common.pri)
include(../srcDistribution.pri)
