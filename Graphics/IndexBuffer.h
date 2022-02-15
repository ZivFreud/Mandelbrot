//
// Created by zivfreud on 2/4/22.
//

#ifndef MANDELBROT_INDEXBUFFER_H
#define MANDELBROT_INDEXBUFFER_H

#include <GL/glew.h>
#include <vector>

class IndexBuffer {
public:
    explicit IndexBuffer(std::vector<unsigned int> indices);

    void Bind() const;
    static void UnBind();

private:
    unsigned int m_ID{};
    std::vector<unsigned int> m_Indices;
};


#endif //MANDELBROT_INDEXBUFFER_H
