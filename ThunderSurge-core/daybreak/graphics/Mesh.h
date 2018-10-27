#ifndef _MESH_H_
#define _MESH_H_

#include <GL/glew.h>

#include "../core/math/math.h"
#include "../utils/FileUtils.h"

namespace daybreak {

	namespace graphics {

		struct Vertex {
			math::vec3 pos;
			math::vec3 normal;
			math::vec2 texture;
			math::vec3 color;
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
			void load();
		public:
			Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices);
			Mesh(const char* filename);
			~Mesh();

			void render();
		};
	}
}
#endif 