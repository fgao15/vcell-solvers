/**
 * @cond doxygen-libsbml-internal
 *
 * @file    UniqueIdsForUnitDefinitions.cpp
 * @brief   Ensures the ids for all UnitDefinitions in a Model are unique
 * @author  Ben Bornstein
 *
 * $Id: UniqueIdsForUnitDefinitions.cpp 13266 2011-03-21 22:26:50Z mhucka $
 * $HeadURL: http://sbml.svn.sourceforge.net/svnroot/sbml/trunk/libsbml/src/validator/constraints/UniqueIdsForUnitDefinitions.cpp $
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
#include <sbml/UnitDefinition.h>

#include "UniqueIdsForUnitDefinitions.h"

/** @cond doxygen-ignored */

using namespace std;

/** @endcond */

LIBSBML_CPP_NAMESPACE_BEGIN

static const char* PREAMBLE =
    "The value of the 'id' field of every <unitDefinition> must be unique "
    "across the set of all <unitDefinition>s in the entire model. "
    "(References: L2V2 Section 4.4; L2V1 Section 3.4.1 and 4.4.1.)";


/**
 * Creates a new Constraint with the given constraint id.
 */
UniqueIdsForUnitDefinitions::UniqueIdsForUnitDefinitions ( unsigned int id,
                                                           Validator& v ) :
  UniqueIdBase(id, v)
{
}


/**
 * Destroys this Constraint.
 */
UniqueIdsForUnitDefinitions::~UniqueIdsForUnitDefinitions ()
{
}


/**
 * @return the preamble to use when logging constraint violations.
 */
const char*
UniqueIdsForUnitDefinitions::getPreamble ()
{
  return PREAMBLE;
}


/**
 * Checks that all ids on UnitDefinitions are unique.
 */
void
UniqueIdsForUnitDefinitions::doCheck (const Model& m)
{
  unsigned int n, size;


  size = m.getNumUnitDefinitions();
  for (n = 0; n < size; ++n) checkId( *m.getUnitDefinition(n) );
}

LIBSBML_CPP_NAMESPACE_END

/** @endcond */
