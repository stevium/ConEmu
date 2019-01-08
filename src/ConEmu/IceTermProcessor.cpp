#include "Inside.h"
#include "IceTermProcessor.h"

IceTermProcessor::IceTermProcessor(CConEmuMain *gpConEmu)
{
	this->mp_ConEmu = gpConEmu;
}

bool IceTermProcessor::execute(std::wstring const& cmd) {
	std::wstring command = cmd.substr(0, cmd.find(_T(" ")));
	std::wstring args = cmd.substr(cmd.find(_T(" ")));
	 
	switch (hashIceTermCmd(command))
	{
	case SWITCH_WINDOW: 
		HWND hParent = (HWND)(DWORD_PTR)wcstoul(args.c_str(), NULL, 16);
		return switchWindow(hParent);
	case UNDEFINED:
	default:
		return false;
	}
}

bool IceTermProcessor::switchWindow(HWND hParent) {
	if (hParent && IsWindow(hParent)) {
		mp_ConEmu->SetParent(hParent);
		mp_ConEmu->mp_Inside->InitInside(false, false, NULL, 0, hParent);
		return true;
	}
	return false;
}

IceTermCmds IceTermProcessor::hashIceTermCmd(std::wstring const& inString) {
	if (wcscmp(inString.c_str(), _T("Switch-Window")) == 0) return SWITCH_WINDOW;
	else return UNDEFINED;
}
