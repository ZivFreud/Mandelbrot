//
// Created by zivfreud on 2/9/22.
//

#include "Renderer2D.h"


Renderer2D::Renderer2D(glm::mat4 projection) : m_Projection(projection), m_Changed(false){
    ResourceManager::LoadShader("BasicShader", "BasicShader/BasicShaderVertex.glsl", "BasicShader/BasicShaderFragment.glsl");
    m_Shader = ResourceManager::GetShader("BasicShader");

    m_Shader.SetMat4("projection", projection);


}

void Renderer2D::RenderPoints() {

    if (m_Vertices.empty())
        return;


    if (m_Changed) {
        m_VAO.ClearBuffers();
        VertexArrayLayout layout;
        layout.PushElement(2, GL_FLOAT, GL_FALSE); //Position
        layout.PushElement(4, GL_FLOAT, GL_FALSE); //Color
        m_VAO.AddBuffer(VertexBuffer(m_Vertices), layout);
        m_Changed = false;
    }
    m_VAO.Bind();
    m_Shader.Bind();
    glDrawArrays(GL_POINTS, 0, (int)m_Vertices.size());
}

void Renderer2D::AddPoint(glm::vec2 point) {
    Vertex vertex = {point, m_Color};
    m_Vertices.push_back(vertex);
    m_Changed = true;
}
void Renderer2D::AddPoint(float x, float y) {
    AddPoint(glm::vec2(x,y));
}

void Renderer2D::SetColor(glm::vec4 color) {
    m_Color = color;
    m_Changed = true;
}
void Renderer2D::SetColor(float r, float g, float b, float a) {
    SetColor(glm::vec4(r,g,b,a));
}

void Renderer2D::FlushPoints() {
    m_Vertices.clear();
}

void Renderer2D::FillRect(float x, float y, float width, float height, const char* shader) {
    std::vector<Vertex> vertices;
    vertices.push_back({glm::vec2(x, y), m_Color});
    vertices.push_back({glm::vec2(x+width, y), m_Color});
    vertices.push_back({glm::vec2(x+width, y+height), m_Color});
    vertices.push_back({glm::vec2(x, y+height), m_Color});

    std::vector<unsigned int> indices = {0, 1, 2, 2, 3, 0};

    VertexArrayLayout layout;
    layout.PushElement(2, GL_FLOAT, GL_FALSE); //Position
    layout.PushElement(4, GL_FLOAT, GL_FALSE); //Color
    VertexArray vao;
    vao.AddBuffer(VertexBuffer(vertices), layout);
    IndexBuffer ibo(indices);

    if (shader){
        ResourceManager::GetShader(shader).Bind();
    }else{
        m_Shader.Bind();
    }

    vao.Bind();
    ibo.Bind();

    glDrawElements(GL_TRIANGLES, (int)indices.size(), GL_UNSIGNED_INT, nullptr);
}

void Renderer2D::FillRect(glm::vec4 rect) {
    FillRect(rect.x, rect.y, rect.z, rect.w);
}

void Renderer2D::DrawRect(float x, float y, float width, float height, const char *shader) {
    std::vector<Vertex> vertices;
    vertices.push_back({glm::vec2(x, y), m_Color});
    vertices.push_back({glm::vec2(x+width, y), m_Color});
    vertices.push_back({glm::vec2(x+width, y+height), m_Color});
    vertices.push_back({glm::vec2(x, y+height), m_Color});
    //vertices.push_back({glm::vec2(x, y), m_Color});

    VertexArrayLayout layout;
    layout.PushElement(2, GL_FLOAT, GL_FALSE); //Position
    layout.PushElement(4, GL_FLOAT, GL_FALSE); //Color
    VertexArray vao;
    vao.AddBuffer(VertexBuffer(vertices), layout);


    if (shader){
        ResourceManager::GetShader(shader).Bind();
    }else{
        m_Shader.Bind();
    }

    vao.Bind();
    glDrawArrays(GL_LINE_LOOP, 0, 4);
}

void Renderer2D::DrawRect(glm::vec4 rect) {
    DrawRect(rect.x, rect.y, rect.z, rect.w);
}



