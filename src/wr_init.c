#include "internal.h"


GLFWbool _glfwConnectWebrogue(int platformID, _GLFWplatform* platform)
{
    const _GLFWplatform wr =
    {
        .platformID = GLFW_PLATFORM_WEBROGUE,
        .init = _glfwInitNull,
        .terminate = _glfwTerminateNull,
        .getCursorPos = _glfwGetCursorPosNull,
        .setCursorPos = _glfwSetCursorPosNull,
        .setCursorMode = _glfwSetCursorModeNull,
        .setRawMouseMotion = _glfwSetRawMouseMotionNull,
        .rawMouseMotionSupported = _glfwRawMouseMotionSupportedNull,
        .createCursor = _glfwCreateCursorNull,
        .createStandardCursor = _glfwCreateStandardCursorNull,
        .destroyCursor = _glfwDestroyCursorNull,
        .setCursor = _glfwSetCursorNull,
        .getScancodeName = _glfwGetScancodeNameNull,
        .getKeyScancode = _glfwGetKeyScancodeNull,
        .setClipboardString = _glfwSetClipboardStringNull,
        .getClipboardString = _glfwGetClipboardStringNull,
        .initJoysticks = _glfwInitJoysticksNull,
        .terminateJoysticks = _glfwTerminateJoysticksNull,
        .pollJoystick = _glfwPollJoystickNull,
        .getMappingName = _glfwGetMappingNameNull,
        .updateGamepadGUID = _glfwUpdateGamepadGUIDNull,
        .freeMonitor = _glfwFreeMonitorNull,
        .getMonitorPos = _glfwGetMonitorPosNull,
        .getMonitorContentScale = _glfwGetMonitorContentScaleNull,
        .getMonitorWorkarea = _glfwGetMonitorWorkareaNull,
        .getVideoModes = _glfwGetVideoModesNull,
        .getVideoMode = _glfwGetVideoModeNull,
        .getGammaRamp = _glfwGetGammaRampNull,
        .setGammaRamp = _glfwSetGammaRampNull,
        .createWindow = _glfwCreateWindowWebrogue,
        .destroyWindow = _glfwDestroyWindowNull,
        .setWindowTitle = _glfwSetWindowTitleNull,
        .setWindowIcon = _glfwSetWindowIconNull,
        .getWindowPos = _glfwGetWindowPosNull,
        .setWindowPos = _glfwSetWindowPosNull,
        .getWindowSize = _glfwGetWindowSizeWebrogue,
        .setWindowSize = _glfwSetWindowSizeNull,
        .setWindowSizeLimits = _glfwSetWindowSizeLimitsNull,
        .setWindowAspectRatio = _glfwSetWindowAspectRatioNull,
        .getFramebufferSize = _glfwGetFramebufferSizeWebrogue,
        .getWindowFrameSize = _glfwGetWindowFrameSizeNull,
        .getWindowContentScale = _glfwGetWindowContentScaleNull,
        .iconifyWindow = _glfwIconifyWindowNull,
        .restoreWindow = _glfwRestoreWindowNull,
        .maximizeWindow = _glfwMaximizeWindowNull,
        .showWindow = _glfwShowWindowNull,
        .hideWindow = _glfwHideWindowNull,
        .requestWindowAttention = _glfwRequestWindowAttentionNull,
        .focusWindow = _glfwFocusWindowNull,
        .setWindowMonitor = _glfwSetWindowMonitorNull,
        .windowFocused = _glfwWindowFocusedNull,
        .windowIconified = _glfwWindowIconifiedNull,
        .windowVisible = _glfwWindowVisibleNull,
        .windowMaximized = _glfwWindowMaximizedNull,
        .windowHovered = _glfwWindowHoveredNull,
        .framebufferTransparent = _glfwFramebufferTransparentNull,
        .getWindowOpacity = _glfwGetWindowOpacityNull,
        .setWindowResizable = _glfwSetWindowResizableNull,
        .setWindowDecorated = _glfwSetWindowDecoratedNull,
        .setWindowFloating = _glfwSetWindowFloatingNull,
        .setWindowOpacity = _glfwSetWindowOpacityNull,
        .setWindowMousePassthrough = _glfwSetWindowMousePassthroughNull,
        .pollEvents = _glfwPollEventsNull,
        .waitEvents = _glfwWaitEventsNull,
        .waitEventsTimeout = _glfwWaitEventsTimeoutNull,
        .postEmptyEvent = _glfwPostEmptyEventNull,
        .getEGLPlatform = _glfwGetEGLPlatformNull,
        .getEGLNativeDisplay = _glfwGetEGLNativeDisplayNull,
        .getEGLNativeWindow = _glfwGetEGLNativeWindowNull,
        .getRequiredInstanceExtensions = _glfwGetRequiredInstanceExtensionsNull,
        .getPhysicalDevicePresentationSupport = _glfwGetPhysicalDevicePresentationSupportNull,
        .createWindowSurface = _glfwCreateWindowSurfaceNull
    };

    *platform = wr;
    return GLFW_TRUE;
}