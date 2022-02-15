//
// Created by zivfreud on 2/4/22.
//


#include "Window.h"

Window::Window(int width, int height, const char* title) : m_Width(width), m_Height(height), m_Title(title), m_Window(nullptr){}

void Window::Init() {

    m_Window = glfwCreateWindow(m_Width, m_Height, m_Title, nullptr, nullptr);
    if (m_Window == nullptr)
        LOG_CRITICAL("Window Init Failed!");
    glfwMakeContextCurrent(m_Window);
}


void Window::SwapBuffers() {
    glfwSwapBuffers(m_Window);
}

bool Window::ShouldClose() {
    return glfwWindowShouldClose(m_Window);
}

GLFWwindow *Window::GetGLFWwindow() {
    return m_Window;
}
