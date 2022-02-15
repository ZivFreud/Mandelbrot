//
// Created by zivfreud on 2/5/22.
//

#ifndef MANDELBROT_SHADER_H
#define MANDELBROT_SHADER_H

#include <GL/glew.h>
#include <map>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Core/Log.h"

class Shader {
public:
    Shader() = default;
    ~Shader();

    void Bind() const;
    static void UnBind();

    bool Compile(const char* vertexSource, const char* fragmentSource, const char* geometrySource = nullptr);
    bool Link();
    bool CompileAndLink(const char* vertexSource, const char* fragmentSource, const char* geometrySource = nullptr);

    void SetFloat(const char* name, float value);
    void SetBool(const char* name, bool value);
    void SetVec2(const char* name, glm::vec2 value);
    void SetVec3(const char* name, glm::vec3 value);
    void SetMat4(const char* name, glm::mat4 value);

private:
    int GetUniformLocation(const char* name);

private:
    bool m_HasGeometryShader;
    unsigned int m_VShader{}, m_FShader{}, m_GShader{}, m_ID{};
    std::map<const char*, int> m_Locations; //Uniforms' locations cache.
};


#endif //MANDELBROT_SHADER_H
