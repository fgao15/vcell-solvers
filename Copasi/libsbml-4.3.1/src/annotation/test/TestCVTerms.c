/**
 * \file    TestCVTerms.cpp
 * \brief   CVTerms unit tests
 * \author  Sarah Keating
 *
 * $Id: TestCVTerms.c 12780 2011-02-08 04:12:54Z mhucka $
 * $HeadURL: http://sbml.svn.sourceforge.net/svnroot/sbml/trunk/libsbml/src/annotation/test/TestCVTerms.c $
 *
 * <!--------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright (C) 2009-2011 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. EMBL European Bioinformatics Institute (EBML-EBI), Hinxton, UK
 *  
 * Copyright (C) 2006-2008 by the California Institute of Technology,
 *     Pasadena, CA, USA 
 *  
 * Copyright (C) 2002-2005 jointly by the following organizations: 
 *     1. California Institute of Technology, Pasadena, CA, USA
 *     2. Japan Science and Technology Agency, Japan
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution
 * and also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

#include <sbml/common/common.h>
#include <sbml/annotation/CVTerm.h>
#include <sbml/xml/XMLNode.h>
#include <sbml/xml/XMLTriple.h>

#include <check.h>

#if __cplusplus
CK_CPPSTART
#endif



START_TEST (test_CVTerm_create)
{
  CVTerm_t *term = CVTerm_createWithQualifierType(MODEL_QUALIFIER);

  fail_unless(term != NULL);
  fail_unless(CVTerm_getQualifierType(term) == MODEL_QUALIFIER);
  CVTerm_free(term);

}
END_TEST

START_TEST (test_CVTerm_set_get)
{
  CVTerm_t *term = CVTerm_createWithQualifierType(MODEL_QUALIFIER);

  fail_unless(term != NULL);
  fail_unless(CVTerm_getQualifierType(term) == MODEL_QUALIFIER);
  
  CVTerm_setModelQualifierType(term, BQM_IS);

  fail_unless(term != NULL);
  fail_unless(CVTerm_getQualifierType(term) == MODEL_QUALIFIER);
  fail_unless(CVTerm_getModelQualifierType(term) == BQM_IS);

  CVTerm_setQualifierType(term, BIOLOGICAL_QUALIFIER);
  CVTerm_setBiologicalQualifierType( term, BQB_IS);

  fail_unless(CVTerm_getQualifierType(term) == BIOLOGICAL_QUALIFIER);
  fail_unless(CVTerm_getBiologicalQualifierType(term) == BQB_IS);

  
  
  CVTerm_free(term);
}
END_TEST

START_TEST (test_CVTerm_createFromNode)
{
  XMLAttributes_t * xa;
  XMLTriple_t * qual_triple = XMLTriple_createWith ("is", "", "bqbiol");
  XMLTriple_t * bag_triple = XMLTriple_create ();
  XMLTriple_t * li_triple = XMLTriple_create();
  XMLAttributes_t * att = XMLAttributes_create ();
  XMLAttributes_add(att, "", "This is my resource");
  XMLAttributes_t *att1 = XMLAttributes_create();

  XMLToken_t * li_token = XMLToken_createWithTripleAttr(li_triple, att);
  XMLToken_t * bag_token = XMLToken_createWithTripleAttr(bag_triple, att1);
  XMLToken_t * qual_token = XMLToken_createWithTripleAttr(qual_triple, att1);

  XMLNode_t * li = XMLNode_createFromToken(li_token);
  XMLNode_t * bag = XMLNode_createFromToken(bag_token);
  XMLNode_t * node = XMLNode_createFromToken(qual_token);

  XMLNode_addChild(bag, li);
  XMLNode_addChild(node, bag);


  CVTerm_t *term = CVTerm_createFromNode(node);

  fail_unless(term != NULL);
  fail_unless(CVTerm_getQualifierType(term) == BIOLOGICAL_QUALIFIER);
  fail_unless(CVTerm_getBiologicalQualifierType(term) == BQB_IS);

  xa = CVTerm_getResources(term);

  fail_unless(XMLAttributes_getLength(xa) == 1);
  fail_unless(!strcmp(XMLAttributes_getName(xa, 0), "rdf:resource"));
  fail_unless(!strcmp(XMLAttributes_getValue(xa, 0), "This is my resource"));

  XMLTriple_free(qual_triple);
  XMLTriple_free(bag_triple);
  XMLTriple_free(li_triple);
  XMLToken_free(li_token);
  XMLToken_free(bag_token);
  XMLToken_free(qual_token);
  XMLAttributes_free(att);
  XMLAttributes_free(att1);
  CVTerm_free(term);
  XMLNode_free(node);
  XMLNode_free(bag);
  XMLNode_free(li);
  

}
END_TEST

START_TEST (test_CVTerm_addResource)
{
  CVTerm_t *term = CVTerm_createWithQualifierType(MODEL_QUALIFIER);
  const char * resource = "GO6666";
  XMLAttributes_t *xa;

  fail_unless(term != NULL);
  fail_unless(CVTerm_getQualifierType(term) == MODEL_QUALIFIER);
  
  CVTerm_addResource(term, resource);

  xa = CVTerm_getResources(term);

  fail_unless(XMLAttributes_getLength(xa) == 1);
  fail_unless(!strcmp(XMLAttributes_getName(xa, 0), "rdf:resource"));
  fail_unless(!strcmp(XMLAttributes_getValue(xa, 0), "GO6666"));


  
  CVTerm_free(term);

}
END_TEST


START_TEST (test_CVTerm_getResources)
{
  CVTerm_t *term = CVTerm_createWithQualifierType(MODEL_QUALIFIER);
  const char * resource = "GO6666";
  const char * resource1 = "OtherURI";
  unsigned int number;
  
  CVTerm_addResource(term, resource);
  CVTerm_addResource(term, resource1);

  number = CVTerm_getNumResources(term);

  fail_unless(number == 2);
  fail_unless(!strcmp(CVTerm_getResourceURI(term, 0), "GO6666"));
  fail_unless(!strcmp(CVTerm_getResourceURI(term, 1), "OtherURI"));


  
  CVTerm_free(term);

}
END_TEST

START_TEST (test_CVTerm_accessWithNULL)
{
	fail_unless (CVTerm_addResource(NULL, NULL) == LIBSBML_OPERATION_FAILED);
	fail_unless (CVTerm_clone(NULL) == NULL);
	fail_unless (CVTerm_createFromNode(NULL) == NULL);

	// make sure we don't crash on freeing nothing
    CVTerm_free(NULL);

	fail_unless (CVTerm_getBiologicalQualifierType(NULL) == BQB_UNKNOWN);
	fail_unless (CVTerm_getModelQualifierType(NULL) == BQM_UNKNOWN);
	fail_unless (CVTerm_getNumResources(NULL) == SBML_INT_MAX);
	fail_unless (CVTerm_getQualifierType(NULL) == UNKNOWN_QUALIFIER);
	fail_unless (CVTerm_getResources(NULL) == NULL);
	fail_unless (CVTerm_getResourceURI(NULL, 0) == NULL);
	fail_unless (CVTerm_hasRequiredAttributes(NULL) == 0);
	fail_unless (CVTerm_removeResource(NULL, NULL) == LIBSBML_INVALID_OBJECT);
	fail_unless (CVTerm_setBiologicalQualifierType(NULL, BQB_UNKNOWN) == LIBSBML_INVALID_OBJECT);
	fail_unless (CVTerm_setModelQualifierType(NULL, BQM_UNKNOWN) == LIBSBML_INVALID_OBJECT);
	fail_unless (CVTerm_setQualifierType(NULL, UNKNOWN_QUALIFIER) == LIBSBML_INVALID_OBJECT);

}
END_TEST

Suite *
create_suite_CVTerms (void)
{
  Suite *suite = suite_create("CVTerms");
  TCase *tcase = tcase_create("CVTerms");

  tcase_add_test( tcase, test_CVTerm_create          );
  tcase_add_test( tcase, test_CVTerm_set_get         );
  tcase_add_test( tcase, test_CVTerm_addResource     );
  tcase_add_test( tcase, test_CVTerm_createFromNode  );
  tcase_add_test( tcase, test_CVTerm_getResources    );
  tcase_add_test( tcase, test_CVTerm_accessWithNULL  );
  suite_add_tcase(suite, tcase);

  return suite;
};


#if __cplusplus
CK_CPPEND
#endif
