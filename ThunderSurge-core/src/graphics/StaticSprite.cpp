#include "StaticSprite.h"

namespace thundersurge {

	namespace graphics {
		
		StaticSprite::StaticSprite(float x, float y, float width, float height, const math::vec4& color, Shader& shader)
			: Renderable2D(math::vec3(x, y, 0), math::vec2(width, height), color), m_Shader(shader) {
			
			m_VertexArray = new VertexArray();
			GLfloat vertices[] = {
				0, 0, 0,
				0, height, 0,
				width, height, 0,
				width, 0, 0
			 };
			GLfloat colors[] = {
				color.m_x, color.m_y, color.m_z, color.m_w,
				color.m_x, color.m_y, color.m_z, color.m_w,
				color.m_x, color.m_y, color.m_z, color.m_w,
				color.m_x, color.m_y, color.m_z, color.m_w
			};

			m_VertexArray->addBuffer(new Buffer(vertices, 4 * 3, 3), 0);
			m_VertexArray->addBuffer(new Buffer(colors, 4 * 4, 4), 1);

			GLushort indices[] = { 0, 1, 2, 2, 3, 0 };
			m_IndexBuffer = new IndexBuffer(indices, 6);
		}
			
		StaticSprite::~StaticSprite() {
			delete m_VertexArray;
			delete m_IndexBuffer;
		}
	}
}