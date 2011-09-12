// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CQTextDialog.cpp,v $
//   $Revision: 1.3.4.1 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/05/13 21:46:54 $
// End CVS Header

// Copyright (C) 2011 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

// Copyright (C) 2008 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., EML Research, gGmbH, University of Heidelberg,
// and The University of Manchester.
// All rights reserved.

#include "CQTextDialog.h"

#include <qvariant.h>
#include "CQTextDialog.ui.h"
/*
 *  Constructs a CQTextDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  true to construct a modal dialog.
 */
CQTextDialog::CQTextDialog(QWidget* parent, const char* name, bool modal, Qt::WindowFlags fl)
    : QDialog(parent, name, modal, fl)
{
  setupUi(this);
}

/*
 *  Destroys the object and frees any allocated resources
 */
CQTextDialog::~CQTextDialog()
{
  // no need to delete child widgets, Qt does it all for us
}

