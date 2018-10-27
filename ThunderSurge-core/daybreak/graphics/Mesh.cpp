#include "Mesh.h"

#define TINYOBJLOADER_IMPLEMENTATION
#include <tiny_obj_loader.h>

namespace daybreak {

	namespace graphics {

		Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices)
			: m_vertices(vertices), m_indices(indices) {
			load();
		}

		Mesh::Mesh(const char* filename) {
			parseOBJ(filename);
			load();
		}

		Mesh::~Mesh() {
			m_vertices.clear();
			m_indices.clear();
		}

		void Mesh::parseOBJ(const char* filename) {
			tinyobj::attrib_t attrib;
			std::vector<tinyobj::shape_t> shapes;
			std::vector<tinyobj::material_t> materials;
			std::string err;

			if (!tinyobj::LoadObj(&attrib, &shapes, &materials, &err, filename)) {
				throw std::runtime_error(err);
			}

			for (const auto& shape : shapes) {
				for (const auto& index : shape.mesh.indices) {
					Vertex vertex;

					vertex.pos.m_x = attrib.vertices[3 * index.vertex_index + 0];
					vertex.pos.m_y = attrib.vertices[3 * index.vertex_index + 1];
					vertex.pos.m_z = attrib.vertices[3 * index.vertex_index + 2];

					if (index.texcoord_index >= 0) {
						vertex.texture.m_x = attrib.texcoords[2 * index.texcoord_index + 0];
						vertex.texture.m_y = attrib.texcoords[2 * index.texcoord_index + 1];
					}

					if (index.normal_index >= 0) {
						vertex.normal.m_x = attrib.normals[3 * index.normal_index + 0];
						vertex.normal.m_y = attrib.normals[3 * index.normal_index + 1];
						vertex.normal.m_z = attrib.normals[3 * index.normal_index + 2];
					}

					vertex.color.m_x = 1;
					vertex.color.m_y = 1;
					vertex.color.m_z = 0;

					m_vertices.push_back(vertex);
					m_indices.push_back(m_indices.size());
				}
			}

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
			// Texture Coordinates
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texture));
			// Normals Coordinates
			glEnableVertexAttribArray(2);
			glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
			// Vertex Colors
			glEnableVertexAttribArray(3);
			glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, color));

			glBindVertexArray(0);
		}

		void Mesh::render() {
			glBindVertexArray(m_vao);
			glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}
	}
}