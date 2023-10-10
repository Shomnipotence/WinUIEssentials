#include "pch.h"
#include "WindowHelper.hpp"
#include <CoreWindow.h>
#include <winrt/base.h>
#include <winrt/Windows.UI.Core.h>

HWND GetHwnd(winrt::Windows::UI::Core::CoreWindow coreWindow)
{
	winrt::com_ptr<ICoreWindowInterop> interop;
	winrt::check_hresult(winrt::get_unknown(coreWindow)->QueryInterface(interop.put()));
	HWND hwnd;
	winrt::check_hresult(interop->get_WindowHandle(&hwnd));
	return hwnd;
}