#ifndef __CONSTANTBACKGROUND_H__
#define __CONSTANTBACKGROUND_H__

#include "IBackground.h"
#include "Block.h"

class ConstantBackground : public IBackground {
		public:
			Vec3<float> getColor(const Ray & ray);

			void init(const Block & block);
		
		protected:
			Vec3<float> color;
};

#endif
