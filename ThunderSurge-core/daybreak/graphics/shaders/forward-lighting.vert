#version 330

layout (location = 0) in vec3 position;
layout (location = 1) in vec2 texture;
layout (location = 2) in vec3 normal;

out vec2 texture0;
out vec3 normal0;
out vec3 position0;

uniform mat4 model;
uniform mat4 projection;

void main() {
    gl_Position = projection * model * vec4(position, 1.0);

    texture0 = texture;
    normal0 = mat3(transpose(inverse(model))) * normal;
    position0 = vec3(model * vec4(position, 1.0));
}