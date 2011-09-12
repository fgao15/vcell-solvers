// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CQMatrixDialog.h,v $
//   $Revision: 1.6.2.3 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/05/13 21:46:55 $
// End CVS Header

// Copyright (C) 2011 - 2010 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

#ifndef CQMATRIXDIALOG_H
#define CQMATRIXDIALOG_H

#include <qvariant.h>
#include "ui_CQMatrixDialog.h"

class CArrayAnnotation;

class CQMatrixDialog : public QDialog, public Ui::CQMatrixDialog
{
  Q_OBJECT

public:
  CQMatrixDialog(QWidget* parent = 0, const char* name = 0, bool modal = false, Qt::WindowFlags fl = 0);
  ~CQMatrixDialog();

public slots:
  virtual void setArray(const CArrayAnnotation * tmp, bool single);

protected slots:


};

#endif // CQMATRIXDIALOG_H
