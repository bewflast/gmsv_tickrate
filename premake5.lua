PROJECT_GENERATOR_VERSION = 3

newoption({
	trigger = "gmcommon",
	description = "Sets the path to the garrysmod_common (https://github.com/danielga/garrysmod_common) directory",
	value = "../garrysmod_common"
})

local gmcommon = assert(_OPTIONS.gmcommon or os.getenv("GARRYSMOD_COMMON"),
	"you didn't provide a path to your garrysmod_common (https://github.com/danielga/garrysmod_common) directory")

include(gmcommon)

includedirs(_SCRIPT_DIR .. "/include")
files { _SCRIPT_DIR  .. "/include/**.h" }

CreateWorkspace({name = "tickrate"})
	CreateProject({serverside = true})
		IncludeHelpers()
		IncludeHelpersExtended()
