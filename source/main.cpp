#include <GarrysMod/Lua/Interface.h>
#include <GarrysMod/FactoryLoader.hpp>
#include <GarrysMod/InterfacePointers.hpp>

#include <tickrate.h>

#include <memory>


namespace globals
{
	IEngineTool*	IEngineTool_ptr		=	nullptr;
}


static	double	getHostFT()
{
	return(static_cast<double>(globals::IEngineTool_ptr->HostFrameTime()));
}


LUA_FUNCTION(HostFrameTime)
{
	LUA->PushNumber(getHostFT());

	return (1);
}


LUA_FUNCTION(GetServerTickrate)
{
	LUA->PushNumber(1.0 / getHostFT());
	
	return (1);
}


GMOD_MODULE_OPEN()
{
	std::unique_ptr<SourceSDK::FactoryLoader>	engineFactory;

	engineFactory				=	std::make_unique<SourceSDK::FactoryLoader>("engine");
	globals::IEngineTool_ptr	=	engineFactory->GetInterface<IEngineTool>(VENGINETOOL_INTERFACE_VERSION);

	LUA->GetField(GarrysMod::Lua::INDEX_GLOBAL, "util");
	LUA->PushCFunction(GetServerTickrate);
	LUA->SetField(-2, "GetServerTickrate");

	LUA->Pop();

	LUA->GetField(GarrysMod::Lua::INDEX_GLOBAL, "engine");
	LUA->PushCFunction(HostFrameTime);
	LUA->SetField(-2, "HostFrameTime");

	LUA->Pop();

	return (0);
}


GMOD_MODULE_CLOSE()
{
	delete	globals::IEngineTool_ptr;

	return (0);
}
