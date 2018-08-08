#version 450

in VS_OUT {
	vec2 texture0;
	vec3 normal0;
	vec3 position0;
} fs_in;

out vec4 fragColor;

void main() {
	fragColor = vec4(0, 0, 0, 1);
}