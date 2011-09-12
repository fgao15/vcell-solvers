// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/layout/CLBase.cpp,v $
//   $Revision: 1.6 $
//   $Name: Build-33 $
//   $Author: gauges $
//   $Date: 2010/03/10 12:26:12 $
// End CVS Header

// Copyright (C) 2010 by Pedro Mendes, Virginia Tech Intellectual
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

#define USE_LAYOUT 1

#include <sbml/layout/BoundingBox.h>

#include "CLBase.h"

//sbml constructors

CLPoint::CLPoint(const Point& p) :
    mX(p.getXOffset())
    , mY(p.getYOffset())
#ifdef USE_CRENDER_EXTENSION
    , mZ(p.getZOffset())
#endif // USE_CRENDER_EXTENSION
{}

Point CLPoint::getSBMLPoint() const
{
#ifdef USE_CRENDER_EXTENSION
  Point p(mX, mY, mZ);
#else
  Point p(mX, mY);
#endif // USE_CRENDER_EXTENSION
  return p;
}

//***********************************************************

CLDimensions::CLDimensions(const Dimensions& d) :
    mWidth(d.getWidth())
    , mHeight(d.getHeight())
#ifdef USE_CRENDER_EXTENSION
    , mDepth(d.getDepth())
#endif // USE_CRENDER_EXTENSION
{}

Dimensions CLDimensions::getSBMLDimensions() const
{
  Dimensions d(mWidth
               , mHeight
#ifdef USE_CRENDER_EXTENSION
               , mDepth
#endif // USE_CRENDER_EXTENSION
              );
  return d;
}

//***********************************************************

CLBoundingBox::CLBoundingBox(const BoundingBox & bb)
    : mPosition(*bb.getPosition()),
    mDimensions(*bb.getDimensions())
{}

BoundingBox CLBoundingBox::getSBMLBoundingBox() const
{
  return BoundingBox("", mPosition.getX(), mPosition.getY(),
                     mDimensions.getWidth(), mDimensions.getHeight());
}

//***********************************************************

std::ostream & operator<<(std::ostream &os, const CLPoint & p)
{
  os << "(x=" << p.mX << ", y=" << p.mY << ")";
  return os;
}

std::ostream & operator<<(std::ostream &os, const CLDimensions & d)
{
  os << "(w=" << d.mWidth << ", h=" << d.mHeight << ")";
  return os;
}

std::ostream & operator<<(std::ostream &os, const CLBoundingBox & bb)
{
  os << "[" << bb.mPosition << bb.mDimensions << "]";
  return os;
}
