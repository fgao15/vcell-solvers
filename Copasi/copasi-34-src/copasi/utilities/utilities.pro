# Begin CVS Header 
#   $Source: /fs/turing/cvs/copasi_dev/copasi/utilities/utilities.pro,v $ 
#   $Revision: 1.27.2.2 $ 
#   $Name: Build-33 $ 
#   $Author: shoops $ 
#   $Date: 2010/11/13 16:56:02 $ 
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
# $Revision: 1.27.2.2 $ $Author: shoops $ $Date: 2010/11/13 16:56:02 $
######################################################################

LIB = utilities
DISTFILES = utilities.pro

# Input
HEADERS += CAnnotatedMatrix.h \
           CCopasiException.h \
           CCopasiMessage.h \
           CCopasiMethod.h \
           CCopasiNode.h \
           CCopasiParameter.h \
           CCopasiParameterGroup.h \
           CCopasiProblem.h \
           CCopasiTask.h \
           CCopasiTree.h \
           CCopasiVector.h \
           CDependencyGraph.h \
           CDimension.h \
           CDirEntry.h \
           CIndexedPriorityQueue.h \
           CluX.h \
           CMatrix.h \
           copasimathml.h \
           CopasiTime.h \
           COutputHandler.h \
           CProcessReport.h \
           CReadConfig.h \
           CSlider.h \
           CSparseMatrix.h \
           CSort.h \
           CTableCell.h \
           CVector.h \
           CVersion.h \
           messages.h \
           utility.h

SOURCES += CAnnotatedMatrix.cpp \
           CCopasiException.cpp \
           CCopasiMessage.cpp \
           CCopasiMethod.cpp \
           CCopasiParameter.cpp \
           CCopasiParameterGroup.cpp \
           CCopasiProblem.cpp \
           CCopasiTask.cpp \
           CDependencyGraph.cpp \
           CDimension.cpp \
           CDirEntry.cpp \
           CIndexedPriorityQueue.cpp \
           CluX.cpp \
           CopasiTime.cpp \
           COutputHandler.cpp \
           CProcessReport.cpp \
           CReadConfig.cpp \
           CSlider.cpp \
           CSparseMatrix.cpp \
           CTableCell.cpp \
           CVersion.cpp \
           utility.cpp

include(../lib.pri)
include(../common.pri)
include(../srcDistribution.pri)
