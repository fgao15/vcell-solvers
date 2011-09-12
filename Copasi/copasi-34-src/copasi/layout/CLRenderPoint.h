// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/layout/CLRenderPoint.h,v $
//   $Revision: 1.3 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2010/09/16 18:28:06 $
// End CVS Header

// Copyright (C) 2010 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

#ifndef CLRenderPoint_H__
#define CLRenderPoint_H__

#include <copasi/layout/CLBase.h>
#include <copasi/layout/CLRelAbsVector.h>

class RenderPoint;

class CLRenderPoint : public CLBase
{
protected:

  CLRelAbsVector mXOffset;
  CLRelAbsVector mYOffset;
  CLRelAbsVector mZOffset;

public:
  /**
   * Creates a new point with x,y and z set to 0.0.
   */

  CLRenderPoint();

  /**
   * Copy constructor.
   */
  CLRenderPoint(const CLRenderPoint& orig);

  /**
   * Creates a new point with the given ccordinates.
   */

  CLRenderPoint(const CLRelAbsVector& x, const CLRelAbsVector& y, const CLRelAbsVector& z = CLRelAbsVector(0.0, 0.0));

  /**
   * Constructor to generate object from the corresponding SBML object.
   */
  CLRenderPoint(const RenderPoint& source);

  /**
   * Destructor.
   */

  virtual ~CLRenderPoint();

  /**
   * Assignment operator
   */
  CLRenderPoint& operator=(const CLRenderPoint& orig);

  /**
   * Comparison operator.
   */
  bool operator==(const CLRenderPoint& left);

  /**
   * Returns the x offset.
   */
  const CLRelAbsVector& x() const;

  /**
   * Returns the y offset.
   */
  const CLRelAbsVector& y() const;

  /**
   * Returns the z offset.
   */
  const CLRelAbsVector& z() const;

  /**
   * Returns the x offset.
   */
  const CLRelAbsVector& getXOffset() const;

  /**
   * Returns the y offset.
   */
  const CLRelAbsVector& getYOffset() const;

  /**
   * Returns the z offset.
   */
  const CLRelAbsVector& getZOffset() const;

  /**
   * Returns the x offset.
   */
  CLRelAbsVector& x();

  /**
   * Returns the y offset.
   */
  CLRelAbsVector& y();

  /**
   * Returns the z offset.
   */
  CLRelAbsVector& z();

  /**
   * Returns the x offset.
   */
  CLRelAbsVector& getXOffset();

  /**
   * Returns the y offset.
   */
  CLRelAbsVector& getYOffset();

  /**
   * Returns the z offset.
   */
  CLRelAbsVector& getZOffset();

  /**
   * Sets the x offset.
   */
  void setX(const CLRelAbsVector& x);

  /**
   * Sets the y offset.
   */
  void setY(const CLRelAbsVector& y);

  /**
   * Sets the z offset.
   */
  void setZ(const CLRelAbsVector& z);

  /**
   * Sets the x offset.
   */
  void setXOffset(const CLRelAbsVector& x);

  /**
   * Sets the y offset.
   */
  void setYOffset(const CLRelAbsVector& y);

  /**
   * Sets the z offset.
   */
  void setZOffset(const CLRelAbsVector& z);

  /**
   * Sets the coordinates to the given values.
   */
  void setOffsets(const CLRelAbsVector& x, const CLRelAbsVector& y, const CLRelAbsVector& z = CLRelAbsVector(0.0, 0.0));

  /**
   * Sets the Z offset to 0.0.
   */
  void initDefaults();

  /**
   * Converts this object to the corresponding SBML object.
   */
  virtual RenderPoint* toSBML(unsigned int level, unsigned int version) const;

  /**
   * Adds the attributes for a render point object to the passed in.
   * object.
   */
  virtual void addSBMLAttributes(RenderPoint* pPoint) const;
};

#endif  /* CLRenderPoint_H__ */
