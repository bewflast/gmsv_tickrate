#ifndef TICKRATE_H
# define TICKRATE_H

#include <GarrysMod/Lua/Interface.h>
#include <GarrysMod/FactoryLoader.hpp>
#include <GarrysMod/InterfacePointers.hpp>

#include <memory>

typedef void* (*CreateInterfaceFn)(const char* pName, int* pReturnCode);

template< class T, class I = int >
class CUtlMemory;

template< class T, class A = CUtlMemory<T> >
class CUtlVector;

class Vector;
class CViewSetup;
class IToolSystem;
class KeyValues;
class ITraceFilter;
class CBaseTrace;
class IVideoRecorder;
class VMatrix;
class IPartitionQueryCallback;
class IHandleEntity;

struct dlight_t;
struct Ray_t;
struct AudioState_t;
struct model_t;
struct studiohdr_t;
struct con_nprint_s;
struct LightDesc_t;

typedef unsigned short SpatialPartitionHandle_t;
typedef bool (*FnQuitHandler)(void* pvUserData);
typedef unsigned int HTOOLHANDLE;
typedef int SpatialPartitionListMask_t;

#ifndef MAX_DLIGHTS
#define	MAX_DLIGHTS		32
#endif

#define PRINTF_FORMAT_STRING
#define VENGINETOOLFRAMEWORK_INTERFACE_VERSION	"VENGINETOOLFRAMEWORK003"
#define VENGINETOOL_INTERFACE_VERSION	"VENGINETOOL003"
#define	PITCH_NORM		100

enum soundlevel_t
{
	SNDLVL_NONE = 0,
	SNDLVL_20dB = 20,
	SNDLVL_25dB = 25,
	SNDLVL_30dB = 30,
	SNDLVL_35dB = 35,
	SNDLVL_40dB = 40,
	SNDLVL_45dB = 45,
	SNDLVL_50dB = 50,
	SNDLVL_55dB = 55,
	SNDLVL_IDLE = 60,
	SNDLVL_60dB = 60,
	SNDLVL_65dB = 65,
	SNDLVL_STATIC = 66,
	SNDLVL_70dB = 70,
	SNDLVL_NORM = 75,
	SNDLVL_75dB = 75,
	SNDLVL_80dB = 80,
	SNDLVL_TALKING = 80,
	SNDLVL_85dB = 85,
	SNDLVL_90dB = 90,
	SNDLVL_95dB = 95,
	SNDLVL_100dB = 100,
	SNDLVL_105dB = 105,
	SNDLVL_110dB = 110,
	SNDLVL_120dB = 120,
	SNDLVL_130dB = 130,
	SNDLVL_GUNFIRE = 140,
	SNDLVL_140dB = 140,
	SNDLVL_150dB = 150,
	SNDLVL_180dB = 180,
};

class IBaseInterface
{
public:
	virtual	~IBaseInterface() {}
};

class IEngineToolFramework : public IBaseInterface
{
public:
	virtual int			GetToolCount() const = 0;
	virtual char const* GetToolName(int index) const = 0;
	virtual void		SwitchToTool(int index) = 0;
	virtual bool		IsTopmostTool(const IToolSystem* sys) const = 0;
	virtual const IToolSystem* GetToolSystem(int index) const = 0;
	virtual IToolSystem* GetTopmostTool() = 0;
	virtual void		ShowCursor(bool show) = 0;
	virtual bool		IsCursorVisible() const = 0;
};

class IEngineTool : public IEngineToolFramework
{
public:
	virtual void		GetServerFactory(CreateInterfaceFn& factory) = 0;
	virtual void		GetClientFactory(CreateInterfaceFn& factory) = 0;

	virtual float		GetSoundDuration(const char* pszName) = 0;
	virtual bool		IsSoundStillPlaying(int guid) = 0;
	virtual int			StartSound(
		int iUserData,
		bool staticsound,
		int iEntIndex,
		int iChannel,
		const char* pSample,
		float flVolume,
		soundlevel_t iSoundlevel,
		const Vector& origin,
		const Vector& direction,
		int iFlags = 0,
		int iPitch = PITCH_NORM,
		bool bUpdatePositions = true,
		float delay = 0.0f,
		int speakerentity = -1) = 0;
	virtual void		StopSoundByGuid(int guid) = 0;
	virtual float		GetSoundDuration(int guid) = 0;
	virtual bool		IsLoopingSound(int guid) = 0;
	virtual void		ReloadSound(const char* pSample) = 0;
	virtual void		StopAllSounds() = 0;
	virtual float		GetMono16Samples(const char* pszName, CUtlVector< short >& sampleList) = 0;
	virtual void		SetAudioState(const AudioState_t& audioState) = 0;
	virtual void		Command(char const* cmd) = 0;
	virtual void		Execute() = 0;
	virtual char const* GetCurrentMap() = 0;
	virtual void		ChangeToMap(char const* mapname) = 0;
	virtual bool		IsMapValid(char const* mapname) = 0;
	virtual void		RenderView(CViewSetup& view, int nFlags, int whatToRender) = 0;
	virtual bool		IsInGame() = 0;
	virtual bool		IsConnected() = 0;
	virtual int			GetMaxClients() = 0;
	virtual bool		IsGamePaused() = 0;
	virtual void		SetGamePaused(bool paused) = 0;
	virtual float		GetTimescale() = 0;
	virtual void		SetTimescale(float scale) = 0;
	virtual float		GetRealTime() = 0;
	virtual float		GetRealFrameTime() = 0;
	virtual float		Time() = 0;
	virtual float		HostFrameTime() = 0;
	virtual float		HostTime() = 0;
	virtual int			HostTick() = 0;
	virtual int			HostFrameCount() = 0;
	virtual float		ServerTime() = 0;
	virtual float		ServerFrameTime() = 0;
	virtual int			ServerTick() = 0;
	virtual float		ServerTickInterval() = 0;
	virtual float		ClientTime() = 0;
	virtual float		ClientFrameTime() = 0;
	virtual int			ClientTick() = 0;
	virtual void		SetClientFrameTime(float frametime) = 0;
	virtual void		ForceUpdateDuringPause() = 0;
	virtual model_t* GetModel(HTOOLHANDLE hEntity) = 0;
	virtual studiohdr_t* GetStudioModel(HTOOLHANDLE hEntity) = 0;
	virtual void		Con_NPrintf(int pos, PRINTF_FORMAT_STRING const char* fmt, ...) = 0;
	virtual void		Con_NXPrintf(const struct con_nprint_s* info, PRINTF_FORMAT_STRING const char* fmt, ...) = 0;
	virtual void        GetGameDir(char* szGetGameDir, int maxlength) = 0;
	virtual void		GetScreenSize(int& width, int& height) = 0;
	virtual void		SetMainView(const Vector& vecOrigin, const QAngle& angles) = 0;
	virtual bool		GetPlayerView(CViewSetup& playerView, int x, int y, int w, int h) = 0;
	virtual void		CreatePickingRay(const CViewSetup& viewSetup, int x, int y, Vector& org, Vector& forward) = 0;
	virtual bool		PrecacheSound(const char* pName, bool bPreload = false) = 0;
	virtual bool		PrecacheModel(const char* pName, bool bPreload = false) = 0;
	virtual void		InstallQuitHandler(void* pvUserData, FnQuitHandler func) = 0;
	virtual void		TakeTGAScreenShot(char const* filename, int width, int height) = 0;
	virtual void		ForceSend() = 0;
	virtual bool		IsRecordingMovie() = 0;
	virtual void		StartMovieRecording(KeyValues* pMovieParams) = 0;
	virtual void		EndMovieRecording() = 0;
	virtual void		CancelMovieRecording() = 0;
	virtual IVideoRecorder* GetActiveVideoRecorder() = 0;
	virtual void		StartRecordingVoiceToFile(char const* filename, char const* pPathID = 0) = 0;
	virtual void		StopRecordingVoiceToFile() = 0;
	virtual bool		IsVoiceRecording() = 0;
	virtual void		TraceRay(const Ray_t& ray, unsigned int fMask, ITraceFilter* pTraceFilter, CBaseTrace* pTrace) = 0;
	virtual void		TraceRayServer(const Ray_t& ray, unsigned int fMask, ITraceFilter* pTraceFilter, CBaseTrace* pTrace) = 0;
	virtual bool		IsConsoleVisible() = 0;
	virtual int			GetPointContents(const Vector& vecPosition) = 0;
	virtual int			GetActiveDLights(dlight_t* pList[MAX_DLIGHTS]) = 0;
	virtual int			GetLightingConditions(const Vector& vecPosition, Vector* pColors, int nMaxLocalLights, LightDesc_t* pLocalLights) = 0;
	virtual void		GetWorldToScreenMatrixForView(const CViewSetup& view, VMatrix* pVMatrix) = 0;
	virtual SpatialPartitionHandle_t CreatePartitionHandle(IHandleEntity* pEntity,
		SpatialPartitionListMask_t listMask, const Vector& mins, const Vector& maxs) = 0;
	virtual void DestroyPartitionHandle(SpatialPartitionHandle_t hPartition) = 0;
	virtual void InstallPartitionQueryCallback(IPartitionQueryCallback* pQuery) = 0;
	virtual void RemovePartitionQueryCallback(IPartitionQueryCallback* pQuery) = 0;
	virtual void ElementMoved(SpatialPartitionHandle_t handle,
		const Vector& mins, const Vector& maxs) = 0;
};

#endif