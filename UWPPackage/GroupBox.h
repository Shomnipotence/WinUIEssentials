#pragma once

#include "GroupBox.g.h"
#include "TemplateControlHelper.hpp"

namespace winrt::UWPPackage::implementation
{
    struct GroupBox : GroupBoxT<GroupBox>, TemplateControlHelper<GroupBox>
    {
        GroupBox() = default;

        winrt::hstring Header();
        void Header(winrt::hstring value);

    private:
        winrt::hstring m_header;
    };
}

namespace winrt::UWPPackage::factory_implementation
{
    struct GroupBox : GroupBoxT<GroupBox, implementation::GroupBox>
    {
    };
}
