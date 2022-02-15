#version 330 core
layout (location = 0) in vec2 aPos;
layout (location = 1) in vec4 aColor;

uniform mat4 projection;
uniform mat4 view;

out vec2 pos;

void main()
{
    gl_Position = projection * vec4(aPos.x, aPos.y, 0.0, 1.0);
    vec4 v = projection * view * vec4(aPos.x, aPos.y, 0.0, 1.0);
    pos = vec2(v.x, v.y);
}