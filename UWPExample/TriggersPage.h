#pragma once

#include "TriggersPage.g.h"

namespace winrt::UWPExample::implementation
{
    struct TriggersPage : TriggersPageT<TriggersPage>
    {
        TriggersPage() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }
    };
}

namespace winrt::UWPExample::factory_implementation
{
    struct TriggersPage : TriggersPageT<TriggersPage, implementation::TriggersPage>
    {
    };
}
