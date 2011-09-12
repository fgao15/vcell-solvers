/* Begin CVS Header
 $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CQLyapResultWidget.h,v $
 $Revision: 1.7.2.1 $
 $Name: Build-33 $
 $Author: shoops $
 $Date: 2011/05/13 21:46:58 $
 End CVS Header */

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

#ifndef CQLYAPRESULT_H
#define CQLYAPRESULT_H

#include "ui_CQLyapResultWidget.h"

#include "lyap/CLyapTask.h"

class CQLyapResultWidget : public CopasiWidget, public Ui::CQLyapResultWidget
{
  Q_OBJECT

public:
  CQLyapResultWidget(QWidget* parent = 0, const char* name = 0, Qt::WFlags fl = 0);
  ~CQLyapResultWidget();

  virtual bool update(ListViews::ObjectType objectType, ListViews::Action action, const std::string & key);
  virtual bool leave();

protected slots:


  void saveToFile();

protected:
  virtual bool enterProtected();
  bool loadFromBackend();

private:
  void init();

  CLyapTask * mpTask;
};

#endif
