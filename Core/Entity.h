//
// Created by zivfreud on 2/4/22.
//

#ifndef MANDELBROT_ENTITY_H
#define MANDELBROT_ENTITY_H

#include "Graphics/Renderers/Renderer2D.h"

class Entity{
public:
    virtual void Update(float dt) = 0;
    virtual void Render(Renderer2D& renderer) = 0;

    template<typename T, typename ... Args, typename = std::enable_if<std::is_base_of<Entity, T>::value>> // T must be an entity.
    static Ref<T> CreateEntity(Args&& ... args){
        return CreateRef<T>(std::forward<Args>(args)...);
    }
};

#endif //MANDELBROT_ENTITY_H
