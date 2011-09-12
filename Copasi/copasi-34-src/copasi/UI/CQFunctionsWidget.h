// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CQFunctionsWidget.h,v $
//   $Revision: 1.4.2.1 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/05/13 21:47:04 $
// End CVS Header

// Copyright (C) 2011 - 2010 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

// Copyright (C) 2008 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., EML Research, gGmbH, University of Heidelberg,
// and The University of Manchester.
// All rights reserved.

#ifndef CQFunctionsWidget_h
#define CQFunctionsWidget_h

#include "CQSortFilterProxyModel.h"
#include "ui_CQFunctionsWidget.h"
#include "CQFunctionDM.h"

class CQFunctionsWidget : public CopasiWidget, public Ui::CQFunctionsWidget
{
  Q_OBJECT

public:
  CQFunctionsWidget(QWidget* parent = 0, const char* name = 0);
  ~CQFunctionsWidget();

  virtual bool update(ListViews::ObjectType objectType, ListViews::Action action, const std::string & key);
  virtual bool leave();

protected:
  virtual bool enterProtected();

private:
  CQFunctionDM* mpFunctionDM;
  CQSortFilterProxyModel *mpProxyModel;
  void deleteSelectedFunctions();
  void updateDeleteBtns();

protected:
  virtual void keyPressEvent(QKeyEvent* ev);

protected slots:

  virtual void slotBtnNewClicked();
  virtual void slotBtnDeleteClicked();
  virtual void slotBtnClearClicked();
  virtual void slotSelectionChanged(const QItemSelection& selected,
                                    const QItemSelection& deselected);
  virtual void slotDoubleClicked(const QModelIndex proxyIndex);
  virtual void dataChanged(const QModelIndex& topLeft,
                           const QModelIndex& bottomRight);
  virtual void slotFilterChanged();
};

#endif // CQFunctionsWidget_h
