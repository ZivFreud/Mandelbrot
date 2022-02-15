//
// Created by zivfreud on 10/18/21.
//

#include "Input.h"

bool Input::s_Keys[];
GLFWwindow* Input::s_Window;

void Input::Init(GLFWwindow *window) {
    s_Window = window;
}

void Input::Update() {
    for (int i = MIN_KEY_CODE; i < MAX_KEY_CODE; i++){
        s_Keys[i] = glfwGetKey(s_Window, i) != GLFW_PRESS;
    }
}

bool Input::IsKeyDown(KeyCode key) {
    return !s_Keys[key];
}

bool Input::IsKeyUp(KeyCode key) {
    return s_Keys[key];
}

#include "Core/Log.h"

glm::vec2 Input::GetCursorPosition() {
    double xpos, ypos;

    int height;
    glfwGetWindowSize(s_Window, nullptr, &height);
    glfwGetCursorPos(s_Window, &xpos, &ypos);
    return {xpos, height-ypos};
}

bool Input::IsMouseDown() {
    return glfwGetMouseButton(s_Window, GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;
}

