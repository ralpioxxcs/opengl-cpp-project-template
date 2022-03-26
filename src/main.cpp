//#include "common.h"

/* Ask for an OpenGL Core Context */
#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>

#include <iostream>

//static void OnErrorCallback(int errorCode, const char* errorDescription) {
//  std::cerr << "Error : " << errorDescription << std::endl;
//}

//static void OnKeyCallback(GLFWwindow* wnd, int key, int scancode, int action, int mods) {
//  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
//    glfwSetWindowShouldClose(wnd, GLFW_TRUE);
//  }
//}

//static void OnFramebufferSizeCallback(GLFWwindow* window, int width, int height) {
//  glViewport(0, 0, width, height);
//}

int main(int argc, char* argv[]) {
  GLFWwindow* window;

  if (!glfwInit()) {
    const char* desc = nullptr;
    glfwGetError(&desc);
    std::cerr << "Error: failed to initialize GLFW (" << desc << ")" << std::endl;
    return -1;
  }

#ifdef __APPLE__
  /* We need to explicitly ask for a 3.2 context on OS X */
  glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 2);
  glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
  glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

  const int wndWidth = 800;
  const int wndHeight = 600;
  const char* wndName = "window";

  window = glfwCreateWindow(wndWidth, wndHeight, wndName, nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    return -1;
  }
  glfwMakeContextCurrent(window);  // GLFW가 현재 window을 main context로 만들도록 함

  //OnFramebufferSizeCallback(window, wndWidth, wndHeight);
  //glfwSetFramebufferSizeCallback(window, OnFramebufferSizeCallback);
  //glfwSetKeyCallback(window, OnKeyCallback);
  //glfwSetErrorCallback(OnErrorCallback);

  //std::cout << "OpenGL version : " << glGetString(GL_VERSION) << std::endl;
  //std::cout << "GLSL version : " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
  //std::cout << "Vendor : " << glGetString(GL_VENDOR) << std::endl;
  //std::cout << "Renderer : " << glGetString(GL_RENDER) << std::endl;

  while (!glfwWindowShouldClose(window)) {
    //glClearColor(0.1f, 0.2f, 0.3f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the buffers
    glfwSwapBuffers(window);
    glfwPollEvents();
  }

  glfwTerminate();
  return 0;
}
