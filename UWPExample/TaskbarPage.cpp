#include "pch.h"
#include "TaskbarPage.h"
#if __has_include("TaskbarPage.g.cpp")
#include "TaskbarPage.g.cpp"
#endif
#include <Taskbar.h>
#include <winrt/Windows.UI.Core.h>
#include <WindowHelper.hpp>

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UWPExample::implementation
{
	void TaskbarPage::ComboBox_SelectionChanged(
		winrt::Windows::Foundation::IInspectable const& sender, 
		winrt::Windows::UI::Xaml::Controls::SelectionChangedEventArgs const& e)
	{
		auto stateStr = winrt::unbox_value<winrt::hstring>(sender.as<winrt::Windows::UI::Xaml::Controls::ComboBox>().SelectedItem());
		Taskbar::ProgressState state;
		if (stateStr == L"NoProgress") state = Taskbar::ProgressState::NoProgress;
		else if (stateStr == L"Indeterminate") state = Taskbar::ProgressState::Indeterminate;
		else if (stateStr == L"Normal") state = Taskbar::ProgressState::Normal;
		else if (stateStr == L"Error") state = Taskbar::ProgressState::Error;
		else if (stateStr == L"Paused") state = Taskbar::ProgressState::Paused;

		auto hwnd = GetHwnd(winrt::Windows::UI::Core::CoreWindow::GetForCurrentThread());
		Taskbar::SetProgressState(hwnd, state);
		Taskbar::SetProgressValue(hwnd, 50);
	}

}
