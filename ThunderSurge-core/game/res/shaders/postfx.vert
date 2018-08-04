#version 450

layout (location = 0) in vec2 postion;
layout (location = 1) in vec2 texture;

out vec2 texture0;
out vec2 position0;

void main() {
	texture0 = texture;
	position0 = vec2(postion.x, postion.y);
	gl_Position = vec4(postion.x, postion.y, 0.0, 1.0);
}