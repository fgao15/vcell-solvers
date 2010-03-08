/*
 * (C) Copyright University of Connecticut Health Center 2001.
 * All rights reserved.
 */
#include <fstream>
using std::ofstream;
using std::endl;

#include <VCELL/Variable.h>
#include <math.h>

Variable::Variable(long Asize, string& nameStr, bool pde)
{
	size = Asize;
	ASSERTION(size);
	old = new double[size];
	curr = new double[size];
	name = nameStr;
	bPde = pde;
	clear();
}

Variable::~Variable()
{
	delete[] old;
	delete[] curr;
}

void Variable::clear()
{
	memset(old, 0, size * sizeof(double));
	memset(curr, 0, size * sizeof(double));
}

void Variable::show(ofstream& fp)
{
	fp << name << endl;
	long k = 0;
	for (k=0;k<size;k++){
		fp << curr[k] << " ";
		if (k % 10 == 9) 
			fp << endl;
	}
	if (k%10 != 0) 
		fp << endl;
}

double Variable::getOld(long index)
{
	// 
	// if (doesn't exist, return 0.0)
	//
	if (index<0 || index>=size) return 0.0;
	   
	return *(old + index);
}

double Variable::getCurr(long index)
{
	// 
	// if (doesn't exist, return 0.0)
	//
	if (index<0 || index>=size) return 0.0;
	   
	return *(curr + index);
}

void Variable::setOld(long index, double value)
{
	ASSERTION(index>=0 && index<size);
	   
	*(old + index) = value;
}

void Variable::setCurr(long index, double value)
{
	ASSERTION(index>=0 && index<size);
	   
	*(curr + index) = value;
}

void Variable::update()
{
	memcpy(old, curr, sizeof(double)*size);
}

void Variable::revert()
{
	memcpy(curr, old, sizeof(double)*size);
}
