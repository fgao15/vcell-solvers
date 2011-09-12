// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CQProgressItemText.cpp,v $
//   $Revision: 1.5.4.1 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/05/13 21:46:50 $
// End CVS Header

// Copyright (C) 2011 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

// Copyright (C) 2008 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., EML Research, gGmbH, University of Heidelberg,
// and The University of Manchester.
// All rights reserved.

#include "CQProgressItemText.h"

#include <qvariant.h>
#include "CQProgressItem.h"
#include "CQProgressItemText.ui.h"
/*
 *  Constructs a CQProgressItemText which is a child of 'parent', with the
 *  name 'name'.'
 */
CQProgressItemText::CQProgressItemText(QWidget* parent, const char* name)
    : CQProgressItem(parent, name)
{
  Ui::CQProgressItemText::setupUi(this);
}

/*
 *  Destroys the object and frees any allocated resources
 */
CQProgressItemText::~CQProgressItemText()
{
  // no need to delete child widgets, Qt does it all for us
}

