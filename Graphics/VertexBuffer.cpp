//
// Created by zivfreud on 2/4/22.
//

#include "VertexBuffer.h"

#include <utility>

VertexBuffer::VertexBuffer(std::vector<Vertex> vertices) : m_Vertices(std::move(vertices)){
    glGenBuffers(1, &m_ID);
    Bind();
    glBufferData(GL_ARRAY_BUFFER, (long)(m_Vertices.size()*sizeof(Vertex)), &m_Vertices[0], GL_STATIC_DRAW);
}

void VertexBuffer::Bind() const {
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void VertexBuffer::UnBind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
