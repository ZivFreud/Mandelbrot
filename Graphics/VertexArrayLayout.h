//
// Created by zivfreud on 2/5/22.
//

#ifndef MANDELBROT_VERTEXARRAYLAYOUT_H
#define MANDELBROT_VERTEXARRAYLAYOUT_H

#include <vector>
#include "Utils.h"

struct VertexArrayElement{
    int size;
    unsigned int type;
    unsigned char normalized;
};

class VertexArrayLayout{
public:
    VertexArrayLayout();

    void PushElement(int size, unsigned int type, unsigned char normalized);
    inline const std::vector<VertexArrayElement>& GetElement() const { return m_Elements; };
    inline int GetStride() const { return m_Stride; }
private:
    int m_Stride;
    std::vector<VertexArrayElement> m_Elements;
};

#endif //MANDELBROT_VERTEXARRAYLAYOUT_H
