#version 450

layout (triangles) in;
layout (triangle_strip, max_vertices = 3) out;

in VS_OUT {
	vec2 texture0;
	vec3 normal0;
	vec3 position0;
} gs_in[];

out VS_OUT {
	vec2 texture0;
	vec3 normal0;
	vec3 position0;
} gs_out;


void main() {
	gl_Position = gl_in[0].gl_Position;
	gs_out = gs_in[0];
	EmitVertex();
	gl_Position = gl_in[1].gl_Position;
	gs_out = gs_in[1];
	EmitVertex();
	gl_Position = gl_in[2].gl_Position;
	gs_out = gs_in[2];
	EmitVertex();
	EndPrimitive();
}