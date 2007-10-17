/**
 * @cond doxygen-libsbml-internal
 *
 * @file    L2v2CompatibilityValidator.h
 * @brief   Checks whether an SBML model can be converted from L2v2/3 to L2v1
 * @author  Sarah Keating
 *
 * $Id: L2v2CompatibilityValidator.h,v 1.4 2007/06/04 20:08:33 mhucka Exp $
 * $Source: /cvsroot/sbml/libsbml/src/validator/L2v2CompatibilityValidator.h,v $
 *
 *<!---------------------------------------------------------------------------
 * This file is part of libSBML.  Please visit http://sbml.org for more
 * information about SBML, and the latest version of libSBML.
 *
 * Copyright 2005-2007 California Institute of Technology.
 * Copyright 2002-2005 California Institute of Technology and
 *                     Japan Science and Technology Corporation.
 * 
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation.  A copy of the license agreement is provided
 * in the file named "LICENSE.txt" included with this software distribution and
 * also available online as http://sbml.org/software/libsbml/license.html
 *----------------------------------------------------------------------- -->*/

#ifndef L2v2CompatibilityValidator_h
#define L2v2CompatibilityValidator_h


#ifdef __cplusplus


#include <sbml/validator/Validator.h>


class L2v2CompatibilityValidator: public Validator
{
public:

  L2v2CompatibilityValidator () :
    Validator( SBMLError::SBMLL2v2Compatibility ) { }

  virtual ~L2v2CompatibilityValidator () { }

  /**
   * Initializes this Validator with a set of Constraints.
   */
  virtual void init ();
};


#endif  /* __cplusplus */
#endif  /* L2v2CompatibilityValidator_h */


/** @endcond doxygen-libsbml-internal */
