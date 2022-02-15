//
// Created by zivfreud on 2/4/22.
//

#ifndef MANDELBROT_VERTEXBUFFER_H
#define MANDELBROT_VERTEXBUFFER_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

struct Vertex{
    glm::vec2 position;
    glm::vec4 color;
};

class VertexBuffer {
public:
    explicit VertexBuffer(std::vector<Vertex> vertices);

    void Bind() const;
    static void UnBind();

private:
    unsigned int m_ID{};
    std::vector<Vertex> m_Vertices;

    friend class VertexArray;
};


#endif //MANDELBROT_VERTEXBUFFER_H
