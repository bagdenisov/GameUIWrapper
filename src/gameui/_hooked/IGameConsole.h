#pragma once
#include "../IGameConsole.h"

class IGameConsole_Hooked : public IGameConsole
{
public:
	void Activate() override;
	void Initialize() override;
	void Hide() override;
	void Clear() override;
	bool IsConsoleVisible() override;
	void Printf(const char* format, ...) override;
	void DPrintf(const char* format, ...) override;
	void SetParent(unsigned int parent ) override;
	//virtual void SetParent( vgui2::VPANEL parent ) = 0;
};

