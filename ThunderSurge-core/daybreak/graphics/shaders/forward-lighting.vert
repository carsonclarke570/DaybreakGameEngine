#version 450

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texture;
layout (location = 2) in vec3 normal;

out VS_OUT {
	vec2 texture0;
	vec3 normal0;
	vec3 position0;
} vs_out;

layout (std140, binding = 0) uniform SYS_View {
	mat4 view;
	mat4 projection;
};

uniform mat4 model;

void main() {
    gl_Position = projection * view * model * vec4(position, 1.0);

    vs_out.texture0 = texture;
    vs_out.normal0 = mat3(transpose(inverse(model))) * normal;
    vs_out.position0 = vec3(model * vec4(position, 1.0));
}