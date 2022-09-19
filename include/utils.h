#ifndef UTILS_H
# define UTILS_H

# include "sdk.h"

# ifdef SHIT_PLATFORM

# include <GarrysMod/InterfacePointers.hpp>

# else

# include <GarrysMod/FactoryLoader.hpp>
# include <memory>

# endif

int		gmsv_tickrateInit();
double	getHostFrameTime();

#endif