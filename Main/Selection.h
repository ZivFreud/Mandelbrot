//
// Created by zivfreud on 2/15/22.
//

#ifndef MANDELBROT_SELECTION_H
#define MANDELBROT_SELECTION_H

#include "Core/Entity.h"
#include "Input/Input.h"

class Selection : public Entity{
public:
    Selection(float aspectRatio);

    void Update(float dt) override;
    void Render(Renderer2D& renderer) override;

    /// \return A vec4 of a rectangle: {x, y, width, height}
    glm::vec4 GetSelection();
    bool Selected() const;
    void UnSelect();

private:
    float m_AspectRatio;
    glm::vec2 m_P1, m_P2;
    bool m_SelectedFirst, m_Selected;
    bool m_Visible;

};


#endif //MANDELBROT_SELECTION_H
