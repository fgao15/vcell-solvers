// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CQGlobalQuantitiesWidget.h,v $
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

#ifndef CQGlobalQuantitiesWidget_h
#define CQGlobalQuantitiesWidget_h

#include "CQComboDelegate.h"
#include "CQSortFilterProxyModel.h"
#include "ui_CQGlobalQuantitiesWidget.h"
#include "CQGlobalQuantityDM.h"

class CQGlobalQuantitiesWidget : public CopasiWidget, public Ui::CQGlobalQuantitiesWidget
{
  Q_OBJECT

public:
  CQGlobalQuantitiesWidget(QWidget* parent = 0, const char* name = 0);
  ~CQGlobalQuantitiesWidget();

  virtual bool update(ListViews::ObjectType objectType, ListViews::Action action, const std::string & key);
  virtual bool leave();

protected:
  virtual bool enterProtected();

private:
  CQGlobalQuantityDM* mpGlobalQuantityDM;
  CQSortFilterProxyModel *mpProxyModel;
  CQIndexComboDelegate* mpTypeDelegate;
  void deleteSelectedGlobalQuantities();
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

#endif // CQGlobalQuantitiesWidget_h
