#version 450

in vec2 texcoord;
in vec3 normal;
in vec3 position;

out vec4 fragColor;

void main() {
	fragColor = vec4(0, 0, 0, 1);
}