# ToastHelper
Helper for creating toast notifications.

## ToastTemplates --- *namespace `ToastTemplates`*

The [built-in templates](https://learn.microsoft.com/en-us/uwp/api/windows.ui.notifications.toasttemplatetype?view=winrt-22621) re-written to classes that derived from `winrt::Windows::UI::Notification::ToastNotification`, so that you can directly use them as arguments for`winrt::Windows::UI::Notifications::ToastNotificationManager`. Example usage:
```cpp
winrt::Windows::UI::Notifications::ToastNotificationManager::CreateToastNotifier()
    .Show(ToastTemplates::ImageWithHeaderAndBody{ L"ms-appx:///Assets/Windows 11.png", L"Header", L"body" });
```

|Type|Template|Sample|
|--|--|--|
|`BodyTextOnly`|ToastText01|
|`SingleLineHeaderWithBody`|ToastText02|
|`TwoLineHeaderWithBody`|ToastText03|
|`HeaderWithTwoSingleLineBody`|ToastText04|
|`ImageWithBodyOnly`|ToastImageAndText01|
|`ImageWithHeaderAndBody`|ToastImageAndText02|
|`ImageWithTwoLineHeaderAndBody`|ToastImageAndText03|
|`ImageWithHeaderAndTwoSingleLineBody`|ToastImageAndText04|

## ToastBuilder