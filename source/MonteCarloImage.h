#ifndef _MONTE_CARLO_
#define _MONTE_CARLO_
#include "vec3.h"
using namespace Math;
#include <string>

class MonteCarloImage {
	public:
		MonteCarloImage(const int x, const int y);
		~MonteCarloImage();

		void add(const int x, const int y, const Vec3<float> color);
		Vec3<float> & get(const int x, const int y) const;
		
		void save(const int samp, const std::string & path) const;

		int getWidth() const;
		int getHeight() const;

	private:
		int x, y;
		Vec3<float>* pixels;

};
#endif

