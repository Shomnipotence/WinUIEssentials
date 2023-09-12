# WinUI Essentials
A repo dedicated for simplifying C++ development with WinUI2 (Universal Windows Platform) and WinUI3 (Windows App SDK).

## Usage
The repo should be organized with features separated to individual folders, each with a UWP version and a WinUI3 version (if possible to implement), a `README`, and their respective example project.
For example:
```
    ToastHelper\    Helper for creating toast notifications
        UWP\        UWP helper
        WinUI3\     WinUI3 helper
        example\
            UWP\    UWP example
            WinUI3\ WinUI3 example
    ... others
```
Most of these helpers should be header only, so you can **copy-paste into your project,** OR clone this repo and then add to your project.

It should be useful until the [community toolkit](https://github.com/CommunityToolkit/WindowsCommunityToolkit) provides C++.
## Content
- ToastHelper: Helper for creating toast notifications, with strong typing
