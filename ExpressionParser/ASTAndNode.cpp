#include "ASTAndNode.h"
#include "ExpressionException.h"
#include "ExpressionParserTreeConstants.h"

ASTAndNode::ASTAndNode() : SimpleNode(JJTANDNODE) {
}

ASTAndNode::ASTAndNode(int i) : SimpleNode(i) {
}

ASTAndNode::~ASTAndNode() {
}

bool ASTAndNode::isBoolean() {
	return true;
}

string ASTAndNode::infixString(int lang, NameScope* nameScope)
{
	string buffer("(");

	for (int i=0;i<jjtGetNumChildren();i++){
		if (i>0) 
			buffer += " && ";
		buffer += jjtGetChild(i)->infixString(lang, nameScope);
	}
	buffer += ")";

	return buffer;
}

void ASTAndNode::getStackElements(vector<StackElement>& elements) {
	for (int i=0;i<jjtGetNumChildren();i++){
		jjtGetChild(i)->getStackElements(elements);;
		if (i>0) 
			elements.push_back(StackElement(TYPE_AND));
	}
}

double ASTAndNode::evaluate(int evalType, double* values) {
	double sum = 1;
	ExpressionException* savedException = null;
	for (int i = 0; i < jjtGetNumChildren(); i++) {
		try {
			if (jjtGetChild(i)->evaluate(evalType, values) == 0) {
				return 0;
			}
		} catch(ExpressionException& ex){
			if (evalType == EVALUATE_VECTOR) {
				throw ex;
			}
			savedException = new ExpressionException(ex.getMessage());
		}
	}

	if (savedException != null){
		throw (*savedException);
	}else{
		return sum;
	}
}

Node* ASTAndNode::copyTree() {
	ASTAndNode* node = new ASTAndNode();
	for (int i=0;i<jjtGetNumChildren();i++){
		node->jjtAddChild(jjtGetChild(i)->copyTree());
	}
	return node;	
}
