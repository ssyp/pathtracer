#ifndef _MONTE_CARLO_
#define _MONTE_CARLO_
#include <list>
#include "vector.h"

class MonteCarloImage {
	public:
		MonteCarloImage(int x, int y);
		void add(int x, int y, Vector& color);
		Vector& get(int x, int y) const;
	private:
		Vector** pixels;

};
#endif