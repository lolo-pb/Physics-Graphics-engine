#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <iostream>
#include <vector>
#include <string.h>

const uint32_t WIN_HEIGHT = 720;
const uint32_t WIN_WIDTH = 1280;
const char* WIN_NAME = "engine-window";

void initWindow(GLFWwindow* window);
void cleanup(VkInstance instance, GLFWwindow* window);

int main() {

// Window setup
   GLFWwindow* win;
   initWindow(win);



  uint32_t extCount = 0;
  const char** ext = glfwGetRequiredInstanceExtensions(&extCount);
  std::vector<const char*> exts(ext, ext + extCount);

  VkApplicationInfo app = {
      .sType = VK_STRUCTURE_TYPE_APPLICATION_INFO,
      .pApplicationName = "engine",
      .applicationVersion = VK_MAKE_VERSION(0,1,0),
      .pEngineName = "engine",
      .engineVersion = VK_MAKE_VERSION(0,1,0),
      .apiVersion = VK_API_VERSION_1_2,
  };

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

// Main loop
  while (!glfwWindowShouldClose(win)) { 
      glfwPollEvents(); 
  }

// Cleanup / Exit
  cleanup(instance, win);

  return 0;
}


void initWindow(GLFWwindow* window) {
    if (!glfwInit()) { std::cerr << "GLFW init failed\n"; return 1; }

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, WIN_NAME, nullptr, nullptr);
    if (!window) { std::cerr << "Window create failed\n"; glfwTerminate(); return 1; }
}

void initVulkan() {
    creayeInstance();
}

void createInstance() {
    VkApplicationInfo appInfo = { 
        .sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
        .pApplicationName = "Hello Triangle",
        .applicationVersion = VK_MAKE_VERSION(1, 0, 0),
        .pEngineName = "No Engine",
        .engineVersion = VK_MAKE_VERSION(1, 0, 0),
        .apiVersion = vkApiVersion14 
    };
}

void cleanup(VkInstance instance, GLFWwindow* window) {
    vkDestroyInstance(instance, nullptr);
    glfwDestroyWindow(window);
    glfwTerminate();
}

void initVulkan() {
    
}