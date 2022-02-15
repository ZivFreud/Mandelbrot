//
// Created by zivfreud on 10/18/21.
//

#ifndef ROTATINGVECTORS_INPUT_H
#define ROTATINGVECTORS_INPUT_H

#include "KeyCodes.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

class Input {
public:
    static void Init(GLFWwindow* window);

    static void Update();
    static bool IsKeyDown(KeyCode key);
    static bool IsKeyUp(KeyCode key);

    static glm::vec2 GetCursorPosition();
    static bool IsMouseDown();

private:
    static bool s_Keys[MAX_KEY_CODE];
    static GLFWwindow* s_Window;
};


#endif //ROTATINGVECTORS_INPUT_H
