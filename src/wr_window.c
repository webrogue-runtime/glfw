#include "internal.h"
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <webrogue_gfx/webrogue_gfx.h>


static void makeContextCurrentWebrogue(_GLFWwindow* window)
{
    _glfwPlatformSetTls(&_glfw.contextSlot, window);
}


static void swapBuffersWebrogue(_GLFWwindow* window)
{
    if (window != _glfwPlatformGetTls(&_glfw.contextSlot))
    {
        _glfwInputError(GLFW_PLATFORM_ERROR,
                        "EGL: The context must be current on the calling thread when swapping buffers");
        return;
    }
    webrogue_gfx_present();
    // swap
}



static void swapIntervalWebrogue(int interval)
{
}

static int extensionSupportedWebrogue(const char* extension)
{
    return GLFW_FALSE;
}

void* webrogueGLLoader(const char* procname);

static GLFWglproc getProcAddressWebrogue(const char* procname)
{
    _GLFWwindow* window = _glfwPlatformGetTls(&_glfw.contextSlot);
    assert(window != NULL);

    return (GLFWglproc) webrogueGLLoader(procname);
}

static void destroyContextWebrogue(_GLFWwindow* window)
{

}

// Create the OpenGL or OpenGL ES context
//
GLFWbool _glfwCreateContextWebrogue(_GLFWwindow* window,
                               const _GLFWctxconfig* ctxconfig,
                               const _GLFWfbconfig* fbconfig)
{
    webrogue_gfx_make_window();
    
    window->context.client = GLFW_OPENGL_ES_API;
    window->context.makeCurrent = makeContextCurrentWebrogue;
    window->context.swapBuffers = swapBuffersWebrogue;
    window->context.swapInterval = swapIntervalWebrogue;
    window->context.extensionSupported = extensionSupportedWebrogue;
    window->context.getProcAddress = getProcAddressWebrogue;
    window->context.destroy = destroyContextWebrogue;

    return GLFW_TRUE;
}

GLFWbool _glfwCreateWindowWebrogue(_GLFWwindow* window,
                              const _GLFWwndconfig* wndconfig,
                              const _GLFWctxconfig* ctxconfig,
                              const _GLFWfbconfig* fbconfig)
{
    // Visual* visual = NULL;
    // int depth;

    // if (ctxconfig->client != GLFW_NO_API)
    // {
    //     if (ctxconfig->source == GLFW_NATIVE_CONTEXT_API)
    //     {
    //         if (!_glfwInitGLX())
    //             return GLFW_FALSE;
    //         if (!_glfwChooseVisualGLX(wndconfig, ctxconfig, fbconfig, &visual, &depth))
    //             return GLFW_FALSE;
    //     }
    //     else if (ctxconfig->source == GLFW_EGL_CONTEXT_API)
    //     {
    //         if (!_glfwInitEGL())
    //             return GLFW_FALSE;
    //         if (!_glfwChooseVisualEGL(wndconfig, ctxconfig, fbconfig, &visual, &depth))
    //             return GLFW_FALSE;
    //     }
    //     else if (ctxconfig->source == GLFW_OSMESA_CONTEXT_API)
    //     {
    //         if (!_glfwInitOSMesa())
    //             return GLFW_FALSE;
    //     }
    // }

    // if (!visual)
    // {
    //     visual = DefaultVisual(_glfw.x11.display, _glfw.x11.screen);
    //     depth = DefaultDepth(_glfw.x11.display, _glfw.x11.screen);
    // }

    // if (!createNativeWindow(window, wndconfig, visual, depth))
    //     return GLFW_FALSE;

    if (ctxconfig->client != GLFW_NO_API)
    {
        // if (ctxconfig->source == GLFW_NATIVE_CONTEXT_API)
        // {
            if (!_glfwCreateContextWebrogue(window, ctxconfig, fbconfig))
                return GLFW_FALSE;
        // }
        
        if (!_glfwRefreshContextAttribs(window, ctxconfig))
            return GLFW_FALSE;
    }

    // if (wndconfig->mousePassthrough)
    //     _glfwSetWindowMousePassthroughX11(window, GLFW_TRUE);

    // if (window->monitor)
    // {
    //     _glfwShowWindowX11(window);
    //     updateWindowMode(window);
    //     acquireMonitor(window);

    //     if (wndconfig->centerCursor)
    //         _glfwCenterCursorInContentArea(window);
    // }
    // else
    // {
    //     if (wndconfig->visible)
    //     {
    //         _glfwShowWindowX11(window);
    //         if (wndconfig->focused)
    //             _glfwFocusWindowX11(window);
    //     }
    // }

    // XFlush(_glfw.x11.display);
    return GLFW_TRUE;
}

void _glfwGetFramebufferSizeWebrogue(_GLFWwindow* window, int* width, int* height) {
    webrogue_gfx_gl_size(width, height);
}
void _glfwGetWindowSizeWebrogue(_GLFWwindow* window, int* width, int* height) {
    webrogue_gfx_window_size(width, height);
}
