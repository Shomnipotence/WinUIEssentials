#pragma once

#include <winrt/base.h>
#include "Export.h"

struct ITaskbarList3;


/**
 * @brief Wrapper for controlling taskbar icon progress
 */
class DLLEXPORT Taskbar
{
	static ITaskbarList3* getPtr();

public:
	enum class ProgressState : unsigned
	{
		NoProgress,
		Indeterminate,
		Normal,
		Error,
		Paused
	};


	/**
	 * @brief Set taskbar icon progress state of a window
	 *
	 * @param hwnd window handle
	 */
	static void SetProgressState(HWND hwnd, ProgressState state);

	/**
	 * @brief Set taskbar icon progress value
	 *
	 * @param hwnd window handle
	 * @param current current value, default to the number of percentage if `maximum` not specified
	 * @param maximum default = `100`'
	 */
	static void SetProgressValue(HWND hwnd, ULONGLONG current, ULONGLONG maximum = 100);
private:
	static constexpr unsigned getRawState(ProgressState state);
};
