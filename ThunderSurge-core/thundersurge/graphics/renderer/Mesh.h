#pragma once

#include <map>

#include "../../core/math/math.h"
#include "../buffer/vertexarray.h"
#include "../buffer/indexbuffer.h"
#include "../../utils/FileUtils.h"

namespace thundersurge {

	namespace graphics {

		struct Vertex {
			math::vec3 pos;
			math::vec3 normal;
			math::vec2 texture;
		};

		struct Index {
			GLuint posInd;
			GLuint texInd;
			GLuint normalInd;
		};

		class Mesh {
		private:
			std::vector<Vertex> m_vertices;
			std::vector<GLuint> m_indices;
			GLuint m_vao, m_vbo, m_ibo;

			void parseOBJ(const char* filename);
			Index* parseOBJIndex(const char* str);
			void load();
		public:
			Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices);
			Mesh(const char* filename);
			~Mesh();

			void render();

			friend std::ostream& operator<<(std::ostream& stream, const Mesh& mesh);
		};
	}
}