#ifndef Hdf5OutputWriter_h
#define Hdf5OutputWriter_h

#include <MovingBoundaryTypes.h>
#include <World.h>
#include <vector>
#include <string>
#include <ReportClient.h>
#include <H5Cpp.h>
using std::vector;
using std::string;

using moving_boundary::World ;
using moving_boundary::CoordinateType;
using moving_boundary::Volume2DClass;

struct Hdf5OutputWriter :public moving_boundary::ReportClient
{
	typedef World<CoordinateType,2> WorldType;
	/**
	* HDF5 spatial chunk size (x and y dimensions)
	*/
	static const size_t spatialChunkSize = 10;
	/**
	* HDF5 spatial chunk size (time dimension)
	*/
	static const size_t timeChunkSize = 50;

	/**
	* worldDim, speciesDim index
	*/
	static const size_t timeArrayIndex = 0;

	/**
	* worldDim, speciesDim index
	*/
	static const size_t xArrayIndex = 1;

	/**
	* worldDim, speciesDim index
	*/
	static const size_t yArrayIndex = 2;

	/**
	* speciesDim index
	*/
	static const size_t speciesIndex = 3;

	static constexpr const char* H5_FILE_EXT = ".h5";
	static constexpr const char* LOG_FILE_EXT = ".log";
	static constexpr const char* MBSDATA_IDENTIFIER = "MBSData";
	static constexpr const char* DataSet_Times = "/Times";
	static constexpr const char* Group_Solution = "/Solution";
	static constexpr const char* Group_Mesh = "/Mesh";


	/**
	* @param f file to write to
	* @param mbpp the problem
	* @param baseName name of dataset in HDF5 file if not default
	*/
	Hdf5OutputWriter(std::string& a_xml, std::string& baseFileName, int steps, double interval, WorldType & world_, const moving_boundary::MovingBoundaryParabolicProblem &mbpp);
	~Hdf5OutputWriter();

	virtual void time(double t, unsigned int generationCounter, bool last, const moving_boundary::GeometryInfo<moving_boundary::CoordinateType> & geometryInfo);

	/**
	* state of inside / boundary nodes
	*/
	virtual void element(const moving_boundary::MeshElementNode &e);
	/**
	* notify client they've received all elements
	*/
	virtual void iterationComplete( );

	void simulationComplete( );

	std::string getXML() const
	{
		return xml;
	}

	virtual std::string outputName( ) const {
		return h5FileName;
	}

private:
	bool shouldReport();
	void init();
	void writeLog();
	void writeSolution();
	void initTimesDataSet();
	void initSolutionGroup();
	void initMeshGroup();

	const moving_boundary::MovingBoundaryParabolicProblem &theProblem;
	const WorldType & world;

	/**
	* XML used to create
	*/
	double* solution;
	unsigned int solutionSize;
	unsigned int numSpecies;
	unsigned int numElements;
	std::string xml;
	std::string h5FileName;
	H5::H5File h5File;
	H5::DataSet timesDataSet;
	H5::Group solutionGroup;
	H5::Group meshGroup;
	std::string logFileName;
	double currentTime;
	int currentIter;
	bool bLastIter;
	unsigned long lastReportIteration;
	unsigned int outputNumSteps;
	double outputTimeStep;
	vector<double> timeList;
	H5::DataSet solutionDataSet;

	WorldType::PointConverter pointconverter;
};

#endif
