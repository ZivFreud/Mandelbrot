//
// Created by zivfreud on 2/5/22.
//

#include "VertexArray.h"

VertexArray::VertexArray() {
    glGenVertexArrays(1, &m_ID);
}

void VertexArray::Bind() const {
    glBindVertexArray(m_ID);
}

void VertexArray::UnBind() {
    glBindVertexArray(0);
}

void VertexArray::AddBuffer(const VertexBuffer& buffer, const VertexArrayLayout& layout) {
    Bind();
    buffer.Bind();

    const auto& elements = layout.GetElement();
    int stride = layout.GetStride();
    int offset = 0;
    for (int i = 0; i < elements.size(); i++){
        VertexArrayElement element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.size, element.type, element.normalized, stride, reinterpret_cast<const void*>(offset));
        offset += element.size * Utils::GetSizeOfType(element.type);
    }

    m_VBOs.push_back(buffer.m_ID);
}

void VertexArray::AddBuffer(const DynamicVertexBuffer &buffer, const VertexArrayLayout &layout) const {
    Bind();
    buffer.Bind();

    const auto& elements = layout.GetElement();
    int stride = layout.GetStride();
    int offset = 0;
    for (int i = 0; i < elements.size(); i++){
        VertexArrayElement element = elements[i];
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, element.size, element.type, element.normalized, stride, reinterpret_cast<const void*>(offset));
        offset += element.size * Utils::GetSizeOfType(element.type);
    }
}

void VertexArray::ClearBuffers() {
    for (unsigned int id : m_VBOs){
        glDeleteBuffers(1, &id);
    }
}
