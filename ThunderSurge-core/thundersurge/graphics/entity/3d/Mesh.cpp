#include "Mesh.h"

namespace thundersurge {

	namespace graphics {

		Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices)
			: m_vertices(vertices), m_indices(indices) {

			load();
		}

		Mesh::~Mesh() {
		}

		void Mesh::load() {
			glGenVertexArrays(1, &m_vao);
			glGenBuffers(1, &m_vbo);
			glGenBuffers(1, &m_ibo);

			glBindVertexArray(m_vao);
			glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
			glBufferData(GL_ARRAY_BUFFER, m_vertices.size() * sizeof(Vertex), &m_vertices[0], GL_STATIC_DRAW);

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.size() * sizeof(GLuint), &m_indices[0], GL_STATIC_DRAW);

			// Vertex Positions
			glEnableVertexAttribArray(0);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

			glBindVertexArray(0);
		}

		void Mesh::render() {
			glBindVertexArray(m_vao);
			glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}
	}
}