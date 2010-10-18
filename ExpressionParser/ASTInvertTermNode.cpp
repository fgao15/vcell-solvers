#include "ASTInvertTermNode.h"
#include "DivideByZeroException.h"
#include "SymbolTable.h"
#include "Expression.h"
#include "ExpressionParserTreeConstants.h"

ASTInvertTermNode::ASTInvertTermNode() : SimpleNode(JJTINVERTTERMNODE) {
}

ASTInvertTermNode::ASTInvertTermNode(int i) : SimpleNode(i) {
}

ASTInvertTermNode::~ASTInvertTermNode() {
}

string ASTInvertTermNode::infixString(int lang, NameScope* nameScope)
{
	return jjtGetChild(0)->infixString(lang,nameScope); 
}

void ASTInvertTermNode::getStackElements(vector<StackElement>& elements) {
	jjtGetChild(0)->getStackElements(elements);
	elements.push_back(StackElement(TYPE_DIV));
}


double ASTInvertTermNode::evaluate(int evalType, double* values) {
	double childValue = jjtGetChild(0)->evaluate(evalType, values);
	if (childValue == 0.0) {
		//string childString = infixString(LANGUAGE_DEFAULT, 0);
		//throw DivideByZeroException("divide by zero '" + childString + "'");
		//
		// DIVIDE BY ZERO !!!!!
		//
		// form error message for user's consumption.
		//
		string errorMsg = getFunctionDomainError("divide by zero", 0, "divisor", jjtGetChild(0));
        throw DivideByZeroException(errorMsg);
	} else {
		return (1.0 / childValue);
	}
}

Node* ASTInvertTermNode::copyTree() {
	ASTInvertTermNode* node = new ASTInvertTermNode();
	for (int i=0;i<jjtGetNumChildren();i++){
		node->jjtAddChild(jjtGetChild(i)->copyTree());
	}
	return node;	
}