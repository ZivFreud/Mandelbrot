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
    void RenderMandelbrot(Renderer2D& renderer);
private:
    int Iterate(std::complex<float> c) const;
    static glm::vec3 hsv2rgb(glm::vec3 hsv);
    std::complex<float> Transform(std::complex<float> num) const;


private:
    Application& m_App;
    Selection& m_Selection;

    std::stack<glm::mat4> m_MatStack;
    glm::mat4 m_Mat{};

    //settings
    unsigned int m_MaxIterations;
};


#endif //MANDELBROT_MANDELBROT_H
