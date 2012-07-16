#ifndef _MONTE_CARLO_
#define _MONTE_CARLO_
#include "vec3.h"
using namespace Math;

class MonteCarloImage {
	public:
		MonteCarloImage(int x, int y);
		~MonteCarloImage();

		void add(int x, int y, Vec3<float> color);
		Vec3<float> & get(int x, int y) const;
		
		void save() const;

	private:
		int x, y;
		Vec3<float>** pixels;

};
#endif

