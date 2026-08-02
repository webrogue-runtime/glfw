#include "internal.h"
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


void _glfwGetRequiredInstanceExtensionsWebrogue(char** extensions)
{
    if (!_glfw.vk.KHR_surface || !_glfw.vk.WEBROGUE_surface)
        return;

    extensions[0] = "VK_KHR_surface";
    extensions[1] = "VK_WEBROGUE_surface";
}

static _GLFWwindow **wrWindows = NULL;
static int wrWindowsCount = 0;

VkResult _glfwCreateWindowSurfaceWebrogue(VkInstance instance, _GLFWwindow* window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface) {
  VkSurfaceCreateInfoWEBROGUE sci;
  PFN_vkCreateSurfaceWEBROGUE vkCreateSurfaceWEBROGUE;

  vkCreateSurfaceWEBROGUE = (PFN_vkCreateSurfaceWEBROGUE)
      vkGetInstanceProcAddr(instance, "vkCreateSurfaceWEBROGUE");

  memset(&sci, 0, sizeof(VkSurfaceCreateInfoWEBROGUE));
  sci.sType = VK_STRUCTURE_TYPE_SURFACE_CREATE_INFO_WEBROGUE;
  sci.webrogue_window_id = webroguegfx_get_vulkan_window_id(window->wr.handle);
  return vkCreateSurfaceWEBROGUE(instance, &sci, allocator, surface);
}

static GLFWglproc APIENTRY static_eglGetProcAddress(const char*) __attribute__ ((weakref ("eglGetProcAddress")));

GLFWbool _glfwCreateWindowWebrogue(_GLFWwindow *window,
                                   const _GLFWwndconfig *wndconfig,
                                   const _GLFWctxconfig *ctxconfig,
                                   const _GLFWfbconfig *fbconfig) {
    webroguegfx_make_window(&window->wr.handle);

    if (ctxconfig->client != GLFW_NO_API)
    {
        if (ctxconfig->source == GLFW_EGL_CONTEXT_API ||
            ctxconfig->source == GLFW_NATIVE_CONTEXT_API)
        {
            if (!window->wr.handle)
            {
                _glfwInputError(GLFW_PLATFORM_ERROR,
                                "Webrogue: Failed to create Webrogue window");
                return GLFW_FALSE;
            }

            if (!static_eglGetProcAddress)
            {
                _glfwInputError(GLFW_PLATFORM_ERROR,
                                "Webrogue: eglGetProcAddress function not found. You probably forgot -Wl,--export=eglGetProcAddress or -lEGL flag.");
                return GLFW_FALSE;
            }
            _glfw.egl.GetProcAddress = static_eglGetProcAddress;
            if (!_glfwInitEGL())
                return GLFW_FALSE;
            if (!_glfwCreateContextEGL(window, ctxconfig, fbconfig))
                return GLFW_FALSE;
        }

        if (!_glfwRefreshContextAttribs(window, ctxconfig))
            return GLFW_FALSE;
    }

    if(wrWindowsCount == 0) {
        wrWindows = malloc(sizeof(_GLFWwindow*));
    } else {
        wrWindows = realloc(wrWindows, (wrWindowsCount + 1) * sizeof(_GLFWwindow*));
    }
    wrWindows[wrWindowsCount++] = window;
    return GLFW_TRUE;
}

void _glfwGetFramebufferSizeWebrogue(_GLFWwindow *window, int *width,
                                     int *height) {
  webroguegfx_gl_size(window->wr.handle, width, height);
}
void _glfwGetWindowSizeWebrogue(_GLFWwindow *window, int *width, int *height) {
  webroguegfx_window_size(window->wr.handle, width, height);
}

EGLNativeWindowType _glfwGetEGLNativeWindowWebrogue(_GLFWwindow* window)
{
    return window->wr.handle;
}

EGLNativeDisplayType _glfwGetEGLNativeDisplayWebrogue(void)
{
    return EGL_DEFAULT_DISPLAY;
}

static void handleEvents(double* timeout)
{
    while(1) {
        webrogue_event event = webroguegfx_poll();
        switch (event.type) {
            case WEBROGUE_EVENT_TYPE_INVALID:
                return;
            case WEBROGUE_EVENT_TYPE_QUIT: {
                for(int i = 0; i < wrWindowsCount; i++)
                    _glfwInputWindowCloseRequest(wrWindows[i]);
                break;
            }
        }
    }
}

void _glfwPollEventsWebrogue(void)
{
    double timeout = 0.0;
    handleEvents(&timeout);
}

void _glfwWaitEventsWebrogue(void)
{
    handleEvents(NULL);
}

void _glfwWaitEventsTimeoutWebrogue(double timeout)
{
    handleEvents(&timeout);
}
