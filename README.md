# WinUI Essentials
A repo dedicated for simplifying C++ development with WinUI2 (Universal Windows Platform) and WinUI3 (Windows App SDK).

## Usage
> [!WARNING]
> Make sure to set your C++ language version to C++20 first!

Open the `WinUIEssential.sln` containing 4 projects:
- UWPPackage (project for WinUIEssential.UWP nuget package)
- UWPExample (example gallery for using the above package)
- WinUI3Package (project for WinUIEssential.WinUI3 nuget package)
- WinUI3Example (example gallery for using the above package)

Build the `*Package` project will build the project and pack it with nuget, then install the nuget to your project and start using it.

> [!NOTE]
> Functionalities for UWP and WinUI3 should be exactly the same unless otherwise noted!

It should be useful until the [community toolkit](https://github.com/CommunityToolkit/WindowsCommunityToolkit) provides C++.

## Content
|Component|UWP|WinUI3|Type
|--|--|--|--|
|WinUIIncludes| :white_check_mark: | :x: | Header only
|TemplateControlHelper| :white_check_mark: | :white_check_mark: | Header only
|Glyphs| :white_check_mark: | :white_check_mark: | Header only + Xaml only
|BadgeGlyphs| :white_check_mark: | :white_check_mark: | Header only
|ToastTemplates| :white_check_mark: | :white_check_mark: | Header only
|ToastBuilder | :white_check_mark: | :white_check_mark: | Header only
|SettingsExpander |  |  | WinRT component
|CursorController | :white_check_mark: | :white_check_mark: | WinRT component
|PropertyChangeHelper | :white_check_mark: | :white_check_mark: | Header only
|NegateBoolConverter | :white_check_mark: | :white_check_mark: | WinRT component
|BoolToVisibilityConverter | :white_check_mark: | :white_check_mark: | WinRT component
|ContainerToBoolConverter | :white_check_mark: | :white_check_mark: | WinRT component
|StringToBoolConverter | :white_check_mark: | :white_check_mark: | WinRT component
|ReferenceToBoolConverter | :white_check_mark: | :white_check_mark: | WinRT component
|ConverterGroup | :white_check_mark: | :white_check_mark: | WinRT component
|IsEqualStateTrigger| :white_check_mark: | :white_check_mark: | WinRT component
|IsNullOrEmptyStateTrigger | :white_check_mark: | :white_check_mark: | WinRT component
|ControlSizeTrigger | :white_check_mark: | :white_check_mark: | WinRT component
|GroupBox | :white_check_mark: | :white_check_mark: | Control

*means additional settings required, see the sections for info

---
## ToastHelper
Helper for creating toast notifications.

### ToastTemplates --- *namespace `ToastTemplates`*
The [built-in templates](https://learn.microsoft.com/en-us/uwp/api/windows.ui.notifications.toasttemplatetype?view=winrt-22621) re-written to strongly-typed classes that derived from `winrt::Windows::UI::Notification::ToastNotification`, so that you can directly use them as arguments for`winrt::Windows::UI::Notifications::ToastNotificationManager`. Example usage:
```cpp
#include <ToastTemplates.hpp>
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

### ToastBuilder --- *namespace `ToastBuilder`*
Strongly-typed, declarative toast notification elements to quickly build toast notifications, as if you are writing XAML. [Schema here.](https://learn.microsoft.com/en-us/uwp/schemas/tiles/toastschema/root-elements) 
Example usage:
<table>
<tr>
    <td>XML</td> <td>C++</td>
<tr>
<tr>
<td>

```xml
<toast duration="long" scenario="reminder" useButtonStyle="true">
    <visual>
        <binding template="ToastText04">
            <text id="1">headline</text>
            <text id="2">body text1</text>
            <text id="3">body text2</text>
        </binding>
    </visual>
    <actions>
        <action content="Accept" arguments="accept"/>
    </actions>
</toast>
```
</td>
<td>

```cpp
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
```

</td>
</tr>
<tr>
<td>

`<tag>...content...</tag>`

</td>
<td>

`Tag()(...content...)`

</td>
</tr>
<tr>
<td>

`attribute="value"`

</td>
<td>

`.Attribute(value)`

</td>
</tr>
<table>

## Glphys --- *namespace `Glyphs`*
Font glyphs value for Segoe MDL2 Assets fonts.

## CursorController --- *namespace `CursorController`*
Xaml helper for controlling the cursor type when mouse enters. 
Value for `Type` is [CoreCursorType enum](https://learn.microsoft.com/en-us/uwp/api/windows.ui.core.corecursortype?view=winrt-22621). Usage:
```xml
xmlns:essential="using:WinUI3Package"
...
<Rectangle Fill="Red" essential:CursorController.Type="Hand"/>
```

## PropertyChangeHelper --- *namespace `MvvmHelper`*
Helper for `OneWay` binding.

Usage: 
1. Inherit `Windows.UI.Xaml.Data.INotifyPropertyChanged` in `idl`
```
[default_interface]
runtimeclass MyPage : Windows.UI.Xaml.Controls.Page, Windows.UI.Xaml.Data.INotifyPropertyChanged
{
    ...
};
```

2. Inherit from this class in the implementation class.
```cpp
/*MyPage.xaml.h*/
#include <include/PropertyChangeHelper.hpp>

namespace winrt::<MyProject>::implementation
{
    struct MyPage : MyMusicT<MyMusic>, MvvmHelper::PropertyChangeHelper<MyMusic>
    {
        int m_value;
        void Value(int newValue)
        {
            compareAndRaise(m_value, newValue, L"Value");
        };
    }
}
```

## Converters
- bool -> Visibility *namespace `BoolToVisibilityConverter`*
- bool negation *namespace `NegateBoolConverter`*
- container (IVector, IMap) -> bool *namespace `ContainerToBoolConverter`*
- reference (any WinRT runtime type) -> bool *namespace `ReferenceToBoolConverter`*
- String -> bool *namespace `StringToBoolConverter`*
- ConverterGroups *namespace `ConverterGroups`*:
  + define series of converters, that convert value from converter1 -> converter2 -> ...
  + usage:
  ```xml
   <essential:ConverterGroup x:Key="StringToVisibilityConverter">
       <essential:StringToBoolConverter/>
       <essential:BoolToVisibilityConverter/>
   </essential:ConverterGroup>
  ```

## BadgeGlyphs --- *namespace `BadgeGlyphs`*
Helpers for creating badge notification xml.
Usage:
```cpp
#include <include/BadgeGlyphs.hpp>

//glyph badge
winrt::Windows::UI::Notifications::BadgeUpdateManager::CreateBadgeUpdaterForApplication()
	.Update(BadgeGlyphs::MakeBadgeNotification(BadgeGlyphs::Alert));

//number badge
winrt::Windows::UI::Notifications::BadgeUpdateManager::CreateBadgeUpdaterForApplication()
	.Update(BadgeGlyphs::MakeBadgeNotification(1));
```

## Triggers
See the same class in [Community Toolkit](https://github.com/CommunityToolkit/Windows) for documentation.
### ControlSizeTrigger --- *namespace `ControlSizeTrigger`*
### IsEqualStateTrigger --- *namespace `IsEqualStateTrigger`*
### IsNullOrEmptyStateTrigger --- *namespace `IsNullOrEmptyStateTrigger`*