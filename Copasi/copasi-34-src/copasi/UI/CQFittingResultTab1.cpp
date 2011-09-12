// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/UI/CQFittingResultTab1.cpp,v $
//   $Revision: 1.6.2.1 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/05/13 21:46:50 $
// End CVS Header

// Copyright (C) 2011 - 2010 by Pedro Mendes, Virginia Tech Intellectual
// Properties, Inc., University of Heidelberg, and The University
// of Manchester.
// All rights reserved.

#include "CQFittingResultTab1.h"
#include "copasi.h"

#include "parameterFitting/CFitProblem.h"
#include "parameterFitting/CFitItem.h"
#include "parameterFitting/CExperimentSet.h"
#include "parameterFitting/CExperiment.h"

#include "UI/qtUtilities.h"

/*
 *  Constructs a CQFittingResultTab1 which is a child of 'parent', with the
 *  name 'name'.'
 */
CQFittingResultTab1::CQFittingResultTab1(QWidget* parent, const char* name, Qt::WindowFlags fl)
    : QWidget(parent, name, fl)
{
  setupUi(this);

  init();
}

/*
 *  Destroys the object and frees any allocated resources
 */
CQFittingResultTab1::~CQFittingResultTab1()
{
  // no need to delete child widgets, Qt does it all for us
}

void CQFittingResultTab1::load(const CFitProblem * pProblem)
{
  mpEditObjectiveValue->setText(QString::number(pProblem->getSolutionValue()));
  mpEditRMS->setText(QString::number(pProblem->getRMS()));
  mpEditStdDeviation->setText(QString::number(pProblem->getStdDeviation()));


#ifndef COPASI_CROSSVALIDATION
  mpLblCVObjectiveValue->hide();
  mpEditCVObjectiveValue->hide();
  mpLblCVRMS->hide();
  mpEditCVRMS->hide();
  mpLblCVStdDeviation->hide();
  mpEditCVStdDeviation->hide();
#endif // not COPASI_CROSSVALIDATION

  const unsigned C_INT32 & FunctionEvaluations = pProblem->getFunctionEvaluations();
  mpEditEvaluations->setText(QString::number(FunctionEvaluations));
  const C_FLOAT64 & ExecutionTime = pProblem->getExecutionTime();
  mpEditCPUTime->setText(QString::number(ExecutionTime));
  mpEditSpeed->setText(QString::number(FunctionEvaluations / ExecutionTime));
}

void CQFittingResultTab1::init()
{}
