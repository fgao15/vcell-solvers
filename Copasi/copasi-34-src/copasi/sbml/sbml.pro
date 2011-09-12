# Begin CVS Header
#   $Source: /fs/turing/cvs/copasi_dev/copasi/sbml/sbml.pro,v $
#   $Revision: 1.23.2.2 $
#   $Name: Build-33 $
#   $Author: shoops $
#   $Date: 2010/11/13 16:55:59 $
# End CVS Header

# Copyright (C) 2010 by Pedro Mendes, Virginia Tech Intellectual 
# Properties, Inc., University of Heidelberg, and The University 
# of Manchester. 
# All rights reserved. 

# Copyright (C) 2008 by Pedro Mendes, Virginia Tech Intellectual
# Properties, Inc., EML Research, gGmbH, University of Heidelberg,
# and The University of Manchester.
# All rights reserved.

# Copyright (C) 2001 - 2007 by Pedro Mendes, Virginia Tech Intellectual
# Properties, Inc. and EML Research, gGmbH.
# All rights reserved.

LIB = sbmlimport
SRC_TARGET = sbml
DISTFILES = sbml.pro

# Input
HEADERS += StdException.h \
           CSBMLExporter.h \
           ConverterASTNode.h \
           SBMLImporter.h \
           SBMLIncompatibility.h \
           SBMLReference.h \
           SBMLUtils.h \
           UnitConversionFactory.hpp \
           incompatibilities.h



SOURCES += StdException.cpp \
           CSBMLExporter.cpp \
           ConverterASTNode.cpp \
           SBMLImporter.cpp \
           SBMLIncompatibility.cpp \
           SBMLReference.cpp \
           SBMLUtils.cpp \
           UnitConversionFactory.cpp

include(../lib.pri)
include(../common.pri)
include(../srcDistribution.pri)

contains(BUILD_OS, WIN32) {
  DEFINES += LIBSBML_STATIC
}
