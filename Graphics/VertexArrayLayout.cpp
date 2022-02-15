//
// Created by zivfreud on 2/5/22.
//

#include "VertexArrayLayout.h"

VertexArrayLayout::VertexArrayLayout() : m_Stride(0) {}

void VertexArrayLayout::PushElement(int size, unsigned int type, unsigned char normalized) {
    m_Elements.push_back({size, type, normalized});
    m_Stride += size * Utils::GetSizeOfType(type);
}