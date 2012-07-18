#ifndef __SURFACEFACTORY_H__
#define __SURFACEFACTORY_H__


class SurfaceFactory {
	public:
		
		ISurface * createSurface(const Block & block);

};

#endif
