#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

uniform mat4 pr_mat;
uniform mat4 vw_mat = mat4(1.0);
uniform mat4 ml_mat = mat4(1.0);

out DATA {
	vec4 position;
	vec4 color;
} vs_out;

void main() {
	gl_Position = pr_mat * vw_mat * ml_mat * position;
	vs_out.position = ml_mat * position;
	vs_out.color = color;
}