//
// Created by zivfreud on 2/4/22.
//

#include "Application.h"

Application::Application(const char* name, int width, int height, int FPS) :
m_Window(width, height, name), m_FPS(FPS), m_Running(false), m_Width(width), m_Height(height){
}

Application::~Application() {
    glfwTerminate();
}


void Application::Init() {
    ResourceManager::SetShadersDir("Resources/Shaders");
    Log::Init();
    InitGLFW();
    m_Window.Init();
    InitGLEW();
    glEnable(GL_PROGRAM_POINT_SIZE);
    glm::mat4 projection = glm::ortho(0.0f, (float)m_Width, 0.0f, (float)m_Height, -1.0f, 1.0f);
    m_Renderer = CreateRef<Renderer2D>(projection);
    Input::Init(m_Window.GetGLFWwindow());
}

void Application::MainLoop() {
    LOG_INFO("Application started.");

    float dt = 1.0f/(float)m_FPS;
    m_Running = true;

    double previous = glfwGetTime();
    double lag = 0.0;

    while (m_Running)
    {
        double current = glfwGetTime();
        double elapsed = current - previous;
        previous = current;
        lag += elapsed;

        glfwPollEvents();
        Input::Update();

        while (lag >= dt)
        {
            Update(dt);
            lag -= dt;
        }

        glClear(GL_COLOR_BUFFER_BIT);
        Render();

        m_Window.SwapBuffers();
    }

}

void Application::Update(float dt) {
    if (m_Window.ShouldClose()) {
        Terminate();
    }
    for (auto& entity : m_Entities){
        entity->Update(dt);
    }
}

void Application::Render() {
    for (auto& entity : m_Entities){
        entity->Render(*m_Renderer);
    }
}

void Application::InitGLFW() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_SAMPLES, 4);
}

void Application::InitGLEW() {
    if (glewInit() != GLEW_OK){
        LOG_CRITICAL("GLEW Init failed!");
    }
}

void Application::PushEntity(const Ref<Entity>& entity) {
    m_Entities.push_back(entity);
}

void Application::Terminate() {
    m_Running = false;
    LOG_INFO("Application terminated.");
}

int Application::GetWidth() const {
    return m_Width;
}

int Application::GetHeight() const {
    return m_Height;
}






