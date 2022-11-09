#version 460

in vec3 colorOut;
out vec4 pixelColor;

void main(void)
{
    pixelColor = vec4(colorOut, 1.0);
}