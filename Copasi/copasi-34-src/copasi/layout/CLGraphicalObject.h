// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/layout/CLGraphicalObject.h,v $
//   $Revision: 1.9.2.1 $
//   $Name: Build-33 $
//   $Author: gauges $
//   $Date: 2011/02/27 17:49:57 $
// End CVS Header

// Copyright (C) 2011 - 2010 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

// Copyright (C) 2008 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., EML Research, gGmbH, University of Heidelberg,
// and The University of Manchester.
// All rights reserved.

// Copyright (C) 2001 - 2007 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc. and EML Research, gGmbH.
// All rights reserved.

#ifndef CLGO_H_
#define CLGO_H_

#include <string>
#include "report/CCopasiContainer.h"

#include "CLBase.h"

#ifdef Darwin
LIBSBML_CPP_NAMESPACE_BEGIN
class GraphicalObject;
LIBSBML_CPP_NAMESPACE_END
#endif

/**
 * This is the base class for the layout objects in copasi.
 * It is a CCopasiObject. It also has a key (which is used if one
 * layout object refers to another one)
 * It provides the mechanism for refering to a copasi model
 * object by key. This needs to be specialized in the derived
 * classes
 */
class CLGraphicalObject : public CLBase, public CCopasiContainer
{
private:

  /**
   *  The key of the layout object itself
   */
  std::string mKey;

  /**
   *  The key of an object of the copasi model. This is not used
   *  in this base class. It is provided as a service for the
   *  derived classes
   */
  std::string mModelObjectKey;

#ifdef USE_CRENDER_EXTENSION
  // attribute to store the object role
  std::string mObjectRole;
#endif // USE_CRENDER_EXTENSION
protected:

  CLBoundingBox mBBox;

public:

  CLGraphicalObject(const std::string & name = "GraphicalObject",
                    const CCopasiContainer * pParent = NULL);

  CLGraphicalObject(const CLGraphicalObject & src,
                    const CCopasiContainer * pParent = NULL);

  /**
   * constructor from libsbml object
   */
  CLGraphicalObject(const GraphicalObject & sbml,
                    std::map<std::string, std::string> & layoutmap,
                    const CCopasiContainer * pParent = NULL);

  ~CLGraphicalObject();

  /**
   * The assignment operator does not copy the key.
   */
  CLGraphicalObject & operator= (const CLGraphicalObject & rhs);

  /**
   *  Retrieves the key of the layout object
   */
  virtual const std::string & getKey() const
  {return mKey;};

  const CLBoundingBox & getBoundingBox() const {return mBBox;};
  CLBoundingBox & getBoundingBox() {return mBBox;};
  void setBoundingBox(const CLBoundingBox & bb) {mBBox = bb;};

  const CLPoint & getPosition() const {return mBBox.getPosition();};
  void setPosition(const CLPoint & p) {mBBox.setPosition(p);};

  const C_FLOAT64 & getX() const {return mBBox.getPosition().getX();};
  void setX(const C_FLOAT64 & x) {mBBox.getPosition().setX(x);};

  const C_FLOAT64 & getY() const {return mBBox.getPosition().getY();};
  void setY(const C_FLOAT64 & y) {mBBox.getPosition().setY(y);};

  const CLDimensions & getDimensions() const {return mBBox.getDimensions();};
  void setDimensions(const CLDimensions & d) {mBBox.setDimensions(d);};

  const C_FLOAT64 & getWidth() const {return mBBox.getDimensions().getWidth();};
  void setWidth(const C_FLOAT64 & w) {mBBox.getDimensions().setWidth(w);};

  const C_FLOAT64 & getHeight() const {return mBBox.getDimensions().getHeight();};
  void setHeight(const C_FLOAT64 & h) {mBBox.getDimensions().setHeight(h);};

  const std::string & getModelObjectKey() const {return mModelObjectKey;};

  void setModelObjectKey(const std::string & k) {mModelObjectKey = k;};

  CCopasiObject * getModelObject() const;

  /**
    * if the graphical object refers to a model object this method will return the
    * name of that object.
    */
  std::string getModelObjectName() const;

  /**
    * if the graphical object refers to a model object this method will return the
    * display name of that object.
    */
  std::string getModelObjectDisplayName(bool regular = true, bool richtext = false) const;

  /**
   * This method writes the information of the copasi layout object into the
   * corresponding sbml object
   */
  virtual void exportToSBML(GraphicalObject * sbmlobject,
                            const std::map<const CCopasiObject*, SBase*> & copasimodelmap,
                            std::map<std::string, const SBase*>& sbmlIDs) const;

#ifdef USE_CRENDER_EXTENSION
  /**
   * Method to set the role of a graphical object.
   */
  void setObjectRole(const std::string& role);

  /**
   * Method to read the object role of an object.
   */
  const std::string& getObjectRole() const;

#endif // USE_CRENDER_EXTENSION

  /**
    * insert operator
    */
  friend std::ostream & operator<<(std::ostream &os, const CLGraphicalObject & g);
  void print(std::ostream * ostream) const;
};

#endif
