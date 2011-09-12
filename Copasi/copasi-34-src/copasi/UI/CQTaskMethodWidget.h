// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CQTaskMethodWidget.h,v $
//   $Revision: 1.1.2.2 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/05/13 21:46:55 $
// End CVS Header

// Copyright (C) 2011 - 2010 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

#ifndef COPASI_CQTaskMethodWidget
#define COPASI_CQTaskMethodWidget

#include <qvariant.h>

#include "copasi/UI/ui_CQTaskMethodWidget.h"

class CCopasiTask;
class CCopasiMethod;

class CQTaskMethodWidget: public QWidget, public Ui::CQTaskMethodWidget
{
  Q_OBJECT

public:
  CQTaskMethodWidget(QWidget* parent = 0, Qt::WindowFlags f = 0);

  virtual ~CQTaskMethodWidget();

  void setTask(CCopasiTask * pTask);

  void setValidMethods(const unsigned int * validMehtods);

  void enableMethodParameter(const bool & enable);

  bool loadMethod();

  bool saveMethod();


protected slots:


  void changeMethod(int);

protected:
  CCopasiTask * mpTask;
  CCopasiMethod * mpMethod;
};

#endif // COPASI_CQTaskMethodWidget
