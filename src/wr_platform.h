typedef VkFlags VkSurfaceCreateFlagsWEBROGUE;
typedef struct VkSurfaceCreateInfoWEBROGUE {
    VkStructureType                 sType;
    const void*                     pNext;
    VkSurfaceCreateFlagsWEBROGUE    flags;
} VkSurfaceCreateInfoWEBROGUE;

typedef VkResult (APIENTRY *PFN_vkCreateSurfaceWEBROGUE)(VkInstance instance, const VkSurfaceCreateInfoWEBROGUE* pCreateInfo, const VkAllocationCallbacks* pAllocator, VkSurfaceKHR* pSurface);

GLFWbool _glfwConnectWebrogue(int platformID, _GLFWplatform* platform);
GLFWbool _glfwCreateWindowWebrogue(_GLFWwindow* window, const _GLFWwndconfig* wndconfig, const _GLFWctxconfig* ctxconfig, const _GLFWfbconfig* fbconfig);
VkResult _glfwCreateWindowSurfaceWebrogue(VkInstance instance, _GLFWwindow* window, const VkAllocationCallbacks* allocator, VkSurfaceKHR* surface);
void _glfwGetFramebufferSizeWebrogue(_GLFWwindow *window, int *width,
                                     int *height);
void _glfwGetWindowSizeWebrogue(_GLFWwindow *window, int *width,
                                     int *height);
