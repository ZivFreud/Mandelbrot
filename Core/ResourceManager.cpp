//
// Created by zivfreud on 2/5/22.
//

#include "ResourceManager.h"

std::map<const std::string, Shader> ResourceManager::Shaders;

std::string ResourceManager::ShadersDir;

void ResourceManager::LoadShader(const std::string& name, const std::string& vertexFile, const std::string& fragmentFile, const std::string& geometryFile) {
    std::string vertexSource = ReadFile(ShadersDir + vertexFile);
    std::string fragmentSource = ReadFile(ShadersDir + fragmentFile);

    Shaders[name] = Shader();

    if (!geometryFile.empty()){
        std::string geometrySource = ReadFile(geometryFile);
        Shaders[name].CompileAndLink(vertexSource.c_str(), fragmentSource.c_str(), geometrySource.c_str());
    }else{
        Shaders[name].CompileAndLink(vertexSource.c_str(), fragmentSource.c_str());
    }
}

const Shader &ResourceManager::GetShader(const std::string& name) {
    if (Shaders.find(name) == Shaders.end()){
        LOG_ERROR("Shader \"{}\" not found.", name);
    }
    Shaders[name].Bind();
    return Shaders[name];
}

std::string ResourceManager::ReadFile(const std::string& path) {
    std::ifstream file(path);

    if (!file.is_open()){
        LOG_ERROR("Failed to open shader file: \"{}\"", path);
        return "";
    }

    std::stringstream content;
    std::string line;

    while(getline(file, line)){
        content << line + "\n";
    }

    file.close();

    return content.str();
}

void ResourceManager::SetShadersDir(const std::string& path) {
    if (path.at(path.size()-1) == '/')
        ShadersDir = path;
    else
        ShadersDir = path + "/";
}
