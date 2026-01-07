#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>

int main() {
  if (!glfwInit()) { std::cerr << "GLFW init failed\n"; return 1; }

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  GLFWwindow* win = glfwCreateWindow(1280, 720, "engine", nullptr, nullptr);
  if (!win) { std::cerr << "Window create failed\n"; glfwTerminate(); return 1; }

  uint32_t extCount = 0;
  const char** ext = glfwGetRequiredInstanceExtensions(&extCount);
  std::vector<const char*> exts(ext, ext + extCount);

  VkApplicationInfo app{ VK_STRUCTURE_TYPE_APPLICATION_INFO };
  app.pApplicationName = "engine";
  app.applicationVersion = VK_MAKE_VERSION(0,1,0);
  app.pEngineName = "engine";
  app.engineVersion = VK_MAKE_VERSION(0,1,0);
  app.apiVersion = VK_API_VERSION_1_2;

  VkInstanceCreateInfo ci{ VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO };
  ci.pApplicationInfo = &app;
  ci.enabledExtensionCount = (uint32_t)exts.size();
  ci.ppEnabledExtensionNames = exts.data();

  VkInstance instance = VK_NULL_HANDLE;
  if (vkCreateInstance(&ci, nullptr, &instance) != VK_SUCCESS) {
    std::cerr << "vkCreateInstance failed\n";
    glfwDestroyWindow(win);
    glfwTerminate();
    return 1;
  }

  std::cout << "Vulkan instance OK\n";
  while (!glfwWindowShouldClose(win)) glfwPollEvents();

  vkDestroyInstance(instance, nullptr);
  glfwDestroyWindow(win);
  glfwTerminate();
  return 0;
}
