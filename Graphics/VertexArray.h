//
// Created by zivfreud on 2/5/22.
//

#ifndef MANDELBROT_VERTEXARRAY_H
#define MANDELBROT_VERTEXARRAY_H

#include <vector>
#include <GL/glew.h>
#include "VertexBuffer.h"
#include "DynamicVertexBuffer.h"
#include "VertexArrayLayout.h"

class VertexArray {
public:
    VertexArray();

    void Bind() const;
    static void UnBind();

    void AddBuffer(const VertexBuffer& buffer, const VertexArrayLayout& layout);
    void AddBuffer(const DynamicVertexBuffer& buffer, const VertexArrayLayout& layout) const;

    void ClearBuffers();
private:
    unsigned int m_ID{};
    std::vector<unsigned int> m_VBOs;
};


#endif //MANDELBROT_VERTEXARRAY_H
