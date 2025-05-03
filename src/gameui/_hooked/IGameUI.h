#pragma once
#include "../IGameUI.h"

class IGameUI_Hooked : public IGameUI
{
public:
	void Initialize(CreateInterfaceFn* factories, int count) override;
	void Start(cl_enginefunc_t* engineFuncs, int interfaceVersion, IBaseSystem* system) override;
	void Shutdown() override;
	int ActivateGameUI() override;
	int ActivateDemoUI() override;
	int HasExclusiveInput() override;
	void RunFrame() override;
	void ConnectToServer(const char* game, int IP, int port) override;
	void DisconnectFromServer() override;
	void HideGameUI() override;
	int IsGameUIActive() override;
	void LoadingStarted(const char* resourceType, const char* resourceName) override;
	void LoadingFinished(const char* resourceType, const char* resourceName) override;
	void StartProgressBar(const char* progressType, int progressSteps) override;
	int ContinueProgressBar(int progressPoint, float progressFraction) override;
	void StopProgressBar(bool bError, const char* failureReason, const char* extendedReason) override;
	int SetProgressBarStatusText(const char* statusText) override;
	void SetSecondaryProgressBar(float progress) override;
	void SetSecondaryProgressBarText(const char* statusText) override;
	void ValidateCDKey(bool force, bool inConnect) override;
	void OnDisconnectFromServer(int eSteamLoginFailure, const char* username) override;
};

