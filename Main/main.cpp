#include "Core/Application.h"
#include "Mandelbrot.h"
#include "Selection.h"

int main() {
    Application app("Mandelbrot Set", 800, 600);

    app.Init();

    Ref<Selection> selection = Entity::CreateEntity<Selection>(((float)app.GetWidth())/((float)app.GetHeight()));

    app.CreateAndPushEntity<Mandelbrot>(app, *selection);
    app.PushEntity(selection);


    app.MainLoop();

    return 0;
}
