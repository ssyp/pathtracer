#ifndef _MONTE_CARLO_
#define _MONTE_CARLO_

#include <string>
#include "Vec3.h"

using namespace Math;

class MonteCarloImage {
	public:
		MonteCarloImage(const int x, const int y);
		~MonteCarloImage();

		void add(const int x, const int y, const Vec3<float> color);
		Vec3<float> & get(const int x, const int y) const;
		
		int getWidth() const;
		int getHeight() const;

	private:
		int x, y;
		Vec3<float>* pixels;
};

#endif
