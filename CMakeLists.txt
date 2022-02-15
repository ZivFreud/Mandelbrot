cmake_minimum_required(VERSION 3.20)
project(mandelbrot)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)
find_package(spdlog REQUIRED)
find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)

add_executable(mandelbrot
        Main/main.cpp
        Core/Log.cpp
        Core/Log.h
        Core/Core.h
        Core/Window.cpp
        Core/Window.h
        Core/Application.cpp
        Core/Application.h
        Core/Entity.h
        Core/ResourceManager.cpp
        Core/ResourceManager.h
        Input/Input.h
        Input/Input.cpp
        Input/KeyCodes.h
        Graphics/VertexBuffer.cpp
        Graphics/VertexBuffer.h
        Graphics/IndexBuffer.cpp
        Graphics/IndexBuffer.h
        Graphics/Shader.cpp
        Graphics/Shader.h
        Graphics/VertexArrayLayout.h
        Graphics/VertexArrayLayout.cpp
        Graphics/Utils.cpp
        Graphics/Utils.h
        Graphics/VertexArray.cpp
        Graphics/VertexArray.h
        Graphics/Renderers/Renderer2D.cpp
        Graphics/Renderers/Renderer2D.h
        Graphics/DynamicVertexBuffer.cpp
        Graphics/DynamicVertexBuffer.h
        Main/Mandelbrot.cpp
        Main/Mandelbrot.h
        Vendor/CTPL/ctpl.h
        Main/Selection.cpp
        Main/Selection.h)

include_directories(${OPENGL_INCLUDE_DIR})

target_link_libraries(mandelbrot OpenGL::GL)
target_link_libraries(mandelbrot spdlog::spdlog)
target_link_libraries(mandelbrot glfw)
target_link_libraries(mandelbrot glm::glm)
target_link_libraries(mandelbrot GLEW::GLEW)

include_directories(".")