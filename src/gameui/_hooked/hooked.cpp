#include "ICareerUI.h"
#include "IGameConsole.h"
#include "IGameUI.h"
#include "IMusicManager.h"
#include "IRunGameEngine.h"
#include "IVGuiModuleLoader.h"
#include "interface.h"
#include <iostream>
#include <windows.h>

auto hLibModule = Sys_LoadModule("valve/cl_dlls/GameUI.dll");
auto factoryFn = Sys_GetFactory(hLibModule);


//carrerui
EXPOSE_SINGLE_INTERFACE(ICareerUI_Hooked, ICareerUI, CAREERUI_INTERFACE_VERSION);
auto pCareerUI = static_cast<ICareerUI*>(factoryFn(CAREERUI_INTERFACE_VERSION, nullptr));

bool ICareerUI_Hooked::IsPlayingMatch() { return pCareerUI->IsPlayingMatch(); }
ITaskVec* ICareerUI_Hooked::GetCurrentTaskVec() { return pCareerUI->GetCurrentTaskVec(); }
bool ICareerUI_Hooked::PlayAsCT() { return pCareerUI->PlayAsCT(); }
int ICareerUI_Hooked::GetReputationGained() { return pCareerUI->GetReputationGained(); }
int ICareerUI_Hooked::GetNumMapsUnlocked() { return pCareerUI->GetNumMapsUnlocked(); }
bool ICareerUI_Hooked::DoesWinUnlockAll() { return pCareerUI->DoesWinUnlockAll(); }
int ICareerUI_Hooked::GetRoundTimeLength() { return pCareerUI->GetRoundTimeLength(); }
int ICareerUI_Hooked::GetWinfastLength() { return pCareerUI->GetWinfastLength(); }
CareerDifficultyType ICareerUI_Hooked::GetDifficulty() const { return pCareerUI->GetDifficulty(); }
int ICareerUI_Hooked::GetCurrentMapTriplet(MapInfo* maps) { return pCareerUI->GetCurrentMapTriplet(maps); }
void ICareerUI_Hooked::OnRoundEndMenuOpen(bool didWin) { pCareerUI->OnRoundEndMenuOpen(didWin); }
void ICareerUI_Hooked::OnMatchEndMenuOpen(bool didWin) { pCareerUI->OnMatchEndMenuOpen(didWin); }
void ICareerUI_Hooked::OnRoundEndMenuClose(bool stillPlaying) { pCareerUI->OnRoundEndMenuClose(stillPlaying); }
void ICareerUI_Hooked::OnMatchEndMenuClose(bool stillPlaying) { pCareerUI->OnMatchEndMenuClose(stillPlaying); }


//gameconsole
auto pGameConsole = static_cast<IGameConsole*>(factoryFn(GAMECONSOLE_INTERFACE_VERSION, nullptr));
EXPOSE_SINGLE_INTERFACE(IGameConsole_Hooked, IGameConsole, GAMECONSOLE_INTERFACE_VERSION);

void IGameConsole_Hooked::Activate() { pGameConsole->Activate(); }
void IGameConsole_Hooked::Initialize() { pGameConsole->Initialize(); }
void IGameConsole_Hooked::Hide() { pGameConsole->Hide(); }
void IGameConsole_Hooked::Clear() { pGameConsole->Clear(); }
bool IGameConsole_Hooked::IsConsoleVisible() { return pGameConsole->IsConsoleVisible(); }
void IGameConsole_Hooked::Printf(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	if (!strcmp(format, "%d"))
	{
		pGameConsole->Printf(format, va_arg(ap, int));
		va_end(ap);
		return;
	}

	if (!strcmp(format, "%s"))
	{
		pGameConsole->Printf(format, va_arg(ap, char*));
		va_end(ap);
		return;
	}
	// хз че делать если не то
	va_end(ap);
	pGameConsole->Printf(format, nullptr);
}
void IGameConsole_Hooked::DPrintf(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	if (!strcmp(format, "%d"))
	{
		pGameConsole->Printf(format, va_arg(ap, int));
		va_end(ap);
		return;
	}

	if (!strcmp(format, "%s"))
	{
		pGameConsole->Printf(format, va_arg(ap, char*));
		va_end(ap);
		return;
	}
	// хз че делать если не то
	va_end(ap);
	pGameConsole->Printf(format, nullptr);
}
void IGameConsole_Hooked::SetParent(unsigned int parent) { pGameConsole->SetParent(parent); }


// gameui
auto pGameUI = static_cast<IGameUI*>(factoryFn(GAMEUI_INTERFACE_VERSION, nullptr));
EXPOSE_SINGLE_INTERFACE(IGameUI_Hooked, IGameUI, GAMEUI_INTERFACE_VERSION);

void IGameUI_Hooked::Initialize(CreateInterfaceFn* factories, int count) { pGameUI->Initialize(factories, count); } //FUN_1002a070
void IGameUI_Hooked::Start(cl_enginefunc_t* engineFuncs, int interfaceVersion, IBaseSystem* system) //FUN_1002a8a0
{
	pGameUI->Start(engineFuncs, interfaceVersion, system); 
}
void IGameUI_Hooked::Shutdown() { pGameUI->Shutdown(); }
int IGameUI_Hooked::ActivateGameUI() 
{ 
	return 0;
	int result = pGameUI->ActivateGameUI();
	return result;
}
int	IGameUI_Hooked::ActivateDemoUI() { return pGameUI->ActivateDemoUI(); }
int	IGameUI_Hooked::HasExclusiveInput() { return pGameUI->HasExclusiveInput(); }
void IGameUI_Hooked::RunFrame() { pGameUI->RunFrame(); }
void IGameUI_Hooked::ConnectToServer(const char* game, int IP, int port) { pGameUI->ConnectToServer(game, IP, port); }
void IGameUI_Hooked::DisconnectFromServer() { pGameUI->DisconnectFromServer(); }
void IGameUI_Hooked::HideGameUI() { pGameUI->HideGameUI(); }
int	IGameUI_Hooked::IsGameUIActive() { return pGameUI->IsGameUIActive(); }
void IGameUI_Hooked::LoadingStarted(const char* resourceType, const char* resourceName) { pGameUI->LoadingStarted(resourceType, resourceName); }
void IGameUI_Hooked::LoadingFinished(const char* resourceType, const char* resourceName) { pGameUI->LoadingFinished(resourceType, resourceName); }
void IGameUI_Hooked::StartProgressBar(const char* progressType, int progressSteps) { pGameUI->StartProgressBar(progressType, progressSteps); }
int IGameUI_Hooked::ContinueProgressBar(int progressPoint, float progressFraction) { return pGameUI->ContinueProgressBar(progressPoint, progressFraction); }
void IGameUI_Hooked::StopProgressBar(bool bError, const char* failureReason, const char* extendedReason) { pGameUI->StopProgressBar(bError, failureReason, extendedReason); }
int IGameUI_Hooked::SetProgressBarStatusText(const char* statusText) { return pGameUI->SetProgressBarStatusText(statusText); }
void IGameUI_Hooked::SetSecondaryProgressBar(float progress) { pGameUI->SetSecondaryProgressBar(progress); }
void IGameUI_Hooked::SetSecondaryProgressBarText(const char* statusText) { pGameUI->SetSecondaryProgressBarText(statusText); }
void IGameUI_Hooked::ValidateCDKey(bool force, bool inConnect) { pGameUI->ValidateCDKey(force, inConnect); }
void IGameUI_Hooked::OnDisconnectFromServer(int eSteamLoginFailure, const char* username) { pGameUI->OnDisconnectFromServer(eSteamLoginFailure, username); }


// musicmanager
auto pMusicManager = static_cast<IMusicManager*>(factoryFn(MUSICMANAGER_INTERFACE_VERSION, nullptr));
EXPOSE_SINGLE_INTERFACE(IMusicManager_Hooked, IMusicManager, MUSICMANAGER_INTERFACE_VERSION);

void IMusicManager_Hooked::StartTrack(TrackType track, bool looping) { pMusicManager->StartTrack(track, looping); }
void IMusicManager_Hooked::StopTrack() { pMusicManager->StopTrack(); }
void IMusicManager_Hooked::FadeOutTrack() { pMusicManager->FadeOutTrack(); }
bool IMusicManager_Hooked::IsPlayingTrack() { return pMusicManager->IsPlayingTrack(); }
bool IMusicManager_Hooked::IsPlayingTrack(TrackType track) {return pMusicManager->IsPlayingTrack(track); }


//rungameengine
auto pRunGameEngine = static_cast<IRunGameEngine*>(factoryFn(RUNGAMEENGINE_INTERFACE_VERSION, nullptr));
EXPOSE_SINGLE_INTERFACE(IRunGameEngine_Hooked, IRunGameEngine, RUNGAMEENGINE_INTERFACE_VERSION);

bool IRunGameEngine_Hooked::IsRunning() { return pRunGameEngine->IsRunning(); }
bool IRunGameEngine_Hooked::AddTextCommand(const char* text) { return pRunGameEngine->AddTextCommand(text); }
IRunGameEngine_Hooked::ERunResult IRunGameEngine_Hooked::RunEngine(int iAppID, const char* gameDir, const char* commandLineParams) { return pRunGameEngine->RunEngine(iAppID, gameDir, commandLineParams); }
bool IRunGameEngine_Hooked::IsInGame() { return pRunGameEngine->IsInGame(); }
bool IRunGameEngine_Hooked::GetGameInfo(char* infoBuffer, int bufferSize) { return pRunGameEngine->GetGameInfo(infoBuffer, bufferSize); }
void IRunGameEngine_Hooked::SetTrackerUserID(int trackerID, const char* trackerName) { pRunGameEngine->SetTrackerUserID(trackerID, trackerName); }
int IRunGameEngine_Hooked::GetPlayerCount() { return pRunGameEngine->GetPlayerCount(); }
unsigned int IRunGameEngine_Hooked::GetPlayerFriendsID(int playerIndex) { return pRunGameEngine->GetPlayerFriendsID(playerIndex); }
const char* IRunGameEngine_Hooked::GetPlayerName(int friendsID) { return pRunGameEngine->GetPlayerName(friendsID); }
const char* IRunGameEngine_Hooked::GetPlayerFriendsName(int friendsID) { return pRunGameEngine->GetPlayerFriendsName(friendsID); }
unsigned int IRunGameEngine_Hooked::GetEngineBuildNumber() { return pRunGameEngine->GetEngineBuildNumber(); }
const char* IRunGameEngine_Hooked::GetProductVersionString() { return pRunGameEngine->GetProductVersionString(); }
unsigned int IRunGameEngine_Hooked::GetPlayerUserID(int playerIndex) { return pRunGameEngine->GetPlayerUserID(playerIndex); }


// vguimoduleloader
auto pVGuiModuleLoader = static_cast<IVGuiModuleLoader*>(factoryFn(VGUIMODULELOADER_INTERFACE_VERSION, nullptr));
EXPOSE_SINGLE_INTERFACE(IVGuiModuleLoader_Hooked, IVGuiModuleLoader, VGUIMODULELOADER_INTERFACE_VERSION);

int IVGuiModuleLoader_Hooked::GetModuleCount() { return pVGuiModuleLoader->GetModuleCount(); }
const char* IVGuiModuleLoader_Hooked::GetModuleLabel(int moduleIndex) { return pVGuiModuleLoader->GetModuleLabel(moduleIndex); }
CreateInterfaceFn IVGuiModuleLoader_Hooked::GetModuleFactory(int moduleIndex) { return pVGuiModuleLoader->GetModuleFactory(moduleIndex); }
bool IVGuiModuleLoader_Hooked::ActivateModule(int moduleIndex) { return pVGuiModuleLoader->ActivateModule(moduleIndex); }
bool IVGuiModuleLoader_Hooked::ActivateModule(const char* moduleName) { return pVGuiModuleLoader->ActivateModule(moduleName); }
void IVGuiModuleLoader_Hooked::SetPlatformToRestart() { pVGuiModuleLoader->SetPlatformToRestart(); }