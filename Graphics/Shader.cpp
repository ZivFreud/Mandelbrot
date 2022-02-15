//
// Created by zivfreud on 2/5/22.
//

#include "Shader.h"

bool Shader::Compile(const char *vertexSource, const char *fragmentSource, const char *geometrySource) {
    if (geometrySource)
        m_HasGeometryShader = true;
    else
        m_HasGeometryShader = false;

    unsigned int vertexShader, fragmentShader, geometryShader;

    //Create shaders
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    if (m_HasGeometryShader)
        geometryShader = glCreateShader(GL_GEOMETRY_SHADER);

    //Add sources
    glShaderSource(vertexShader, 1, &vertexSource, nullptr);
    glShaderSource(fragmentShader, 1, &fragmentSource, nullptr);
    if (m_HasGeometryShader)
        glShaderSource(geometryShader, 1, &geometrySource, nullptr);

    m_VShader = vertexShader;
    m_FShader = fragmentShader;
    m_GShader = geometryShader;

    int success;
    char infoLog[512];

    //Compile vertex shader
    glCompileShader(m_VShader);
    glGetShaderiv(m_VShader, GL_COMPILE_STATUS, &success);
    if(!success)
    {
        glGetShaderInfoLog(m_VShader, 512, nullptr, infoLog);
        LOG_ERROR("Failed to compile vertex shader: {}", infoLog);
        return false;
    }

    //Compile fragment shader
    glCompileShader(m_FShader);
    glGetShaderiv(m_FShader, GL_COMPILE_STATUS, &success);
    if (!success){
        glGetShaderInfoLog(m_FShader, 512, nullptr, infoLog);
        LOG_ERROR("Failed to compile fragment shader: {}", infoLog);
        return false;
    }

    //Compile geometry shader
    if (m_HasGeometryShader){
        glCompileShader(m_GShader);
        glGetShaderiv(m_GShader, GL_COMPILE_STATUS, &success);
        if (!success){
            glGetShaderInfoLog(m_GShader, 512, nullptr, infoLog);
            LOG_ERROR("Failed to compile geometry shader: {}", infoLog);
            return false;
        }
    }
    return true;
}

bool Shader::Link() {
    int success;
    char infoLog[512];

    m_ID = glCreateProgram();
    glAttachShader(m_ID, m_VShader);
    glAttachShader(m_ID, m_FShader);
    if (m_HasGeometryShader)
        glAttachShader(m_ID, m_GShader);

    glLinkProgram(m_ID);
    glGetProgramiv(m_ID, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(m_ID, 512, nullptr, infoLog);
        LOG_ERROR("Failed to link shader: {}", infoLog);
        return false;
    }

    glDeleteShader(m_VShader);
    glDeleteShader(m_FShader);
    if (m_HasGeometryShader)
        glDeleteShader(m_GShader);

    return true;
}

bool Shader::CompileAndLink(const char* vertexSource, const char* fragmentSource, const char* geometrySource) {
    return Compile(vertexSource, fragmentSource, geometrySource) && Link();
}


Shader::~Shader() {
    glDeleteProgram(m_ID);
}

void Shader::Bind() const {
    glUseProgram(m_ID);
}

void Shader::UnBind() {
    glUseProgram(0);
}

void Shader::SetFloat(const char *name, float value) {
    glUniform1f(GetUniformLocation(name), value);
}

void Shader::SetBool(const char *name, bool value) {
    glUniform1i(GetUniformLocation(name), (int)value);
}

void Shader::SetVec2(const char *name, glm::vec2 value) {
    glUniform2fv(GetUniformLocation(name), 1, glm::value_ptr(value));
}

void Shader::SetVec3(const char *name, glm::vec3 value) {
    glUniform3fv(GetUniformLocation(name), 1, glm::value_ptr(value));
}

void Shader::SetMat4(const char *name, glm::mat4 value) {
    glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
}

int Shader::GetUniformLocation(const char *name) {

    int location;
    if (m_Locations.find(name) != m_Locations.end()){
        location = m_Locations[name];
    }else{
        location = glGetUniformLocation(m_ID, name);
        if (location == -1)
            LOG_WARN("Uniform {} not found.", name);
        m_Locations[name] = location;
    }
    return location;
}