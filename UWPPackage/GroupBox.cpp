﻿#include "pch.h"
#include "GroupBox.h"
#if __has_include("GroupBox.g.cpp")
#include "GroupBox.g.cpp"
#endif

namespace winrt::UWPPackage::implementation
{
	winrt::hstring GroupBox::Header()
	{
		return m_header;
	}
	void GroupBox::Header(winrt::hstring value)
	{
		m_header = value;
	}
}
