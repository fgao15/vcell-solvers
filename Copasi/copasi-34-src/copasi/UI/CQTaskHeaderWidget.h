// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CQTaskHeaderWidget.h,v $
//   $Revision: 1.10.2.3 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/05/13 21:46:50 $
// End CVS Header

// Copyright (C) 2011 - 2010 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

#ifndef COPASI_CQTaskHeaderWidget
#define COPASI_CQTaskHeaderWidget

#include <qvariant.h>

#include "copasi/UI/ui_CQTaskHeaderWidget.h"

class CQTaskHeaderWidget: public QWidget, public Ui::CQTaskHeaderWidget
{
  Q_OBJECT

public:
  CQTaskHeaderWidget(QWidget* parent = 0, Qt::WindowFlags f = 0);

  virtual ~CQTaskHeaderWidget();

  bool setTaskName(const std::string & name);
  void saved();

protected slots:


  void slotUpdate();
  void slotExecutable();

protected:
  bool mExecutableChanged;
  bool mUpdateChanged;
  QColor mSavedColor;
  QColor mChangedColor;
};

#endif // CQTASKHEADERWIDGET_H
