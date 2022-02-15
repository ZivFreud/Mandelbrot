//
// Created by zivfreud on 2/5/22.
//

#ifndef MANDELBROT_UTILS_H
#define MANDELBROT_UTILS_H

//Types copied from glew.h
#define GL_BYTE 0x1400
#define GL_UNSIGNED_BYTE 0x1401
#define GL_SHORT 0x1402
#define GL_UNSIGNED_SHORT 0x1403
#define GL_INT 0x1404
#define GL_UNSIGNED_INT 0x1405
#define GL_FLOAT 0x1406

class Utils {
public:
    static int GetSizeOfType(unsigned int type);
};


#endif //MANDELBROT_UTILS_H
