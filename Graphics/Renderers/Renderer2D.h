//
// Created by zivfreud on 2/9/22.
//

#ifndef MANDELBROT_RENDERER2D_H
#define MANDELBROT_RENDERER2D_H

#include <vector>
#include "Graphics/VertexArray.h"
#include "Graphics/IndexBuffer.h"
#include "Graphics/Shader.h"
#include "Core/ResourceManager.h"

class Renderer2D {
public:
    explicit Renderer2D(glm::mat4 projection);

    /// Render a vertex array (not using index buffer)
    /// With GL_TRIANGLES
    /// \param vao
    /// \param shader
    static void Render(const VertexArray& vao, int count, const Shader& shader);

    /// Set the color of the points.
    /// \param color
    void SetColor(glm::vec4 color);
    void SetColor(float r, float g, float b, float a);


    /// \param shader - optional shader
    void FillRect(float x, float y, float width, float height, const char* shader = nullptr);
    void FillRect(glm::vec4 rect);


    /// \param shader - optional shader
    void DrawRect(float x, float y, float width, float height, const char* shader = nullptr);
    void DrawRect(glm::vec4 rect);

    inline glm::mat4 GetProjectionMatrix() const { return m_Projection; };

private:
    glm::vec4 m_Color{};
    Shader m_Shader;
    glm::mat4 m_Projection;
};


#endif //MANDELBROT_RENDERER2D_H
