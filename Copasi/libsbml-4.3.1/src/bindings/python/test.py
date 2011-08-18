#!/usr/bin/env python
##
## @file    test.py
## @brief   AutoRunner for Python test scripts
## @author  Akiya Jouraku
##
## $Id: test.py 12780 2011-02-08 04:12:54Z mhucka $
## $HeadURL: http://sbml.svn.sourceforge.net/svnroot/sbml/trunk/libsbml/src/bindings/python/test.py $
##
## <!--------------------------------------------------------------------------
## This file is part of libSBML.  Please visit http://sbml.org for more
## information about SBML, and the latest version of libSBML.
##
## Copyright (C) 2009-2011 jointly by the following organizations: 
##     1. California Institute of Technology, Pasadena, CA, USA
##     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
##  
## Copyright (C) 2006-2008 by the California Institute of Technology,
##     Pasadena, CA, USA 
##  
## Copyright (C) 2002-2005 jointly by the following organizations: 
##     1. California Institute of Technology, Pasadena, CA, USA
##     2. Japan Science and Technology Agency, Japan
## 
## This library is free software; you can redistribute it and/or modify it
## under the terms of the GNU Lesser General Public License as published by
## the Free Software Foundation.  A copy of the license agreement is provided
## in the file named "LICENSE.txt" included with this software distribution
## and also available online as http://sbml.org/software/libsbml/license.html
## ---------------------------------------------------------------------- -->*/

import os
import sys
import re
import glob
import unittest

test_basedir = 'test'
test_subdirs = ('sbml','xml','math','annotation') 
test_files   = "/Test*.py"

def suite():
  suite = unittest.TestSuite()
  for subdir in test_subdirs :
    for file in glob.glob( test_basedir + '/' + subdir + '/' + test_files ) :
      module_name = re.compile(r"\.py$").sub('',os.path.basename(file)) 
      module = __import__(module_name)
      class_name = getattr(module, module_name)
      suite.addTest(unittest.makeSuite(class_name))
  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)
