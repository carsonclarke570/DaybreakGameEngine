#include "Mesh.h"

namespace thundersurge {

	namespace graphics {

		Mesh::Mesh(std::vector<Vertex>& vertices, std::vector<GLuint>& indices)
			: m_vertices(vertices), m_indices(indices) {

			load();
		}

		Mesh::Mesh(const char* filename) {
			std::vector<std::string> lines = FileUtils::split(FileUtils::read_file(filename), '\n');
			std::vector<Vertex> vertices;
			std::vector<GLuint> indices;

			for (std::string line : lines) {
				std::vector<std::string> tokens = FileUtils::split(line, ' ');

				if (tokens.size() == 0 || !tokens[0].compare("#")) {
					continue;
				}
				else if (tokens[0].compare("v") == 0) {
					Vertex v;
					v.pos = math::vec3(stof(tokens[1]), stof(tokens[2]), stof(tokens[3]));
					vertices.push_back(v);
				}
				else if (tokens[0].compare("f") == 0) {
					indices.push_back(stoi(FileUtils::split(tokens[1], '/')[0]) - 1);
					indices.push_back(stoi(FileUtils::split(tokens[2], '/')[0]) - 1);
					indices.push_back(stoi(FileUtils::split(tokens[3], '/')[0]) - 1);

					if (tokens.size() > 4) {
						indices.push_back(stoi(FileUtils::split(tokens[1], '/')[0]) - 1);
						indices.push_back(stoi(FileUtils::split(tokens[3], '/')[0]) - 1);
						indices.push_back(stoi(FileUtils::split(tokens[4], '/')[0]) - 1);
					}
				}
			}

			m_vertices = vertices;
			m_indices = indices;
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
			// Texture Coordinates
			glEnableVertexAttribArray(1);
			glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, texture));

			glBindVertexArray(0);
		}

		void Mesh::render() {
			glBindVertexArray(m_vao);
			glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}
	}
}