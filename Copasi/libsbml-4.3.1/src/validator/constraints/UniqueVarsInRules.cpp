/**
 * @cond doxygen-libsbml-internal
 *
 * @file    UniqueVarsInRules.cpp
 * @brief   Ensures variables for all Rules are unique
 * @author  Ben Bornstein
 *
 * $Id: UniqueVarsInRules.cpp 13266 2011-03-21 22:26:50Z mhucka $
 * $HeadURL: http://sbml.svn.sourceforge.net/svnroot/sbml/trunk/libsbml/src/validator/constraints/UniqueVarsInRules.cpp $
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
 * the Free Software Foundation.  A copy of the license agreement is
 * provided in the file named "LICENSE.txt" included with this software
 * distribution.  It is also available online at
 * http://sbml.org/software/libsbml/license.html
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA.
 */


#include <sbml/Model.h>
#include <sbml/Rule.h>

#include "UniqueVarsInRules.h"

/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSBML_CPP_NAMESPACE_BEGIN

static const char* PREAMBLE =
    "The value of the 'variable' field in all <assignmentRule> and "
    "<rateRule> definitions must be unique across the set of all such rule "
    "definitions in a model. (References: L2V1 Section 4.8.4; L2V2 Section "
    "4.11.3.)";


/**
 * Creates a new Constraint with the given constraint id.
 */
UniqueVarsInRules::UniqueVarsInRules (unsigned int id, Validator& v) :
  UniqueIdBase(id, v)
{
}


/**
 * Destroys this Constraint.
 */
UniqueVarsInRules::~UniqueVarsInRules ()
{
}


/**
 * @return the fieldname ("variable") to use when logging constraint
 * violations.
 */
const char*
UniqueVarsInRules::getFieldname ()
{
  return "variable";
}


/**
 * @return the preamble to use when logging constraint violations.
 */
const char*
UniqueVarsInRules::getPreamble ()
{
  return PREAMBLE;
}


/**
 * Checks that all ids on KineticLawParameters are unique.
 */
void
UniqueVarsInRules::doCheck (const Model& m)
{
  for (unsigned int n = 0; n < m.getNumRules(); ++n) checkId( *m.getRule(n) );
}

LIBSBML_CPP_NAMESPACE_END

/** @endcond */
