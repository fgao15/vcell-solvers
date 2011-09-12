// Begin CVS Header
//   $Source: /fs/turing/cvs/copasi_dev/copasi/function/CEvaluationNodeVariable.cpp,v $
//   $Revision: 1.14.4.1 $
//   $Name: Build-33 $
//   $Author: shoops $
//   $Date: 2011/01/12 19:00:59 $
// End CVS Header

// Copyright (C) 2010 by Pedro Mendes, Virginia Tech Intellectual
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

#include "copasi.h"
#include "CEvaluationNode.h"
#include "CEvaluationTree.h"

#include "sbml/math/ASTNode.h"

CEvaluationNodeVariable::CEvaluationNodeVariable():
    CEvaluationNode(CEvaluationNode::INVALID, ""),
    mpTree(NULL),
    mIndex(C_INVALID_INDEX)
{mPrecedence = PRECEDENCE_NUMBER;}

CEvaluationNodeVariable::CEvaluationNodeVariable(const SubType & subType,
    const Data & data):
    CEvaluationNode((Type)(CEvaluationNode::VARIABLE | subType), data),
    mpTree(NULL),
    mIndex(C_INVALID_INDEX)
{mPrecedence = PRECEDENCE_NUMBER;}

CEvaluationNodeVariable::CEvaluationNodeVariable(const CEvaluationNodeVariable & src):
    CEvaluationNode(src),
    mpTree(src.mpTree),
    mIndex(src.mIndex)
{}

CEvaluationNodeVariable::~CEvaluationNodeVariable() {}

bool CEvaluationNodeVariable::compile(const CEvaluationTree * pTree)
{
  mpTree = pTree;

  if (!pTree) return false;

  mIndex = pTree->getVariableIndex(mData);

  if (mIndex == C_INVALID_INDEX) return false;

  return (getChild() == NULL); // We must not have any children.
}

const C_FLOAT64 & CEvaluationNodeVariable::value() const
{return *const_cast<C_FLOAT64 *>(&mValue) = mpTree->getVariableValue(mIndex);}

size_t CEvaluationNodeVariable::getIndex() const
{return mIndex;}

ASTNode* CEvaluationNodeVariable::toAST(const CCopasiDataModel* /*pDataModel*/) const
{
  ASTNode* node = new ASTNode();
  node->setType(AST_NAME);
  node->setName(this->getData().c_str());
  return node;
}

#include "utilities/copasimathml.h"

void CEvaluationNodeVariable::writeMathML(std::ostream & out,
    const std::vector<std::vector<std::string> > & env,
    bool /* expand */,
    size_t l) const
{
  if (mIndex < env.size())
    {
      out << SPC(l) << env[mIndex][0] << std::endl;
    }
  else
    {
      out << SPC(l) << "<mi>" << this->mData << "</mi>" << std::endl;
    }
}
