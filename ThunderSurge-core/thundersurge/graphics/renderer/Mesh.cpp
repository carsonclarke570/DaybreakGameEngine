#include "Mesh.h"

namespace thundersurge {

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
		}

		void Mesh::parseOBJ(const char* filename) {
			std::vector<std::string> lines = FileUtils::split(FileUtils::read_file(filename), '\n');

			std::vector<math::vec3> positions;
			std::vector<math::vec2> textures;
			std::vector<math::vec3> normals;
			std::vector<Index*> indices;

			std::vector<math::vec2> texCoord;

			for (std::string line : lines) {
				std::vector<std::string> tokens = FileUtils::split(line, ' ');

				if (tokens.size() == 0 || !tokens[0].compare("#")) {
					continue;
				}
				else if (tokens[0].compare("v") == 0) {
					positions.push_back(math::vec3(stof(tokens[1]), stof(tokens[2]), stof(tokens[3])));
				}
				else if (tokens[0].compare("vt") == 0) {
					textures.push_back(math::vec2(stof(tokens[1]), stof(tokens[2])));
				}
				else if (tokens[0].compare("vn") == 0) {
					normals.push_back(math::vec3(stof(tokens[1]), stof(tokens[2]), stof(tokens[3])));
				}
				else if (tokens[0].compare("f") == 0) {
					indices.push_back(parseOBJIndex(tokens[1].c_str()));
					indices.push_back(parseOBJIndex(tokens[2].c_str()));
					indices.push_back(parseOBJIndex(tokens[3].c_str()));
				}
			}

			std::map<Index*, GLuint> indexMap;
			GLuint modelVertInd;

			for (int x = 0; x < indices.size(); x++) {
				Index* i = indices[x];
				math::vec3 curPos = positions[i->posInd];
				math::vec2 curTex = textures[i->texInd];
				math::vec3 curNrm = normals[i->normalInd];

				std::cout << curNrm << std::endl;

				if (indexMap.count(i) == 0) {
					modelVertInd = m_vertices.size();
					indexMap[i] = modelVertInd;

					Vertex v;
					v.pos = curPos;
					v.texture = curTex;
					v.normal = curNrm;
					m_vertices.push_back(v);
				}
				else {
					modelVertInd = indexMap[i];
				}
				
				m_indices.push_back(modelVertInd);
			}

			for (int x = 0; x < indices.size(); x++) {
				delete indices[x];
			}
		}

		Index* Mesh::parseOBJIndex(const char* str) {
			std::vector<std::string> vals = FileUtils::split(str, '/');
			
			Index* i = new Index();
			i->posInd = stoi(vals[0]) - 1;

			if (vals.size() > 1) {
				if (vals[1].length() != 0) {
					i->texInd = stoi(vals[1]) - 1;
				}
			}
			return i;
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

			glBindVertexArray(0);
		}

		void Mesh::render() {
			glBindVertexArray(m_vao);
			glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
			glBindVertexArray(0);
		}
	}
}