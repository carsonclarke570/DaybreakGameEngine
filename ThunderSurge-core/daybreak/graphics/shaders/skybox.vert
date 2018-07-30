#version 450

layout (location = 0) in vec3 aPos;

out vec3 texture0;

layout (std140, binding = 0) uniform SYS_View {
	mat4 view;
	mat4 projection;
};

void main()
{
    texture0 = aPos;
    gl_Position = (projection * view * vec4(aPos, 1.0));
}  