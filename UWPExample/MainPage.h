#pragma once

#include "MainPage.g.h"
#include <unordered_map>

namespace winrt::UWPExample::implementation
{
    struct MainPage : MainPageT<MainPage>
    {
        MainPage()
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        void NavigationView_SelectionChanged(
            winrt::Windows::UI::Xaml::Controls::NavigationView const& sender,
            winrt::Windows::UI::Xaml::Controls::NavigationViewSelectionChangedEventArgs const& args);

    private:
        static inline std::unordered_map<winrt::hstring, winrt::Windows::UI::Xaml::Interop::TypeName> s_page
        {
            {L"ToastPage", winrt::xaml_typename<UWPExample::ToastPage>()}
        };
    };
}

namespace winrt::UWPExample::factory_implementation
{
    struct MainPage : MainPageT<MainPage, implementation::MainPage>
    {
    };
}
