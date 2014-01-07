#ifndef VoronoiMesh_h
#define VoronoiMesh_h
#include <MovingBoundaryCollections.h>
#include <Mesh.h>
#include <VoronoiResult.h>

namespace moving_boundary {

	struct MeshElementSpecies; 
	template<class MPOINT >
	struct Positions {
		std::vector<MPOINT *> inside;
		std::vector<MPOINT *> outside;
		std::vector<MPOINT *> boundary;
	}; 

	struct VoronoiMesh {
		//typedef REAL FloatingPointType;
		typedef spatial::MeshDef<moving_boundary::CoordinateType,2> MBMeshDef; 
		typedef MeshElementSpecies Element;
		typedef spatial::Mesh<moving_boundary::CoordinateType,2,Element> MBMesh; 

		VoronoiMesh(MBMesh &m);

		~VoronoiMesh( );

		/**
		* set the front to use
		*/
		void setFront(const FrontType & front);

		/**
		* get voronoi for specific element
		*/
		void getResult(spatial::VoronoiResult &, const Element & element) const;

		const MBMesh &mesh( ) const {
			return mesh_;
		}

		/**
		* dump out current voronoi to stream 
		* @param os output stream
		* @param pFront pointer to front (optional, may be null)
		*/
		void matlabPlot(std::ostream &, const FrontType *pFront = nullptr);

	Positions<Element> classify2(const FrontType & polygon); 

	/**
	* adjust positions of nodes relative to front 
	* @param boundaryContainer struct which supports push_back (e.g. STL)
	* @param front new front
	*/
	template<class STL_CONTAINER>
	bool adjustNodes(STL_CONTAINER & boundaryContainer, const FrontType & front);

	private:
		struct VoronoiMeshImpl;

		MBMesh &mesh_;
		VoronoiMeshImpl * impl;
	};

}
#endif
