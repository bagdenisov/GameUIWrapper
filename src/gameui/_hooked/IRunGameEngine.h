//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#include "../IRunGameEngine.h"

class IRunGameEngine_Hooked : public IRunGameEngine
{
public:
	bool IsRunning() override;
	bool AddTextCommand(const char *text) override;
	ERunResult RunEngine( int iAppID, const char *gameDir, const char *commandLineParams ) override;
	bool IsInGame() override;
	bool GetGameInfo(char *infoBuffer, int bufferSize) override;
	void SetTrackerUserID(int trackerID, const char *trackerName) override;
	int GetPlayerCount() override;
	unsigned int GetPlayerFriendsID(int playerIndex) override;
	const char *GetPlayerName(int friendsID) override;
	const char *GetPlayerFriendsName(int friendsID) override;
	unsigned int GetEngineBuildNumber() override;
	const char *GetProductVersionString() override;
	unsigned int GetPlayerUserID( int playerIndex ) override;
};
