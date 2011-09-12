// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/layoutUI/BezierCurve.h,v $
//   $Revision: 1.2.14.1 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/01/12 19:02:00 $
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

/*!
    \file BezierCurve.h
    \brief Header file of class BezierCurve
 */

#ifndef CBEZIERCURVE_H
#define CBEZIERCURVE_H

#include "copasi.h"

#include <vector>

#include "copasi/layout/CLBase.h"

class BezierCurve
{
public:
  BezierCurve();
  BezierCurve(size_t numberOfStepsOnCurve);
  std::vector<CLPoint> curvePts(const std::vector<CLPoint>& pts);

private:
  C_FLOAT64 t;
  size_t steps;
  C_FLOAT64 dt;

  C_FLOAT64 bernstein(C_INT32 i, C_INT32 n, C_FLOAT64 t);
  CLPoint bezierPt(C_FLOAT64 t, std::vector<CLPoint> pts);
  C_FLOAT64 multiplyFromTo(C_INT32 n1, C_INT32 n2);
  void init();
};
#endif
