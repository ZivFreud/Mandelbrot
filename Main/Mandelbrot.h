//
// Created by zivfreud on 2/14/22.
//

#ifndef MANDELBROT_MANDELBROT_H
#define MANDELBROT_MANDELBROT_H

#include "Core/Application.h"
#include "Selection.h"
#include <complex>
#include <stack>

class Mandelbrot : public Entity{
public:
    explicit Mandelbrot(Application& app, Selection& selection);

    void Update(float dt) override;
    void Render(Renderer2D& renderer) override;

private:
    Application& m_App;
    Shader m_Shader;
    VertexArray m_VAO;

    Selection& m_Selection;

    std::stack<glm::mat4> m_MatStack;
    glm::mat4 m_Mat{};

    //settings
    unsigned int m_MaxIterations;
};


#endif //MANDELBROT_MANDELBROT_H
