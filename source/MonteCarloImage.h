#ifndef _MONTE_CARLO_
#define _MONTE_CARLO_
#include "vec3.h"

class MonteCarloImage {
	public:
		MonteCarloImage(int x, int y);
		void add(int x, int y, Vec3<float> color);
		Vec3<float>& get(int x, int y) const;
	private:
		Vec3<float>** pixels;

};
#endif
