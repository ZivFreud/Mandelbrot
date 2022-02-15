#version 330 core
out vec4 FragColor;

uniform float maxIterations;
in vec2 pos;

//See https://stackoverflow.com/questions/15095909/from-rgb-to-hsv-in-opengl-glsl
// All components are in the range [0…1], including hue.
vec3 hsv2rgb(vec3 c)
{
    vec4 K = vec4(1.0, 2.0 / 3.0, 1.0 / 3.0, 3.0);
    vec3 p = abs(fract(c.xxx + K.xyz) * 6.0 - K.www);
    return c.z * mix(K.xxx, clamp(p - K.xxx, 0.0, 1.0), c.y);
}

void main()
{
    vec2 z = vec2(0, 0);
    int n = 0;
    while ((z.x*z.x + z.y*z.y < 4.0f) && (n < maxIterations)){
        z = vec2(z.x*z.x - z.y*z.y, 2*z.x*z.y) + pos;
        n++;
    }

    float hue = n / maxIterations;
    float value = 0.0f;
    if (n < maxIterations)
        value = 1.0f;

    FragColor = vec4(hsv2rgb(vec3(hue, 1.0f, value)), 1.0f);
}