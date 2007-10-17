/**
 * @cond doxygen-libsbml-internal
 *
 * @file    ConsistencyValidator.h
 * @brief   Performs consistency checks on an SBML model
 * @author  Ben Bornstein
 *
 * $Id: ConsistencyValidator.h,v 1.6 2007/06/04 20:08:33 mhucka Exp $
 * $Source: /cvsroot/sbml/libsbml/src/validator/ConsistencyValidator.h,v $
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

#ifndef ConsistencyValidator_h
#define ConsistencyValidator_h


#ifdef __cplusplus


#include <sbml/validator/Validator.h>
#include <sbml/SBMLError.h>


class ConsistencyValidator: public Validator
{
public:

  ConsistencyValidator () : Validator( SBMLError::SBMLConsistency ) { }

  virtual ~ConsistencyValidator () { }

  /**
   * Initializes this Validator with a set of Constraints.
   */
  virtual void init ();
};


#endif  /* __cplusplus */
#endif  /* ConsistencyValidator_h */


/** @endcond doxygen-libsbml-internal */
