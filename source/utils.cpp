#include "utils.hpp"

namespace globals
{

	# ifdef SHIT_PLATFORM
		CGlobalVars*	GlobalVars_ptr	= nullptr;
	# else
		IEngineTool* IEngineTool_ptr	= nullptr;
	# endif

}


int	gmsv_tickrateInit()
{ 

	# ifdef SHIT_PLATFORM
		globals::GlobalVars_ptr = nullptr;
		globals::GlobalVars_ptr	= InterfacePointers::Internal::Server::GlobalVars();
		if (!globals::GlobalVars_ptr)
			return (0);
	# else
		std::unique_ptr<SourceSDK::FactoryLoader>	engineFactory;
		engineFactory = std::make_unique<SourceSDK::FactoryLoader>("engine");

		if (!engineFactory)
			return (1);

		globals::IEngineTool_ptr	= nullptr;
		globals::IEngineTool_ptr	= engineFactory->GetInterface<IEngineTool>(VENGINETOOL_INTERFACE_VERSION);

		if (!globals::IEngineTool_ptr)
			return (2);
	# endif
	
	return (-1);

}


double	getHostFrameTime()
{

	# ifdef SHIT_PLATFORM
		return (static_cast<double>(globals::GlobalVars_ptr->absoluteframetime));
	# else
		return (static_cast<double>(globals::IEngineTool_ptr->HostFrameTime()));
	# endif

}