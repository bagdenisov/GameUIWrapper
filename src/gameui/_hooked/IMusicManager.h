#pragma once
#include "../IMusicManager.h"

class IMusicManager_Hooked : public IMusicManager
{
public:
	void StartTrack(TrackType track, bool looping) override;
	void StopTrack() override;
	void FadeOutTrack() override;
	bool IsPlayingTrack() override;
	bool IsPlayingTrack(TrackType track) override;
};

