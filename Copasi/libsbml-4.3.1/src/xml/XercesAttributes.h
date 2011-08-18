/**
 * @file    XercesAttributes.h
 * @brief   Creates new XMLAttributes from "raw" Xerces-C++ attributes.
 * @author  Ben Bornstein
 *
 * $Id: XercesAttributes.h 12780 2011-02-08 04:12:54Z mhucka $
 * $HeadURL: http://sbml.svn.sourceforge.net/svnroot/sbml/trunk/libsbml/src/xml/XercesAttributes.h $
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
 * in the file named "LICENSE.txt" included with this software distribution and
 * also available online as http://sbml.org/software/libsbml/license.html
 * ---------------------------------------------------------------------- -->*/

#ifndef XercesAttributes_h
#define XercesAttributes_h

#ifdef __cplusplus

#include <string>

#include <xercesc/sax2/Attributes.hpp>
#include <sbml/xml/XMLAttributes.h>

LIBSBML_CPP_NAMESPACE_BEGIN

/** @cond doxygen-libsbml-internal */

class XercesAttributes : public XMLAttributes
{
public:

  /**
   * Creates a new XMLAttributes set that wraps the given "raw" Xerces-C++
   * Attributes set.
   */
  XercesAttributes (const xercesc::Attributes& attrs,
		    const std::string elementName);


  /**
   * Destroys this XercesAttributes set.
   */
  virtual ~XercesAttributes ();
};

/** @endcond */

LIBSBML_CPP_NAMESPACE_END

#endif  /* __cplusplus */
#endif  /* XercesAttributes_h */