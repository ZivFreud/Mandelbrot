//
// Created by zivfreud on 2/5/22.
//

#ifndef MANDELBROT_RESOURCEMANAGER_H
#define MANDELBROT_RESOURCEMANAGER_H

#include <fstream>
#include <string>
#include <sstream>
#include <map>
#include "Graphics/Shader.h"

class ResourceManager {
public:
    static void LoadShader(const std::string& name, const std::string& vertexFile, const std::string& fragmentFile, const std::string& geometryFile = "");
    static const Shader& GetShader(const std::string& name);

    static void SetShadersDir(const std::string& path);
private:
    ResourceManager() = default;

    static std::string ReadFile(const std::string& path);

private:
    static std::map<const std::string, Shader> Shaders;
    static std::string ShadersDir;
};


#endif //MANDELBROT_RESOURCEMANAGER_H
