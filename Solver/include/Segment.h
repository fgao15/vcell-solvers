#ifndef Segment_h
#define Segment_h
#include <TPoint.h>
#include <ostream>

namespace spatial {
	/**
	* sortable, comparable modeling of segment between two points TPoint<T,N>
	* point order is not maintained / meaningful
	* @tparam T point type 
	* @tparam N point number of dimensions
	*/
	template <typename T, int N>
	struct Segment {
		static_assert(N > 0, "Segment dim must be non-zero");

		/**
		* ctor; order of arguments doesn't matter
		* @param one one endpoint
		* @param other endpoint
		*/
		Segment(const TPoint<T,N> & one = TPoint<T,N>( ) , const TPoint<T,N> & other= TPoint<T,N>( ) ) 
			:points(construct(one,other)) {}

		Segment(const Segment<T,N> &rhs) 
			:points(rhs.points) {}

		//default assigment operator works fine

		/**
		* one of the points; it is guaranteed #a( ) <= #b( )
		*/
		const TPoint<T,N> & a( ) const {
			return points[0];
		}
		/**
		* the other point; it is guaranteed #a( ) <= #b( )
		*/
		const TPoint<T,N> & b( ) const {
			return points[1];
		}

		/**
		* segment has equal endpoints; is a point. Default constructed
		*/
		const bool singular( ) const {
			return a( ) == b( );
		}

		/**
		* @tparam M calculation / return type of magnitude squared. Most be selected to prevent overflow of integral types
		*/
		template <typename M>
		const M magnitudeSquared( ) const {
			return spatial::magnitudeSquared<M>(points[0], points[1]);
		}

		/**
		* @tparam M calculation / return type of magnitude. Most be selected to prevent overflow of integral types
		*/
		template <typename M>
		const M magnitude( ) const {
			return spatial::magnitude<M>(points[0], points[1]);
		}

		/**
		* @return true if and only if points have same y value 
		*/
		bool horizontal() const{
			return points[0](cY) == points[1](cY); 
		}

		/**
		* @return true if and only if points have same x value 
		*/
		bool vertical( ) const {
			return points[0](cX) == points[1](cX); 
		}

		/**
		* return distance along specified axis
		*/
		T axialDistance(Axis a) const {
			assert (a < N);
			T lc = points[0](a);
			T rc = points[1](a);
			return rc > lc ? rc -lc : lc - rc;
		}

	private:
		std::array<TPoint<T,N>, 2> points;
		static std::array<TPoint<T,N>, 2> construct(const TPoint<T,N> & one , const TPoint<T,N> & other) {
			std::array<TPoint<T,N>, 2> rval; 
			for (Axis a = axisInitial; a < N; ++a) {
				if (one(a) < other(a)) {
					rval[0] = one;
					rval[1] = other;
					return rval;
				}
				else if (other(a) < one(a) ) { 
					rval[0] = other;
					rval[1] = one;
					return rval;
				}
			}
			rval[0] = one;
			rval[1] = other;
			return rval;
		}
	};

	template <typename T, int N>
	bool operator==(const Segment<T,N> & one , const Segment<T,N> & other) {
		return (one.a( ) == other.a( ) ) &&  (one.b( ) == other.b( ));
	}

	template <typename T, int N>
	bool operator<(const Segment<T,N> & one , const Segment<T,N> & other) {
		if (one.a( ) < other.a( ) ) {
			return true;
		}
		if (other.a( ) < one.a( ) ) {
			return false;
		}
		return one.b( ) < other.b( ); 
	}

	template <typename T, int N>
	std::ostream & operator<<(std::ostream & os, const Segment<T,N> & seg) {
		os << '{' << seg.a( ) << " : " << seg.b( ) << '}' << std::endl;
		return os;
	}
}

#endif
