//
// Created by zivfreud on 2/14/22.
//

#ifndef MANDELBROT_DYNAMICVERTEXBUFFER_H
#define MANDELBROT_DYNAMICVERTEXBUFFER_H

#include <vector>
#include "VertexBuffer.h"

class DynamicVertexBuffer {
public:
    static const int DEFAULT_VERTEX_BUFFER_SIZE = 1<<24;

    DynamicVertexBuffer();

    void PushVertex(Vertex vertex);

    void Bind() const;
    static void UnBind();

    void Flush();

    inline unsigned long Size() const { return m_Vertices.size(); }
    inline unsigned long Capacity() const { return m_Capacity; }

private:
    void UpdateBuffer();

    unsigned int m_ID{};
    std::vector<Vertex> m_Vertices;
    unsigned long m_Capacity;
};


#endif //MANDELBROT_DYNAMICVERTEXBUFFER_H
