// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CQEFMWidget.cpp,v $
//   $Revision: 1.10.2.2 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/05/13 21:47:03 $
// End CVS Header

// Copyright (C) 2011 - 2010 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

// Copyright (C) 2008 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., EML Research, gGmbH, University of Heidelberg,
// and The University of Manchester.
// All rights reserved.

#include "CQEFMWidget.h"

#include "CQTaskBtnWidget.h"
#include "CQTaskHeaderWidget.h"
#include "CProgressBar.h"
#include "qtUtilities.h"
#include "CQMessageBox.h"
#include "CQEFMResultWidget.h"

#include "copasi.h"

#include "elementaryFluxModes/CEFMMethod.h"
#include "elementaryFluxModes/CEFMTask.h"

/*
 *  Constructs a CQEFMWidget which is a child of 'parent', with the
 *  name 'name'.'
 */
CQEFMWidget::CQEFMWidget(QWidget* parent, const char* name)
    : TaskWidget(parent, name)
{
  setupUi(this);

  mpHeaderWidget->setTaskName("Elementary Flux Modes");
  mpHeaderWidget->mpUpdateModel->hide();

  verticalLayout->insertWidget(0, mpHeaderWidget);
  verticalLayout->addWidget(mpBtnWidget);
}

/*
 *  Destroys the object and frees any allocated resources
 */
CQEFMWidget::~CQEFMWidget()
{}

bool CQEFMWidget::runTask()
{
  if (dynamic_cast< CEFMTask * >(mpTask) == NULL)
    return false;

  if (!commonBeforeRunTask()) return false;

  return commonRunTask();
}

bool CQEFMWidget::taskFinishedEvent()
{
  bool success = true;

  // We need to load the result here as this is the only place where
  // we know that it is correct.
  CQEFMResultWidget * pResult =
    dynamic_cast< CQEFMResultWidget * >(CopasiWidget::mpListView->findWidgetFromId(2211));

  if (pResult == NULL)
    return false;

  success &= pResult->loadResult(mpTask);

  if (success && isShown())
    CopasiWidget::mpListView->switchToOtherWidget(2211, ""); //change to the results window

  return success;
}

bool CQEFMWidget::saveTask()
{
  CEFMTask * pTask =
    dynamic_cast< CEFMTask * >(mpTask);

  if (!pTask) return false;

  saveCommon();
  saveMethod();

  return true;
}

bool CQEFMWidget::loadTask()
{
  CEFMTask * pTask =
    dynamic_cast< CEFMTask * >(mpTask);

  if (!pTask) return false;

  loadCommon();
  loadMethod();

  return true;
}

CCopasiMethod * CQEFMWidget::createMethod(const CCopasiMethod::SubType & type)
{
  mpTask->setMethodType(type);
  return mpTask->getMethod();
}
