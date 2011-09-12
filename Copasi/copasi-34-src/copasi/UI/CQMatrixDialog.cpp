// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CQMatrixDialog.cpp,v $
//   $Revision: 1.4.2.4 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/05/13 21:46:56 $
// End CVS Header

// Copyright (C) 2011 - 2010 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

#include "CQMatrixDialog.h"

#include <qvariant.h>
#include "utilities/CAnnotatedMatrix.h"
#include "qtUtilities.h"

/*
 *  Constructs a CQMatrixDialog as a child of 'parent', with the
 *  name 'name' and widget flags set to 'f'.
 *
 *  The dialog will by default be modeless, unless you set 'modal' to
 *  true to construct a modal dialog.
 */
CQMatrixDialog::CQMatrixDialog(QWidget* parent, const char* name, bool modal, Qt::WindowFlags fl)
    : QDialog(parent, name, modal, fl)
{
  setupUi(this);

}

/*
 *  Destroys the object and frees any allocated resources
 */
CQMatrixDialog::~CQMatrixDialog()
{
  // no need to delete child widgets, Qt does it all for us
}

void CQMatrixDialog::setArray(const CArrayAnnotation *tmp, bool single)
{
  size_t i;

  mpLabelRow->setText("Rows : " + FROM_UTF8(tmp->getDimensionDescription(0)));
  size_t nRows = tmp->size()[0];

  if (!single)
    mpCBRow->insertItem("ALL");

  if (FROM_UTF8(tmp->getObjectName()).contains("Eigenvalues"))
    {
      for (i = 0; i < nRows; i++)
        mpCBRow->insertItem(QString::number(i + 1));
    }
  else
    {
      for (i = 0; i < nRows; i++)
        mpCBRow->insertItem(FROM_UTF8(tmp->getAnnotationsString(0, true)[i]));
    }

  mpLabelColumn->hide();
  mpCBColumn->hide();

  mpLabelDim3->hide();
  mpCBDim3->hide();

  if (tmp->dimensionality() > 1)
    {
      mpLabelColumn->show();
      mpCBColumn->show();

      mpLabelColumn->setText("Columns : " + FROM_UTF8(tmp->getDimensionDescription(1)));
      size_t nCols = tmp->size()[1];

      if (!single)
        mpCBColumn->insertItem("ALL");

      if (FROM_UTF8(tmp->getObjectName()).contains("Eigenvalues"))
        {
          mpCBColumn->insertItem("Real part");
          mpCBColumn->insertItem("Imaginary part");
        }
      else
        {
          for (i = 0; i < nCols; i++)
            mpCBColumn->insertItem(FROM_UTF8(tmp->getAnnotationsString(1, true)[i]));
        }

      if (tmp->dimensionality() == 3)
        {
          mpLabelDim3->show();
          mpCBDim3->show();

          mpLabelDim3->setText("Dimension : " + FROM_UTF8(tmp->getDimensionDescription(2)));
          size_t nDims = tmp->size()[2];

          if (!single)
            mpCBDim3->insertItem("ALL");

          for (i = 0; i < nDims; i++)
            mpCBDim3->insertItem(FROM_UTF8(tmp->getAnnotationsString(2, true)[i]));
        }
    }
}
