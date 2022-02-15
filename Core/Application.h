//
// Created by zivfreud on 2/4/22.
//

#ifndef MANDELBROT_APPLICATION_H
#define MANDELBROT_APPLICATION_H

#include "GL/glew.h"
#include "Graphics/Renderers/Renderer2D.h"
#include "ResourceManager.h"
#include "Window.h"
#include "Input/Input.h"
#include "Entity.h"
#include <vector>

class Application {
public:
    Application(const char* name, int width, int height, int FPS = 60);
    ~Application();

    void Init();
    void MainLoop();
    void Terminate();

    void PushEntity(const Ref<Entity>& entity);

    template<typename T, typename ... Args, typename = std::enable_if<std::is_base_of<Entity, T>::value>> // T must be an entity.
    Ref<Entity> CreateAndPushEntity(Args&& ... args){
        Ref<Entity> entity = Entity::CreateEntity<T>(std::forward<Args>(args)...);
        PushEntity(entity);
        return entity;
    }

    int GetWidth() const;
    int GetHeight() const;

private:
    void Update(float dt);
    void Render();

    static void InitGLFW();
    static void InitGLEW();
private:
    int m_Width, m_Height;
    Window m_Window;
    int m_FPS;
    bool m_Running;

    std::vector<Ref<Entity>> m_Entities;

    Ref<Renderer2D> m_Renderer;
};


#endif //MANDELBROT_APPLICATION_H
