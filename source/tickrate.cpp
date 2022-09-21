#include "tickrate.hpp"

LUA_FUNCTION(HostFrameTime)
{
	LUA->PushNumber(getHostFrameTime());

	return (1);
}


LUA_FUNCTION(GetServerTickrate)
{
	LUA->PushNumber(1.0 / getHostFrameTime());
	
	return (1);
}


GMOD_MODULE_OPEN()
{
	char*	init_errors[3] =
	{
		"(gmsv_tickrate) Error while accessing to gpGlobals!",
		"(gmsv_tickrate) Error while getting engine factory!",
		"(gmsv_tickrate) Error while accessing to IEngineTools interface!"
	};

	int	post_init_status	= gmsv_tickrateInit();

	if (post_init_status != -1)
		LUA->ThrowError(init_errors[post_init_status]);

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

	return (0);

}
