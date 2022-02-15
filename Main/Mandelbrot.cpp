//
// Created by zivfreud on 2/14/22.
//

#include "Mandelbrot.h"

Mandelbrot::Mandelbrot(Application& app, Selection& selection) :
m_App(app), m_Selection(selection), m_MaxIterations(300) {
    m_Mat = glm::mat4(1.0f);
    m_Mat = glm::translate(m_Mat, glm::vec3((float)-m_App.GetWidth()/4, 0.0f, 0.0f));
    ResourceManager::LoadShader("Mandelbrot", "Mandelbrot/MandelbrotVertex.glsl", "Mandelbrot/MandelbrotFragment.glsl");

    m_Shader = ResourceManager::GetShader("Mandelbrot");
    m_Shader.SetFloat("maxIterations", (float)m_MaxIterations);
    m_Shader.SetMat4("view", m_Mat);

    std::vector<Vertex> vertices;
    vertices.push_back({glm::vec2(0.0f, 0.0f), glm::vec4(0.0f)});
    vertices.push_back({glm::vec2(m_App.GetWidth(), 0.0f), glm::vec4(0.0f)});
    vertices.push_back({glm::vec2(m_App.GetWidth(), m_App.GetHeight()), glm::vec4(0.0f)});
    vertices.push_back({glm::vec2(m_App.GetWidth(), m_App.GetHeight()), glm::vec4(0.0f)});
    vertices.push_back({glm::vec2(0.0f, m_App.GetHeight()), glm::vec4(0.0f)});
    vertices.push_back({glm::vec2(0.0f, 0.0f), glm::vec4(0.0f)});

    VertexArrayLayout layout;
    layout.PushElement(2, GL_FLOAT, GL_FALSE); //position
    layout.PushElement(4, GL_FLOAT, GL_FALSE); //Color (not actually useful in the mandelbrot shader)
    m_VAO.AddBuffer(VertexBuffer(vertices), layout);
}

void Mandelbrot::Update(float dt) {
    if (Input::IsKeyDown(Key::Space) && m_Selection.Selected()){
        //Update the projection
        m_MatStack.push(m_Mat);
        glm::vec4 selection = m_Selection.GetSelection(); //{x, y, width, height}
        m_Mat = glm::translate(m_Mat, glm::vec3(selection.x, selection.y, 0.0));
        m_Mat = glm::scale(m_Mat, glm::vec3(selection.z/m_App.GetWidth(), selection.w/m_App.GetHeight(), 1.0));

        m_Selection.UnSelect();
    }
    if (Input::IsKeyReleased(Key::B) && !m_MatStack.empty()){
        m_Mat = m_MatStack.top();
        m_MatStack.pop();
    }
    if (Input::IsKeyReleased(Key::R) && !m_MatStack.empty()){
        while (m_MatStack.size() > 1)
            m_MatStack.pop();
        m_Mat = m_MatStack.top();
    }
    if (Input::IsKeyReleased(Key::Q))
        m_App.Terminate();
}

void Mandelbrot::Render(Renderer2D &renderer) {
    m_Shader.SetMat4("projection", renderer.GetProjectionMatrix());
    m_Shader.SetMat4("view", m_Mat);
    Renderer2D::Render(m_VAO, 6, m_Shader);
}
