/**
 * @file    SBMLTypeCodes.cpp
 * @brief   Enumeration to identify SBML objects at runtime
 * @author  Ben Bornstein
 *
 * $Id: SBMLTypeCodes.cpp 12780 2011-02-08 04:12:54Z mhucka $
 * $HeadURL: http://sbml.svn.sourceforge.net/svnroot/sbml/trunk/libsbml/src/sbml/SBMLTypeCodes.cpp $
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
#include <sbml/SBMLTypeCodes.h>

LIBSBML_CPP_NAMESPACE_BEGIN

static
const char* SBML_TYPE_CODE_STRINGS[] =
{
    "(Unknown SBML Type)"
  , "Compartment"
  , "CompartmentType"
  , "Constraint"
  , "Document"
  , "Event"
  , "EventAssignment"
  , "FunctionDefinition"
  , "InitialAssignment"
  , "KineticLaw"
  , "ListOf"
  , "Model"
  , "Parameter"
  , "Reaction"
  , "Rule"
  , "Species"
  , "SpeciesReference"
  , "SpeciesType"
  , "ModifierSpeciesReference"
  , "UnitDefinition"
  , "Unit"
  , "AlgebraicRule"
  , "AssignmentRule"
  , "RateRule"
  , "SpeciesConcentrationRule"
  , "CompartmentVolumeRule"
  , "ParameterRule"
  , "Trigger"
  , "Delay"
  , "StoichiometryMath"
  , "LocalParameter"

#ifdef USE_LAYOUT
  , "BoundingBox"
  , "CompartmentGlyph"
  , "CubicBezier"
  , "Curve"
  , "Dimensions"
  , "GraphicalObject"
  , "Layout"
  , "LineSegment"
  , "Point"
  , "ReactionGlyph"
  , "SpeciesGlyph"
  , "SpeciesReferenceGlyph"
  , "TextGlyph"
#endif  /* USE_LAYOUT */

};


/**
 * @return a human readable name for the given SBMLTypeCode_t.  The caller
 * does not own the returned string and is therefore not allowed to modify
 * it.
 */
LIBSBML_EXTERN
const char *
SBMLTypeCode_toString (SBMLTypeCode_t tc)
{
  SBMLTypeCode_t max = SBML_STOICHIOMETRY_MATH;

#ifdef USE_LAYOUT
  max = SBML_LAYOUT_TEXTGLYPH;
#endif  // USE_LAYOUT


  if (tc < SBML_COMPARTMENT || tc > max)
  {
    tc = SBML_UNKNOWN;
  }

  return SBML_TYPE_CODE_STRINGS[tc];
}

LIBSBML_CPP_NAMESPACE_END
