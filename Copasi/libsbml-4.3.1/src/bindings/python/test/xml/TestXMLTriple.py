#
# @file    TestXMLTriple.py
# @brief   XMLTriple unit tests
#
# @author  Akiya Jouraku (Python conversion)
# @author  Michael Hucka <mhucka@caltech.edu> 
#
# $Id: TestXMLTriple.py 11441 2010-07-09 02:22:23Z mhucka $
# $HeadURL: http://sbml.svn.sourceforge.net/svnroot/sbml/trunk/libsbml/src/bindings/python/test/xml/TestXMLTriple.py $
#
# ====== WARNING ===== WARNING ===== WARNING ===== WARNING ===== WARNING ======
#
# DO NOT EDIT THIS FILE.
#
# This file was generated automatically by converting the file located at
# src/xml/test/TestXMLTriple.c
# using the conversion program dev/utilities/translateTests/translateTests.pl.
# Any changes made here will be lost the next time the file is regenerated.
#
# -----------------------------------------------------------------------------
# This file is part of libSBML.  Please visit http://sbml.org for more
# information about SBML, and the latest version of libSBML.
#
# Copyright 2005-2010 California Institute of Technology.
# Copyright 2002-2005 California Institute of Technology and
#                     Japan Science and Technology Corporation.
# 
# This library is free software; you can redistribute it and/or modify it
# under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation.  A copy of the license agreement is provided
# in the file named "LICENSE.txt" included with this software distribution
# and also available online as http://sbml.org/software/libsbml/license.html
# -----------------------------------------------------------------------------

import sys
import unittest
import libsbml


class TestXMLTriple(unittest.TestCase):


  def test_XMLTriple_create(self):
    t = libsbml.XMLTriple()
    self.assert_( t != None )
    self.assert_( t.isEmpty() != False )
    _dummyList = [ t ]; _dummyList[:] = []; del _dummyList
    t = libsbml.XMLTriple("attr", "uri", "prefix")
    self.assert_( (  "attr" != t.getName() ) == False )
    self.assert_( (  "uri" != t.getURI() ) == False )
    self.assert_( (  "prefix" != t.getPrefix() ) == False )
    self.assert_( (  "prefix:attr" != t.getPrefixedName() ) == False )
    self.assert_( t.isEmpty() == False )
    _dummyList = [ t ]; _dummyList[:] = []; del _dummyList
    t = libsbml.XMLTriple("attr", "uri", "")
    self.assert_( (  "attr" != t.getName() ) == False )
    self.assert_( (  "uri" != t.getURI() ) == False )
    self.assert_( t.getPrefix() == "" )
    self.assert_( (  "attr" != t.getPrefixedName() ) == False )
    self.assert_( t.isEmpty() == False )
    _dummyList = [ t ]; _dummyList[:] = []; del _dummyList
    pass  

def suite():
  suite = unittest.TestSuite()
  suite.addTest(unittest.makeSuite(TestXMLTriple))

  return suite

if __name__ == "__main__":
  if unittest.TextTestRunner(verbosity=1).run(suite()).wasSuccessful() :
    sys.exit(0)
  else:
    sys.exit(1)