# Begin CVS Header 
#   $Source: /fs/turing/cvs/copasi_dev/copasi/sensitivities/sensitivities.pro,v $ 
#   $Revision: 1.8.2.2 $ 
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
# $Revision: 1.8.2.2 $ $Author: shoops $ $Date: 2010/11/13 16:56:00 $
######################################################################

LIB = sensitivities
DISTFILES = sensitivities.pro

# Input
HEADERS += CSensMethod.h \
           CSensProblem.h \
           CSensTask.h

SOURCES += CSensMethod.cpp \
           CSensProblem.cpp \
           CSensTask.cpp

include(../lib.pri)
include(../common.pri)
include(../srcDistribution.pri)
