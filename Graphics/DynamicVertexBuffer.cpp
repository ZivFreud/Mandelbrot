//
// Created by zivfreud on 2/14/22.
//

#include "DynamicVertexBuffer.h"

DynamicVertexBuffer::DynamicVertexBuffer() : m_Capacity(DEFAULT_VERTEX_BUFFER_SIZE){
    glGenBuffers(1, &m_ID);
    Bind();
    glBufferData(GL_ARRAY_BUFFER, (long)(m_Capacity*sizeof(Vertex)), &m_Vertices[0], GL_DYNAMIC_DRAW);
}

void DynamicVertexBuffer::PushVertex(Vertex vertex) {
    m_Vertices.push_back(vertex);
    UpdateBuffer();
}

void DynamicVertexBuffer::Bind() const{
    glBindBuffer(GL_ARRAY_BUFFER, m_ID);
}

void DynamicVertexBuffer::UnBind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void DynamicVertexBuffer::UpdateBuffer() {
    Bind();
    if (m_Vertices.size() == m_Capacity) {
        m_Capacity = m_Capacity * 2;
        glBufferData(GL_ARRAY_BUFFER, (long) (m_Capacity * sizeof(Vertex)), &m_Vertices[0], GL_DYNAMIC_DRAW);
    }else{
        glBufferSubData(GL_ARRAY_BUFFER, 0, (long) (m_Vertices.size() * sizeof(Vertex)), &m_Vertices[0]);
    }
}

void DynamicVertexBuffer::Flush() {
    m_Vertices.clear();
    UpdateBuffer();
}


