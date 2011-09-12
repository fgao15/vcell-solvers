// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/layout/CLGradientStop.cpp,v $
//   $Revision: 1.3 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2010/09/16 18:28:05 $
// End CVS Header

// Copyright (C) 2010 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

#include <sstream>
#include <assert.h>
#include <limits>

#include <sbml/layout/render/GradientStop.h>

#include "CLGradientStop.h"

#include <copasi/report/CCopasiRootContainer.h>
#include <copasi/report/CKeyFactory.h>

/**
 * Constructor.
 */
CLGradientStop::CLGradientStop(CCopasiContainer* pParent):
    CLBase(),
    CCopasiObject("GradientStop", pParent),
    mOffset(CLRelAbsVector(std::numeric_limits<double>::quiet_NaN(), std::numeric_limits<double>::quiet_NaN())),
    mStopColor("#00000000"),
    mKey("")
{
  this->mKey = CCopasiRootContainer::getKeyFactory()->add("GradientStop", this);
}

/**
 * Copy Constructor
 */
CLGradientStop::CLGradientStop(const CLGradientStop& source, CCopasiContainer* pParent):
    CLBase(source),
    CCopasiObject(source, pParent),
    mOffset(source.mOffset),
    mStopColor(source.mStopColor),
    mKey("")
{
  this->mKey = CCopasiRootContainer::getKeyFactory()->add("GradientStop", this);
}

/**
 * Copy Constructor
 */
CLGradientStop::CLGradientStop(const GradientStop& source, CCopasiContainer* pParent):
    CLBase(),
    CCopasiObject("GradientStop", pParent),
    mOffset(source.getOffset()),
    mStopColor(source.getStopColor()),
    mKey("")
{
  this->mKey = CCopasiRootContainer::getKeyFactory()->add("GradientStop", this);
}

/**
 * Virtual destructor to satify the linker.
 * Does nothing , is only in the source file to help the compiler
 * in determining where to put the vtable.
 */
CLGradientStop::~CLGradientStop()
{
}

/**
 * Returns the offset.
 */
const CLRelAbsVector& CLGradientStop::getOffset() const
{
  return this->mOffset;
}

/**
 * Sets the offset.
 */
void CLGradientStop::setOffset(double x, double y)
{
  this->mOffset = CLRelAbsVector(x, y);
}

/**
 * Sets the offset.
 */
void CLGradientStop::setOffset(const std::string& co)
{
  this->mOffset = CLRelAbsVector(co);
}

/**
 * Sets the offset.
 */
void CLGradientStop::setOffset(const CLRelAbsVector& co)
{
  this->mOffset = co;
}

/**
 * Returns the stop color id.
 */
const std::string& CLGradientStop::getStopColor() const
{
  return this->mStopColor;
}

/**
 * Sets the stop color key.
 */
void CLGradientStop::setStopColor(const std::string& key)
{
  this->mStopColor = key;
}

/**
 * Converts this object to the corresponding SBML object.
 */
GradientStop* CLGradientStop::toSBML(unsigned int level, unsigned int version) const
{
  GradientStop* pStop = new GradientStop(level, version);
  RelAbsVector* pV = this->mOffset.toSBML();
  pStop->setOffset(*pV);
  delete pV;
  pStop->setStopColor(this->mStopColor);
  return pStop;
}

/**
 * Returns the key of the color definition.
 */
const std::string& CLGradientStop::getKey() const
{
  return this->mKey;
}
