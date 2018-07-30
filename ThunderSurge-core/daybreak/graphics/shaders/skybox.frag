#version 450

out vec4 FragColor;

in vec3 texture0;

uniform samplerCube skybox;

void main()
{    
    FragColor = texture(skybox, texture0);
}