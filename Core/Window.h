//
// Created by zivfreud on 2/4/22.
//

#ifndef MANDELBROT_WINDOW_H
#define MANDELBROT_WINDOW_H

#include <GLFW/glfw3.h>
#include "Log.h"

class Window {
public:
    Window(int width, int height, const char* title);

    void Init();
    void SwapBuffers();
    bool ShouldClose();

    GLFWwindow* GetGLFWwindow();

private:
    GLFWwindow* m_Window{};

    int m_Width, m_Height;
    const char* m_Title;
};


#endif //MANDELBROT_WINDOW_H
