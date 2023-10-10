#include "pch.h"
#include "Taskbar.h"
#include <ShObjIdl_core.h>
constexpr unsigned Taskbar::getRawState(ProgressState state)
{
	switch (state)
	{
	case Taskbar::ProgressState::NoProgress:
		return TBPF_NOPROGRESS;
	case Taskbar::ProgressState::Indeterminate:
		return TBPF_INDETERMINATE;
	case Taskbar::ProgressState::Normal:
		return TBPF_NORMAL;
	case Taskbar::ProgressState::Error:
		return TBPF_ERROR;
	case Taskbar::ProgressState::Paused:
		return TBPF_PAUSED;
	}
}

ITaskbarList3* Taskbar::getPtr()
{
	static winrt::com_ptr<ITaskbarList3> instance = []
	{
		winrt::com_ptr<ITaskbarList3> ptr;
		CoCreateInstance(CLSID_TaskbarList, nullptr, CLSCTX_ALL, __uuidof(ITaskbarList3), ptr.put_void());
		return ptr;
	}(); 
	return instance.get();
}

void Taskbar::SetProgressState(HWND hwnd, ProgressState state)
{
	getPtr()->SetProgressState(hwnd, static_cast<TBPFLAG>(getRawState(state)));
}

void Taskbar::SetProgressValue(HWND hwnd, ULONGLONG current, ULONGLONG maximum)
{
	getPtr()->SetProgressValue(hwnd, current, maximum);
}