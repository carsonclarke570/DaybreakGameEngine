#version 450

layout(location = 0) in vec3 position;
layout(location = 2) in vec3 normal;

out VS_OUT {
	vec3 normal0;
} vs_out;

layout(std140, binding = 0) uniform SYS_View {
	mat4 view;
	mat4 projection;
};
uniform mat4 model;

void main() {
    gl_Position = projection * view * model * vec4(position, 1.0); 
    mat3 normalMatrix = mat3(transpose(inverse(view * model)));
    vs_out.normal0 = normalize(vec3(projection * vec4(normalMatrix * normal, 0.0)));
}
