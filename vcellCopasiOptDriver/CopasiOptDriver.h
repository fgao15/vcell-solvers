#ifndef COPASIOPTDRIVER
#define COPASIOPTDRIVER

#include <string>
#include <vector>
#include <utilities/CCopasiMethod.h>
#include <model/CModel.h>
using namespace std;

struct OptSolverCallbacks;

class CopasiOptDriver
{
public:
	static CModelValue* getModelValue(CModel* model, string& paramName);
	static void run(string& optXML, string& resultSetXML, OptSolverCallbacks* optSolverCallbacks);
	static CCopasiMethod::SubType nameToTypeEnum(const string& nameStr, const char ** enumNames, const CCopasiMethod::SubType & enumDefault);
};
#endif
