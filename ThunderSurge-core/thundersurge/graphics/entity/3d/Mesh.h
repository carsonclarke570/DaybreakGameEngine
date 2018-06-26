#pragma once

#include "../../../core/math/math.h"
#include "../../buffer/vertexarray.h"
#include "../../buffer/indexbuffer.h"

namespace thundersurge {

	namespace graphics {

		struct Vertex {
			math::vec3 pos;
			//math::vec3 normal;
			//math::vec2 texture;
		};

		class Mesh {
		private:
			std::vector<Vertex> m_vertices;
			std::vector<GLuint> m_indices;
			GLuint m_vao, m_vbo, m_ibo;

			void load();
		public:
			Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices);
			~Mesh();

			void render();
		};
	}
}