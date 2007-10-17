/**
 * @cond doxygen-libsbml-internal
 *
 * @file    UnitFormulaFormatter.h
 * @brief   Formats an AST formula tree as a unit definition
 * @author  Sarah Keating
 *
 * $Id: UnitFormulaFormatter.h,v 1.13 2007/06/08 12:39:55 sarahkeating Exp $
 * $Source: /cvsroot/sbml/libsbml/src/units/UnitFormulaFormatter.h,v $
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

#ifndef UnitFormulaFormatter_h
#define UnitFormulaFormatter_h


#include <sbml/common/extern.h>
#include <sbml/util/StringBuffer.h>

#include <sbml/UnitDefinition.h>
#include <sbml/Unit.h>
#include <sbml/Model.h>
#include <sbml/FunctionDefinition.h>
#include <sbml/Compartment.h>
#include <sbml/Species.h>
#include <sbml/Parameter.h>
#include <sbml/Reaction.h>
#include <sbml/KineticLaw.h>
#include <sbml/Event.h>

#include <sbml/math/ASTNode.h>

#include <sbml/units/Utils_UnitDefinition.h>

#ifdef __cplusplus

class   LIBSBML_EXTERN UnitFormulaFormatter
{
public:
  /** 
   * constructor
   */

  UnitFormulaFormatter(const Model *);


  /** 
   * destructor
   */
  ~UnitFormulaFormatter();



  /**
   * visits the ASTNode and returns the unitDefinition of the formula
   * this function is really a dispatcher to the other
   * getUnitdefinition functions
   */
  UnitDefinition * getUnitDefinition(const ASTNode * node, 
    unsigned int KL = 0, int ReactNo = -1);

  /** 
   * returns the unitDefinition for the ASTNode from a function
   */
  UnitDefinition * getUnitDefinitionFromFunction(const ASTNode *);

  /** 
   * returns the unitDefinition for the ASTNode from a times function
   */
  UnitDefinition * getUnitDefinitionFromTimes(const ASTNode *);

  /** 
   * returns the unitDefinition for the ASTNode from a divide function
   */
  UnitDefinition * getUnitDefinitionFromDivide(const ASTNode *);

  /** 
   * returns the unitDefinition for the ASTNode from a power function
   */
  UnitDefinition * getUnitDefinitionFromPower(const ASTNode *, 
                                                      unsigned int, int);

  /** 
   * returns the unitDefinition for the ASTNode from 
   * a piecewise function
   */
  UnitDefinition * getUnitDefinitionFromPiecewise(const ASTNode *);

  /** 
   * returns the unitDefinition for the ASTNode from a root function
   */
  UnitDefinition * getUnitDefinitionFromRoot(const ASTNode *);

  /** 
   * returns the unitDefinition for the ASTNode from 
   * a function returning dimensionless value
   */
  UnitDefinition * getUnitDefinitionFromDimensionlessReturnFunction(const ASTNode *);

  /** 
   * returns the unitDefinition for the ASTNode from 
   * a function returning value with same units as argument(s)
   */
  UnitDefinition * getUnitDefinitionFromArgUnitsReturnFunction(const ASTNode *);

  /** 
   * returns the unitDefinition for the ASTNode from 
   * a delay function
   */
  UnitDefinition * getUnitDefinitionFromDelay(const ASTNode * node);

  /** 
   * returns the unitDefinition for the ASTNode from anything else
   */
  UnitDefinition * getUnitDefinitionFromOther(const ASTNode *);

  /** 
    * returns the unitDefinition for the units of the compartment
    */
  UnitDefinition * getUnitDefinitionFromCompartment(const Compartment *);

 /** 
  * returns the unitDefinition for the units of the species
  */
  UnitDefinition * getUnitDefinitionFromSpecies(const Species *);

  /** 
    * returns the unitDefinition for the units of the parameter
    */
  UnitDefinition * getUnitDefinitionFromParameter(const Parameter *);

  /** 
    * returns the unitDefinition for the time units of the event
    */
  UnitDefinition * getUnitDefinitionFromEventTime(const Event * event);

  /** 
    * returns 1 if the math contains 
    * a parameter that has undeclared units 0 otherwise
    */
  unsigned int hasUndeclaredUnits(const ASTNode *);
  

  /** 
    * returns canIgnoreUndeclaredUnits value
    */
  unsigned int getCanIgnoreUndeclaredUnits();

  /**
   * returns the undeclaredUnits flag
   */
  unsigned int getUndeclaredUnits();

  /** 
   * resets the undeclaredUnits and canIgnoreUndeclaredUnits flags
   * since these will different for each math formula
   */
  void resetFlags();

private:
  const Model * model;
  unsigned int undeclaredUnits;
  unsigned int canIgnoreUndeclaredUnits;
  unsigned int mInKineticlaw;
  int mReactionNo;

};


#endif  /* !cplusplus */
#endif  /* UnitFormulaFormatter_h */


/** @endcond doxygen-libsbml-internal */
