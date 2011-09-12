// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CScanWidgetRepeat.h,v $
//   $Revision: 1.6.4.1 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/05/13 21:46:53 $
// End CVS Header

// Copyright (C) 2011 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

// Copyright (C) 2008 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., EML Research, gGmbH, University of Heidelberg,
// and The University of Manchester.
// All rights reserved.

#ifndef CSCANWIDGETREPEAT_H
#define CSCANWIDGETREPEAT_H

#include "ui_CScanWidgetRepeat.h"

#include "utilities/CCopasiParameterGroup.h"
#include "scan/CScanProblem.h"

class CScanWidgetRepeat : public QWidget, public Ui::CScanWidgetRepeat
{
  Q_OBJECT

public:
  CScanWidgetRepeat(QWidget* parent = 0, const char* name = 0, Qt::WindowFlags fl = 0);
  ~CScanWidgetRepeat();

  virtual bool initFromScanItem(CCopasiParameterGroup * pg);
  virtual bool saveToScanItem(CScanProblem * pg) const;

protected slots:


private:
  void init();
};

#endif // CSCANWIDGETREPEAT_H
