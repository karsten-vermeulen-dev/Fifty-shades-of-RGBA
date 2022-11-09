#version 460

in vec3 colorOut;
out vec4 pixelColor;
uniform float time;

void main(void)
{
    pixelColor = vec4(colorOut.r * abs(sin(time)), 
                      colorOut.g * abs(cos(time)), 
                      colorOut.b * abs(sin(time)), 
                      1.0);
}