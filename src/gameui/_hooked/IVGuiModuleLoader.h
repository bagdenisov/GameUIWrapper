//========= Copyright © 1996-2005, Valve Corporation, All rights reserved. ============//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//
#pragma once
#include "../IVGuiModuleLoader.h"

class IVGuiModuleLoader_Hooked : public IVGuiModuleLoader
{
public:
	int GetModuleCount() override;
	const char *GetModuleLabel(int moduleIndex) override;
	CreateInterfaceFn GetModuleFactory(int moduleIndex) override;
	bool ActivateModule(int moduleIndex) override;
	bool ActivateModule(const char *moduleName) override;
	void SetPlatformToRestart() override;
};
