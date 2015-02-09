#include "ExpressionException.h"

ExpressionException::~ExpressionException(void)
{
}

ExpressionException::ExpressionException(string msg) : Exception("ExpressionException", msg)
{	
}

ExpressionException::ExpressionException(string title, string msg) : Exception(title, msg)
{	
}
