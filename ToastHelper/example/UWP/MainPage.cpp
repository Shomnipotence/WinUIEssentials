#include "pch.h"
#include "MainPage.h"
#include "MainPage.g.cpp"
#include "../../UWP/ToastTemplate.hpp"
#include "../../UWP/ToastBuilder.hpp"
#include <winrt/Windows.UI.Notifications.h>

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::ToastHelper::implementation
{

	void MainPage::BodyTextOnlyBtn_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		winrt::Windows::UI::Notifications::ToastNotificationManager::CreateToastNotifier().Show(ToastTemplates::BodyTextOnly{ L"bodyText" });
	}


	void MainPage::SingleLineHeaderWithBodyBtn_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		winrt::Windows::UI::Notifications::ToastNotificationManager::CreateToastNotifier()
			.Show(ToastTemplates::SingleLineHeaderWithBody{ L"Header", L"Body" });
	}


	void MainPage::TwoLineHeaderWithBodyBtn_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		winrt::Windows::UI::Notifications::ToastNotificationManager::CreateToastNotifier()
			.Show(ToastTemplates::TwoLineHeaderWithBody{ L"Very looooooooooooooooooooooooooong two line header", L"Body" });
	}


	void MainPage::HeaderWithTwoSingleLineBody_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		winrt::Windows::UI::Notifications::ToastNotificationManager::CreateToastNotifier()
			.Show(ToastTemplates::HeaderWithTwoSingleLineBody{ L"Header", L"body#1", L"body#2" });
	}


	void MainPage::ImageWithBodyOnly_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		winrt::Windows::UI::Notifications::ToastNotificationManager::CreateToastNotifier()
			.Show(ToastTemplates::ImageWithBodyOnly{ L"ms-appx:///Assets/Windows 11.png", L"Header" });
	}


	void MainPage::ImageWithHeaderAndBodyBtn_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		winrt::Windows::UI::Notifications::ToastNotificationManager::CreateToastNotifier()
			.Show(ToastTemplates::ImageWithHeaderAndBody{ L"ms-appx:///Assets/Windows 11.png", L"Header", L"body" });
	}


	void MainPage::ImageWithTwoLineHeaderAndBody_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		winrt::Windows::UI::Notifications::ToastNotificationManager::CreateToastNotifier()
			.Show(ToastTemplates::ImageWithTwoLineHeaderAndBody{ L"ms-appx:///Assets/Windows 11.png", L"Very looooooooooooooooooooooooooong two line header", L"body" });
	}


	void MainPage::ImageWithHeaderAndTwoSingleLineBody_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		winrt::Windows::UI::Notifications::ToastNotificationManager::CreateToastNotifier()
			.Show(ToastTemplates::ImageWithHeaderAndTwoSingleLineBody{ L"ms-appx:///Assets/Windows 11.png", L"Header", L"body#1", L"body#2" });
	}


	void MainPage::ToastBuilderBtn_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Windows::UI::Xaml::RoutedEventArgs const& e)
	{
		using namespace ToastBuilder;
		winrt::Windows::UI::Notifications::ToastNotificationManager::CreateToastNotifier()
			.Show(
				Toast().Duration(Long).Scenario(Reminder).UseButtonStyle(true)
				(
					Visual()
					(
						Binding().Template(L"ToastText04")
						(
							Text().Id(1)(L"headline"),
							Text().Id(2)(L"body text1"),
							Text().Id(3)(L"body text2")
							)
						),
					Actions()
					(
						Action().Content(L"Accept").Arguments(L"accept")
					)
				)
			);
	}

}
