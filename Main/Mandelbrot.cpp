//
// Created by zivfreud on 2/14/22.
//

#include "Mandelbrot.h"

Mandelbrot::Mandelbrot(Application& app, Selection& selection) :
m_App(app), m_Selection(selection), m_MaxIterations(100) {
    m_Mat = glm::mat4(0.0f);
}

void Mandelbrot::Update(float dt) {

}

void Mandelbrot::RenderMandelbrot(Renderer2D &renderer) {
    LOG_INFO("Starting rendering the mandelbrot set...");
    std::complex<float> c(0, 0);

    while (c.real() <= (float)m_App.GetWidth()){
        while (c.imag() <= (float)m_App.GetHeight()) {
            int n = Iterate(Transform(c)); //compute the number of iterations
            if (n < m_MaxIterations) {
                //color
                float hue = 360.0f * ((float) n) / ((float) m_MaxIterations);
                float value = 1;
                glm::vec3 rgb = hsv2rgb({hue, 1.0, value});

                Vertex vertex{glm::vec2(c.real(), c.imag()), glm::vec4(rgb.x, rgb.y, rgb.z, 1.0)};
                renderer.SetColor(vertex.color);
                renderer.AddPoint(vertex.position);
            }
            c = {c.real(), c.imag() + 1.0f}; //update c
        }
        c = {c.real() + 1.0f, 0.0f};
    }

    LOG_INFO("Finished rendering mandelbrot set!");
}

void Mandelbrot::Render(Renderer2D &renderer) {
    if (m_Mat == glm::mat4(0.0f)) {
        m_Mat = glm::translate(renderer.GetProjectionMatrix(), glm::vec3((float) -m_App.GetWidth() / 4, 0.0f, 0.0f));
        RenderMandelbrot(renderer);
    }
    if (Input::IsKeyDown(Key::Space) && m_Selection.Selected()) {

        //Update the projection
        m_MatStack.push(m_Mat);
        glm::vec4 selection = m_Selection.GetSelection(); //{x, y, width, height}
        m_Mat = glm::translate(m_Mat, glm::vec3(selection.x, selection.y, 0.0));
        m_Mat = glm::scale(m_Mat, glm::vec3(selection.z/m_App.GetWidth(), selection.w/m_App.GetHeight(), 1.0));

        m_Selection.UnSelect();

        //Render mandelbrot
        renderer.FlushPoints();
        RenderMandelbrot(renderer);
    }
    if (Input::IsKeyDown(Key::B) && !m_MatStack.empty()){
        m_Mat = m_MatStack.top();
        m_MatStack.pop();

        //Render mandelbrot
        renderer.FlushPoints();
        RenderMandelbrot(renderer);
    }
    if (Input::IsKeyDown(Key::R) && !m_MatStack.empty()){
        while (m_MatStack.size() > 1)
            m_MatStack.pop();
        m_Mat = m_MatStack.top();

        //Render mandelbrot
        renderer.FlushPoints();
        RenderMandelbrot(renderer);
    }
    if (Input::IsKeyDown(Key::Q))
        m_App.Terminate();
    renderer.RenderPoints();
}

int Mandelbrot::Iterate(std::complex<float> c) const {
    int i = 0;
    std::complex<float> z = 0.0f;
    while (z.real()*z.real() + z.imag()*z.imag() < 4 && i < m_MaxIterations){
        z = z*z + c;
        i++;
    }
    return i;
}

//See: https://stackoverflow.com/questions/3018313/algorithm-to-convert-rgb-to-hsv-and-hsv-to-rgb-in-range-0-255-for-both
glm::vec3 Mandelbrot::hsv2rgb(glm::vec3 in)
{
    double      hh, p, q, t, ff;
    long        i;
    glm::vec3         out;

    if(in.y <= 0.0) {       // < is bogus, just shuts up warnings
        out.x = in.z;
        out.y = in.z;
        out.z = in.z;
        return out;
    }
    hh = in.x;
    if(hh >= 360.0) hh = 0.0;
    hh /= 60.0;
    i = (long)hh;
    ff = hh - (double)i;
    p = in.z * (1.0 - in.y);
    q = in.z * (1.0 - (in.y * ff));
    t = in.z * (1.0 - (in.y * (1.0 - ff)));

    switch(i) {
        case 0:
            out.x = in.z;
            out.y = (float)t;
            out.z = (float)p;
            break;
        case 1:
            out.x = (float)q;
            out.y = in.z;
            out.z = (float)p;
            break;
        case 2:
            out.x = (float)p;
            out.y = in.z;
            out.z = (float)t;
            break;

        case 3:
            out.x = (float)p;
            out.y = (float)q;
            out.z = in.z;
            break;
        case 4:
            out.x = (float)t;
            out.y = (float)p;
            out.z = in.z;
            break;
        case 5:
        default:
            out.x = in.z;
            out.y = (float)p;
            out.z = (float)q;
            break;
    }
    return out;
}

std::complex<float> Mandelbrot::Transform(std::complex<float> num) const{

    glm::vec4 vec = {num.real(), num.imag(), 0.0f, 1.0f};
    glm::vec4 transformed = m_Mat*vec;
    return {transformed.x, transformed.y};
}

