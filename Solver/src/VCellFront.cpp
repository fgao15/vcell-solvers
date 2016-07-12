#pragma warning ( disable: 4996 )
#include <TPoint.h>
#include <VCellFront.h>
#include <Logger.h>
#include <VCellException.h>
#include <MBridge/FronTierAdapt.h>
using namespace spatial;
namespace {
	/**
	* type conversion without scaling
	* convert frontier output into point, truncating if necessary
	*/
	template <typename T>
	inline TPoint<T,2> convertFrontier(const double* in, const double* normal) {
		T c[2] = {static_cast<T>(in[0]), static_cast<T>(in[1])};
		return TPoint<T,2>(c, normal);
	}
}

template <typename FCT>
VCellFront<FCT>::VCellFront(std::vector<GeoLimit> & limits, int N, double tmax,
					   FronTierLevelFunction levelFunction,
					   FronTierVelocityFunction velocityFunction) 
					   :front( ),
					   f_basic( ),
					   level_func_pack( ),
					   velo_func_pack( ),
					   levelObj(0),
					   velObj(0)
{
	init(limits,N,tmax,levelFunction,velocityFunction, false);
}

template <typename FCT>
VCellFront<FCT>::VCellFront(std::vector<GeoLimit> & limits, int N, double tmax,
					   const FronTierLevel & level,
					   const FronTierVelocity &vel) 
					   :front( ),
					   f_basic( ),
					   level_func_pack( ),
					   velo_func_pack( ),
					   levelObj(&level),
					   velObj(&vel)
{
	init(limits,N,tmax,levelAdapter,velocityAdapter, true);
}

template <typename FCT>
void VCellFront<FCT>::init(std::vector<GeoLimit> & limits, int N, double tmax,
					  FronTierLevelFunction levelFunction,
					  FronTierVelocityFunction velocityFunction, 
					  bool isAdapter) {
						  domainLimits[0] = limits[0];
						  domainLimits[1] = limits[1];
						  const size_t dim = limits.size( );

						  f_basic.dim = static_cast<int>(dim);	
						  FT_Init(0, 0, &f_basic);
						  for (int i = 0; i < dim;i++) {
							  const GeoLimit & xlimit = limits[i];
							  f_basic.L[i] = xlimit.low( ); 
							  f_basic.U[i] = xlimit.high( ); 
							  f_basic.gmax[i] = N;
							  f_basic.boundary[i][0] = f_basic.boundary[i][1] = Frontier::PERIODIC_BOUNDARY;
						  }

						  f_basic.size_of_intfc_state = 0;

						  FT_StartUp(&front, &f_basic);

						  level_func_pack.neg_component = 1;
						  level_func_pack.pos_component = 2;
						  level_func_pack.func_params = NULL;
						  level_func_pack.func = levelFunction; 
						  level_func_pack.wave_type = Frontier::FIRST_PHYSICS_WAVE_TYPE;
						  if (isAdapter) {
							  level_func_pack.func_params = this;
						  }
						  FT_InitIntfc(&front,&level_func_pack);
						 	if (dim == 2)
						  {
							  FT_ClipIntfcToSubdomain(&front);
						  }

						  velo_func_pack.func_params = NULL;
						  velo_func_pack.func = velocityFunction; 
//							velo_func_pack.point_propagate = Frontier::fourth_order_point_propagate;
							velo_func_pack.point_propagate = Frontier::first_order_point_propagate;

						  if (isAdapter) {
							  velo_func_pack.func_params = this;
						  }
						  FT_InitVeloFunc(&front,&velo_func_pack);


						  front.max_time = tmax;
						  front.max_step = 1000000;
						  front.print_time_interval = 1000000;
						  front.movie_frame_interval = 1000000;

						  int redistributionFrequency = 5;

						  Frequency_of_redistribution(&front, Frontier::GENERAL_WAVE) = redistributionFrequency;
							Frequency_of_redistribution(&front, Frontier::VECTOR_WAVE) = redistributionFrequency;
							Frequency_of_redistribution(&front, Frontier::GENERAL_NODE) = redistributionFrequency;

						  //						  enum _REDISTRIBUTION_MODE {
						  //						  	NO_REDIST        = 0,
						  //						  	EXPANSION_REDIST = 1,
						  //						  	FULL_REDIST      = 2
						  //						  };

						  //						  enum _REDISTRIBUTION_VERSION { // when FULL_REDIST
						  //						  	ORDINARY_REDISTRIBUTE  = 1,
						  //						  	EQUI_BOND_REDISTRIBUTE = 2
						  //						  };



							/*
						  REDISTRIBUTION_MODE redistributionMode = EXPANSION_REDIST;
						  Redistribution_mode(front) = redistributionMode;
							CURVE_CLEANERS Sav_cleaners;

							CurveRedistributionOptions(front) = curve_redist_options(init);
							clear_curve_redistribution_info(&Curve_redistribution_info(front));
							if (dim == 1)
									return;

							set_dflt_cur_redist_params(front);
							Sav_cleaners = Curve_redistribution_info(front).Cleaners;

							switch (front_redist_mode(init))
							{
							case NO_REDIST:
									clear_curve_redistribution_info(&Curve_redistribution_info(front));
									Curve_redistribution_info(front).Cleaners = Sav_cleaners;
									break;

							case EXPANSION_REDIST:
									clear_curve_redistribution_info(&Curve_redistribution_info(front));
									Curve_redistribution_function(front) = expansion_redistribute;
									Curve_redistribution_info(front).Cleaners = Sav_cleaners;
									break;

							case FULL_REDIST:
									Curve_redistribution_function(front) = full_redistribute;
									switch (full_curve_redist_version(init))
									{
									case ORDINARY_REDISTRIBUTE:
											Forward_curve_redistribute_function(front) =
													full_inc_redist_cur;
											Backward_curve_redistribute_function(front) =
													full_dec_redist_cur;
											break;

									case EQUI_BOND_REDISTRIBUTE:
											Forward_curve_redistribute_function(front) =
													equi_curve_redistribute;
											Backward_curve_redistribute_function(front) =
													backward_equi_curve_redistribute;
											break;
									}
							}
							*/

						  FT_RedistMesh(&front);
						  FT_ResetTime(&front);
						  // This is a virtual propagation to get maximum front 
						  // speed to determine the first time step.
						  FT_Propagate(&front);
						  FT_SetTimeStep(&front);
						  FT_SetOutputCounter(&front);
}

template<int numDim>
void movePoint(boost::multi_array<double,numDim> & array, int location, const Frontier::POINT &point) {
	for (int d = 0; d < numDim; d++) {
		array[location][d] = point._coords[d];
	}
}

/*
template<class P> UNKJUNK
void movePoint(const POINT &point) {
for (int d = 0; d < P.numDim( ); d++) {
array[location][d] = point._coords[d];
}
*/


static void retrievePoints_2d(Frontier::Front* front, std::vector<Frontier::POINT*>& points) 
{
	using Frontier::CURVE;
	using Frontier::BOND;
	using Frontier::POINT;
	//using Frontier::BDRY_MASK;
	CURVE** curves = front->interf->curves;
	if (curves == NULL) 
	{
		return;
	}
	int numCurves = 0;
	for (int i = 0; curves[i] != NULL; ++ i)
	{
		//mexPrintf("curve %d\n", i);
		CURVE* curve = curves[i];
		if (is_bdry(curve))
		{
			continue;
		}
		for (BOND* bond = curve->first; bond != NULL; bond = bond->next)
		{
			POINT* p = bond->start;
			if (p != NULL)
			{
				points.push_back(p);
			}
		}

		if (!curve->last && !curve->last->end)
		{
			POINT* p = curve->last->end;
			points.push_back(p);
		}
		++ numCurves;
	}
	//mexPrintf("# interior curves = %d\n", numCurves);
}

template <typename FCT>
bool VCellFront<FCT>::propagateTo(double time, std::ostream & os) {
	if (time > front.time) { 
		front.max_time = time;
		while (!FT_TimeLimitReached(&front)) {
			FT_TimeControlFilter(&front);
			FT_Propagate(&front);
			retrieveFront(os); //log points
			FT_AddTimeStepToCounter(&front);
			FT_SetTimeStep(&front);
		}
		return true;
	}
	return false;
}

template <typename FCT>
bool VCellFront<FCT>::propagateTo(double time) {
	if (time > front.time) { 
		front.max_time = time;
		bool first = true; //always run at least once
		while (first || !FT_TimeLimitReached(&front)) {
			first = false;
			FT_TimeControlFilter(&front);
			FT_Propagate(&front);
			FT_AddTimeStepToCounter(&front);
			FT_SetTimeStep(&front);
			VCELL_DEBUG("FT: time=" << front.time << ", step=" << front.step << ", next dt=" << front.dt);
		}
		return true;
	}
	return false;
}

template <typename FCT>
double VCellFront<FCT>::levelAdapter(Frontier::POINTER us, double *in) {
	assert(us != 0);
	VCellFront * vcf = static_cast<VCellFront *>(us); 
	assert(vcf->levelObj != 0);
	return vcf->levelObj->level(in);
}

template <typename FCT>
int VCellFront<FCT>::velocityAdapter(Frontier::POINTER us,Frontier::Front *ft,Frontier::POINT *pt,
								Frontier::HYPER_SURF_ELEMENT *hsf, Frontier::HYPER_SURF *hs, double *in) {
									assert(us != 0);
									VCellFront * vcf = static_cast<VCellFront *>(us); 
									assert(vcf->velObj != 0);
									return vcf->velObj->velocity(ft,pt,hsf,hs,in);
}

template <typename FCT>
std::vector<spatial::TPoint<FCT,2> > VCellFront<FCT>::retrieveFront( ) {
	try {
		return retrieveSurf( );
	} catch (std::domain_error &) {
		std::vector<std::vector<spatial::TPoint<FCT,2> > > curves = retrieveCurves( );
		matlabBridge::Polygons polygons("+");
		char colors[] = {'y','m','c','g','b','k'};
		std::vector<char> colorVec(colors, colors + sizeof(colors)/sizeof(colors[0]));
		polygons.setRainbow(colorVec);
		frontTierAdapt::copyVectorsInto(polygons,curves);
		std::ofstream mcurves("mcurves.m");
		mcurves << polygons;

		std::cout << "got " << curves.size( ) << " curves " << std::endl;
		throw;
	}
}
template <typename FCT>
std::vector<spatial::TPoint<FCT,2> > VCellFront<FCT>::retrieveFront(std::ostream & csv ) {
	typedef typename std::vector<spatial::TPoint<FCT,2> >::const_iterator Iterator;
	const char comma = ',';

	std::vector<spatial::TPoint<FCT,2> > rval = retrieveFront( ); 
	for (Iterator iter = rval.begin( );iter != rval.end( );++iter) {
		csv << front.step << comma << front.time << comma 
			<< iter->get(cX) << comma << iter->get(cY) << std::endl;
	}
	return rval;
}

template <typename FCT>
std::vector<spatial::TPoint<FCT,2> > VCellFront<FCT>::retrieveSurf( ) {
	using Frontier::CURVE;
	using Frontier::BOND;
	using Frontier::POINT;
	//using Frontier::BDRY_MASK;
	std::vector<VCFPointType> rval;
	CURVE** curves = front.interf->curves;
	if (curves == NULL) 
	{
		//return empty array
		return rval; 
	}
	int numPoints  = 0;
	for (CURVE * curve = *curves; curve != nullptr; ++curves, curve = *curves) { 
		//mexPrintf("curve %d\n", i);
		if (is_bdry(curve)) {
			continue;
		}
		for (BOND* bond = curve->first; bond != NULL; bond = bond->next) {
			Frontier::POINT* p = bond->start;
			if (p != NULL) {
				++ numPoints;
			}
		}

		if (curve->last != nullptr && curve->last->end != nullptr)
		{
			POINT* p = curve->last->end;
			++ numPoints;
		}
	}
	rval.reserve(numPoints);

	int numCurves = 0;
	double nor[DIM];
	curves = front.interf->curves;
	for (CURVE * curve = *curves; curve != nullptr; ++curves, curve = *curves) { 
		if (is_bdry(curve)) {
			continue;
		}
		for (BOND* bond = curve->first; bond != NULL; bond = bond->next) {
			Frontier::POINT* p = bond->start;
			if (p != NULL) {
				getPointNormal(p, nor);
				VCFPointType vcPoint(convertFrontier<FCT>(p->_coords, nor));
				rval.push_back(vcPoint);
			}
		}

		if (curve->last != nullptr && curve->last->end != nullptr)
		{
			Frontier::POINT* fPoint = curve->last->end;
			getPointNormal(fPoint, nor);
			VCFPointType vcPoint(convertFrontier<FCT>(fPoint->_coords, nor));
			rval.push_back(vcPoint);
		}
		numCurves++;
		//filter out "shadow" curves frontier returns sometimes
		if (++numCurves > 1) {
			VCFPointType & vcPoint = rval.front( );
			const double x = vcPoint(cX);
			const bool xGood = (x >= domainLimits[cX].low( ) &&  x <= domainLimits[cX].high( ));
			const double y = vcPoint(cY);
			const bool yGood = (y >= domainLimits[cY].low( ) &&  y <= domainLimits[cY].high( ));
			if (!xGood || !yGood) {
				VCELL_EXCEPTION(logic_error, "Multi curve frontier's first set, first point " << x  << ',' << y
					<< " out of bounds X" << domainLimits[cX] << " , Y"   << domainLimits[cY] << std::endl);
			}
			return rval;
		}
	}
	/*
	if (numCurves != 1) {
		VCELL_EXCEPTION(domain_error,"frontier returning " << numCurves << " curves");
	}
	assert(numCurves == 1);
	*/

	//Logger::stream( ) << "# interior curves = " << numCurves << EndLog; 

	return rval; 
}

template <typename FCT>
std::vector<std::vector<spatial::TPoint<FCT,2> > > VCellFront<FCT>::retrieveCurves( ) {
	using Frontier::CURVE;
	using Frontier::BOND;
	using Frontier::POINT;
	//using Frontier::BDRY_MASK;
	std::vector<std::vector<VCFPointType> >rval;

	int numCurves = 0;
	double nor[DIM];
	CURVE** curves = front.interf->curves;
	for (CURVE * curve = *curves; curve != nullptr; ++curves, curve = *curves) { 
		if (is_bdry(curve)) {
			continue;
		}
		std::vector<VCFPointType> cv;
		for (BOND* bond = curve->first; bond != NULL; bond = bond->next) {
			Frontier::POINT* p = bond->start;
			if (p != NULL) {
				getPointNormal(p, nor);
				VCFPointType vcPoint(convertFrontier<FCT>(p->_coords, nor));
				cv.push_back(vcPoint);
			}
		}

		if (curve->last != nullptr && curve->last->end != nullptr)
		{
			Frontier::POINT* fPoint = curve->last->end;
			getPointNormal(fPoint, nor);
			VCFPointType vcPoint(convertFrontier<FCT>(fPoint->_coords, nor));
			cv.push_back(vcPoint);
		}
		numCurves++;
		rval.push_back(cv);
	}

	VCELL_LOG(debug,"frontier # interior curves = " << numCurves );

	return rval; 
}

template <typename FCT>
void VCellFront<FCT>::getPointNormal(Frontier::POINT* p, double* nor)
{
	HYPER_SURF_ELEMENT *hse = p->hse;
	HYPER_SURF *hs = p->hs;
	GetFrontNormal(p, hse, hs, nor, &front);
}

template class spatial::VCellFront<double>;
template class spatial::VCellFront<int32_t>;

//these work as of 5/5/2016, but are not needed for current implementation
//template class spatial::VCellFront<int16_t>;
//template class spatial::VCellFront<int64_t>;
