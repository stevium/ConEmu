#pragma once

#include <string>
#include "ConEmu.h"

enum IceTermCmds {
    SWITCH_WINDOW,
    UNDEFINED,
};

class IceTermProcessor
{
public:
	IceTermProcessor(CConEmuMain *gpConEmu);
	bool execute(const std::wstring &cmd);
	bool switchWindow(HWND handle);

private: 
	CConEmuMain* mp_ConEmu;
	IceTermCmds hashIceTermCmd(std::wstring const& inString);
};

