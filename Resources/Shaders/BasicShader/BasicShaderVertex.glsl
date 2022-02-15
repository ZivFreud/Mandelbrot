#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec4 aColor;

uniform mat4 projection;

out vec4 vertexColor;

void main()
{
    //gl_PointSize = 2;
    gl_Position = projection *  vec4(aPos.x, aPos.y, 0.0, 1.0);
    vertexColor = aColor;
}