#version 450

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in VS_OUT {
	vec2 texture0;
	vec3 normal0;
	vec3 position0;
} gs_in[];

out vec2 texcoord;
out vec3 normal;
out vec3 position;

void main() {
	gl_Position = gl_in[0].gl_Position;
	texcoord = gs_in[0].texture0;
	normal = gs_in[0].normal0;
	position = gs_in[0].position0;
	EmitVertex();
	gl_Position = gl_in[1].gl_Position;
	texcoord = gs_in[1].texture0;
	normal = gs_in[1].normal0;
	position = gs_in[1].position0;
	EmitVertex();
	gl_Position = gl_in[2].gl_Position;
	texcoord = gs_in[2].texture0;
	normal = gs_in[2].normal0;
	position = gs_in[2].position0;
	EmitVertex();
	EndPrimitive();
}