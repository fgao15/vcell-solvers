// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CQExperimentSelection.h,v $
//   $Revision: 1.7.2.1 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/05/13 21:46:57 $
// End CVS Header

// Copyright (C) 2011 - 2010 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

#ifndef CQEXPERIMENTSELECTION_H
#define CQEXPERIMENTSELECTION_H

#include <QVariant>
#include <QDialog>

#include "ui_CQExperimentSelection.h"

class QComboBox;
class CExperimentSet;

class CQExperimentSelection : public QDialog, public Ui::CQExperimentSelection
{
  Q_OBJECT

public:
  CQExperimentSelection(QWidget* parent = 0, const char* name = 0, bool modal = false, Qt::WindowFlags fl = 0);
  ~CQExperimentSelection();

  virtual void load(QComboBox * pBox, const CExperimentSet * pExperimentSet);

protected:
  QComboBox * mpBox;

protected slots:


  void slotBtnOK();
  void slotBtnCancel();
  void slotBtnAll();
  void slotBtnNone();


private:
  void init();

};

#endif // CQEXPERIMENTSELECTION_H
