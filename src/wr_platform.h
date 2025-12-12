#include <webroguegfx/webroguegfx.h>

typedef VkFlags VkSurfaceCreateFlagsWEBROGUE;
typedef struct VkSurfaceCreateInfoWEBROGUE {
    VkStructureType                 sType;
    const void*                     pNext;
    VkSurfaceCreateFlagsWEBROGUE    flags;
    const void*                     window;
} VkSurfaceCreateInfoWEBROGUE;

typedef VkResult (APIENTRY *PFN_vkCreateSurfaceWEBROGUE)(VkInstance instance, const VkSurfaceCreateInfoWEBROGUE* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

#define GLFW_WEBROGUE_WINDOW_STATE         _GLFWwindowWebrogue  wr;
// Webrogue-specific per-window data
//
typedef struct _GLFWwindowWebrogue
{
    wr_window handle;
} _GLFWwindowWebrogue;

GLFWbool _glfwConnectWebrogue(int platformID, _GLFWplatform* platform);
GLFWbool _glfwCreateWindowWebrogue(_GLFWwindow* window, const _GLFWwndconfig* wndconfig, const _GLFWctxconfig* ctxconfig, const _GLFWfbconfig* fbconfig);
VkResult _glfwCreateWindowSurfaceWebrogue(VkInstance instance, _GLFWwindow* window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface);
void _glfwGetFramebufferSizeWebrogue(_GLFWwindow *window, int *width,
                                     int *height);
void _glfwGetWindowSizeWebrogue(_GLFWwindow *window, int *width,
                                     int *height);
void _glfwGetRequiredInstanceExtensionsWebrogue(char** extensions);
EGLNativeWindowType _glfwGetEGLNativeWindowWebrogue(_GLFWwindow* window);
EGLNativeDisplayType _glfwGetEGLNativeDisplayWebrogue(void);
void _glfwPollEventsWebrogue(void);
void _glfwWaitEventsWebrogue(void);
void _glfwWaitEventsTimeoutWebrogue(double timeout);
