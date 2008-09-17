#ifndef VCELLCVODESOLVER_H
#define VCELLCVODESOLVER_H

#include "VCellSundialsSolver.h"

class VCellCVodeSolver : public VCellSundialsSolver {
public:
	VCellCVodeSolver();	
	~VCellCVodeSolver();

	void solve(double* paramValues=0, bool bPrintProgress=false, FILE* outputFile=0, void (*checkStopRequested)(double, long)=0);
	SymbolTable* getSymbolTable() { return rateSymbolTable;}	
	double RHS(double* allValues, int equationIndex);

protected:
	void readEquations(istream& inputstream);
	void initialize();

private:
	Expression** rateExpressions; 
	SymbolTable* rateSymbolTable;
	
	int RHS(realtype t, N_Vector y, N_Vector yp);
	static int RHS_callback(realtype t, N_Vector y, N_Vector r, void *fdata);
	/*
	Arguments 
		t		is the current value of the independent variable.
		y		is the current value of the dependent variable vector, y(t).
		ydot	is the output vector f(t; y).
		f_data	is a pointer to user data | the same as the f data parameter passed to CVodeSetFdata.
	Return value 
		A CVRhsFn should return 0 if successful, a positive value if a recoverable error occurred 
		(in which case cvode will attempt to correct), or a negative value if it failed unrecoverably 
		(in which case the integration is halted and CV RHSFUNC FAIL is returned).
	*/
	int RootFn(realtype t, N_Vector y, realtype *gout);
	static int RootFn_callback(realtype t, N_Vector y, realtype *gout, void *g_data);
	/**
	Arguments 
		t		is the current value of the independent variable.
		y		is the current value of the dependent variable vector, y(t).
		gout	is the output array, of length nrtfn, with components gi(t; y).
		g data	is a pointer to user data | the same as the g data parameter passed to CVodeRootInit.
	Return value 
		A CVRootFn should return 0 if successful or a non-zero value if an error occured (in which case 
		the integration is halted and CVode returns CV RTFUNC FAIL).
	*/

	void initCVode(double* paramValues);
	void cvodeSolve(bool bPrintProgress, FILE* outputFile, void (*checkStopRequested)(double, long));

	void throwCVodeErrorMessage(int returnCode);
	void checkCVodeFlag(int flag);

	void reInit(double t);
	bool fixInitialDiscontinuities(double* paramValues);

};

#endif
