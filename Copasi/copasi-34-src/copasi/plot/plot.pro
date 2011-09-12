# Begin CVS Header 
#   $Source: /fs/turing/cvs/copasi_dev/copasi/plot/plot.pro,v $ 
#   $Revision: 1.27.2.2 $ 
#   $Name: Build-33 $ 
#   $Author: shoops $ 
#   $Date: 2010/11/13 16:55:58 $ 
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
# $Revision: 1.27.2.2 $ $Author: shoops $ $Date: 2010/11/13 16:55:58 $
######################################################################

LIB = plot
DISTFILES = plot.pro

CONFIG -= qt

HEADERS += CPlotItem.h \
           CPlotSpecification.h \
           COutputDefinitionVector.h

SOURCES += CPlotItem.cpp \
           CPlotSpecification.cpp \
           COutputDefinitionVector.cpp \

include(../lib.pri)
include(../common.pri)
include(../srcDistribution.pri)
