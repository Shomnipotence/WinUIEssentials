#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"


using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::UWPExample::implementation
{

	void MainPage::NavigationView_SelectionChanged(
		winrt::Windows::UI::Xaml::Controls::NavigationView const& sender, 
		winrt::Windows::UI::Xaml::Controls::NavigationViewSelectionChangedEventArgs const& args)
	{
		auto tag = args.SelectedItem().as<winrt::Windows::UI::Xaml::Controls::NavigationViewItem>().Tag();
		ContentFrame().Navigate(s_page[winrt::unbox_value<winrt::hstring>(tag)]);
	}

}
