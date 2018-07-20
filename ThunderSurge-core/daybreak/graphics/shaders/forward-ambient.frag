#version 330

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float specPow;
}; 

in vec2 texture0;
in vec3 normal0;
in vec3 position0;

out vec4 fragColor;

uniform vec3 ambient;
uniform Material material;

void main() {
	fragColor = texture2D(material.diffuse, texture0) * vec4(ambient, 1);
}