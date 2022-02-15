//
// Created by zivfreud on 2/4/22.
//

#include "IndexBuffer.h"

#include <utility>

IndexBuffer::IndexBuffer(std::vector<unsigned int> indices) : m_Indices(std::move(indices)){
    glGenBuffers(1, &m_ID);
    Bind();
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, (long)(m_Indices.size()*sizeof(unsigned int)), &m_Indices[0], GL_STATIC_DRAW);
}

void IndexBuffer::Bind() const {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ID);
}

void IndexBuffer::UnBind() {
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
