#pragma once
#include <winrt/Windows.UI.Xaml.Data.h>
namespace MvvmHelper
{
	template<typename Self>
	class PropertyChangeHelper
	{
	public:
		winrt::event_token PropertyChanged(winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler const& value)
		{
			return m_propertyChanged.add(value);
		}

		void PropertyChanged(winrt::event_token const& token)
		{
			m_propertyChanged.remove(token);
		}

		void raisePropertyChange(wchar_t const* propertyName)
		{
			m_propertyChanged(*(static_cast<Self*>(this)), winrt::Windows::UI::Xaml::Data::PropertyChangedEventArgs{ propertyName });
		}

		template<typename T>
		void compareAndRaise(auto& property, T&& newValue, wchar_t const* propertyName)
		{
			if (property != newValue)
			{
				property = std::forward<T>(newValue);
				raisePropertyChange(propertyName);
			}
		}
	private:
		winrt::event<winrt::Windows::UI::Xaml::Data::PropertyChangedEventHandler> m_propertyChanged;
	};
}