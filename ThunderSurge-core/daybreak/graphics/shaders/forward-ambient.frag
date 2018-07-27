#version 450

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float specPow;
}; 

in vec2 texture0;
in vec3 normal0;
in vec3 position0;

out vec4 fragColor;

uniform Material material;

void main() {
	vec3 color = vec3(0.05, 0.05, 0.05) * vec3(texture(material.diffuse, texture0));
	fragColor = vec4(color, 1.0);
}