//
// Created by zivfreud on 2/15/22.
//

#include "Selection.h"

Selection::Selection(float aspectRatio) :
m_SelectedFirst(false), m_P1(0, 0), m_P2(0,0), m_Visible(false), m_Selected(false),
m_AspectRatio(aspectRatio)
{}

void Selection::Update(float dt) {
    if (Input::IsKeyDown(Key::Escape)) {
        UnSelect();
    }
    if (Input::IsMouseDown()){
        if (m_SelectedFirst){
            m_P2 = Input::GetCursorPosition();

            //Adjust to aspect ratio
            float height = glm::abs(m_P2.y-m_P1.y);
            if (m_P2.x < m_P1.x)
                m_P2.x = m_P1.x - height * m_AspectRatio;
            else
                m_P2.x = m_P1.x + height * m_AspectRatio;
        }else{
            m_P1 = Input::GetCursorPosition();
            m_P2 = m_P1;
            m_Visible = true;
            m_SelectedFirst = true;
            m_Selected = false;
        }
    }else if (m_SelectedFirst){
        m_SelectedFirst = false;
        m_Selected = true;
    }
}

void Selection::Render(Renderer2D &renderer) {
    if (m_Visible){
        renderer.SetColor({1.0, 1.0, 1.0, 1.0});
        renderer.DrawRect(GetSelection());
    }
}

glm::vec4 Selection::GetSelection() {
    glm::vec2 diagonal = m_P1-m_P2;
    float width = glm::abs(diagonal.x);
    float height = glm::abs(diagonal.y);

    if (m_P2.x < m_P1.x){
        if (m_P2.y < m_P1.y)
            return {m_P2.x, m_P2.y, width, height};
        else
            return {m_P2.x , m_P1.y, width, height};
    }else{
        if (m_P2.y < m_P1.y)
            return {m_P1.x, m_P2.y, width, height};
        else
            return {m_P1.x , m_P1.y, width, height};
    }
}

bool Selection::Selected() const {

    return m_Selected;
}

void Selection::UnSelect() {
    m_Visible = false;
    m_SelectedFirst = false;
    m_Selected = false;
}
