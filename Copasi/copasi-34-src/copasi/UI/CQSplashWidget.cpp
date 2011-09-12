// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CQSplashWidget.cpp,v $
//   $Revision: 1.6.2.3 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/05/13 21:47:00 $
// End CVS Header

// Copyright (C) 2011 - 2010 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

#include "CQSplashWidget.h"

#include <qvariant.h>
#include "qtUtilities.h"
#include "AboutDialog.h"

#include "utilities/CVersion.h"
#include "report/CCopasiRootContainer.h"

/*
 *  Constructs a CQSplashWidget which is a child of 'parent', with the
 *  name 'name'.'
 */
CQSplashWidget::CQSplashWidget(QWidget* parent, const char* name)
    : CopasiWidget(parent, name)
{
  setupUi(this);

  mpPixmap->setObjectName(QString::fromUtf8("mpPixmap"));
  mpPixmap->setPixmap(QPixmap((const char**)image0_data));

  init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
CQSplashWidget::~CQSplashWidget()
{
  // no need to delete child widgets, Qt does it all for us
}

void CQSplashWidget::init()
{
  mpLblVersion->setText(mpLblVersion->text().arg(FROM_UTF8(CVersion::VERSION.getVersion())));

  return;
}

void CQSplashWidget::slotViewLicense()
{
  QString FixedTitle = "COPASI ";
  FixedTitle += FROM_UTF8(CVersion::VERSION.getVersion());

  AboutDialog* aboutDialog = new AboutDialog(this, CCopasiRootContainer::getLicenseHTML(), 76, 30);
  aboutDialog->setCaption(FixedTitle);
  aboutDialog->exec();
}

