#pragma once
#include "../ICareerUI.h"

class ICareerUI_Hooked : public ICareerUI
{
public:
	bool IsPlayingMatch() override;
	ITaskVec* GetCurrentTaskVec() override;
	bool PlayAsCT() override;
	int GetReputationGained() override;
	int GetNumMapsUnlocked() override;
	bool DoesWinUnlockAll() override;
	int GetRoundTimeLength() override;
	int GetWinfastLength() override;
	CareerDifficultyType GetDifficulty() const override;
	int GetCurrentMapTriplet(MapInfo* maps) override;
	void OnRoundEndMenuOpen(bool didWin) override;
	void OnMatchEndMenuOpen(bool didWin) override;
	void OnRoundEndMenuClose(bool stillPlaying) override;
	void OnMatchEndMenuClose(bool stillPlaying) override;
};
