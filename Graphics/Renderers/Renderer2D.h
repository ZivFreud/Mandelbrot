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

    /// Add a point to the batch.
    /// \param point
    void AddPoint(glm::vec2 point);
    void AddPoint(float x, float y);


    /// Set the color of the points.
    /// \param color
    void SetColor(glm::vec4 color);
    void SetColor(float r, float g, float b, float a);


    /// Render and flush
    void RenderPoints();


    /// \param shader - optional shader
    void FillRect(float x, float y, float width, float height, const char* shader = nullptr);
    void FillRect(glm::vec4 rect);


    /// \param shader - optional shader
    void DrawRect(float x, float y, float width, float height, const char* shader = nullptr);
    void DrawRect(glm::vec4 rect);


    ///Clear the batch
    void FlushPoints();

    inline glm::mat4 GetProjectionMatrix() const { return m_Projection; };

private:
    //Used for rendering points
    bool m_Changed;
    VertexArray m_VAO;
    std::vector<Vertex> m_Vertices;
    glm::vec4 m_Color{};
    Shader m_Shader;
    glm::mat4 m_Projection;
};


#endif //MANDELBROT_RENDERER2D_H
