#ifndef _SKYBOX_H_
#define _SKYBOX_H_

#include "GameComponent.h"

namespace daybreak {

	namespace graphics {

		using namespace std;

		class Skybox : public GameComponent {
		private:
			GLuint m_id, m_vao, m_vbo;

			GLuint load(vector<string> faces) {

				vector<vec3> cubemap {
					vec3(-1.0f,  1.0f, -1.0f),
					vec3(-1.0f, -1.0f, -1.0f),
					vec3(1.0f, -1.0f, -1.0f),
					vec3(1.0f, -1.0f, -1.0f),
					vec3(1.0f,  1.0f, -1.0f),
					vec3(-1.0f,  1.0f, -1.0f),

					vec3(-1.0f, -1.0f,  1.0f),
					vec3(-1.0f, -1.0f, -1.0f),
					vec3(-1.0f,  1.0f, -1.0f),
					vec3(-1.0f,  1.0f, -1.0f),
					vec3(-1.0f,  1.0f,  1.0f),
					vec3(-1.0f, -1.0f,  1.0f),

					vec3(1.0f, -1.0f, -1.0f),
					vec3(1.0f, -1.0f,  1.0f),
					vec3(1.0f,  1.0f,  1.0f),
					vec3(1.0f,  1.0f,  1.0f),
					vec3(1.0f,  1.0f, -1.0f),
					vec3(1.0f, -1.0f, -1.0f),

					vec3(-1.0f, -1.0f,  1.0f),
					vec3(-1.0f,  1.0f,  1.0f),
					vec3(1.0f,  1.0f,  1.0f) ,
					vec3(1.0f,  1.0f,  1.0f) ,
					vec3(1.0f, -1.0f,  1.0f) ,
					vec3(-1.0f, -1.0f,  1.0f),

					vec3(-1.0f,  1.0f, -1.0f),
					vec3(1.0f,  1.0f, -1.0f),
					vec3(1.0f,  1.0f,  1.0f),
					vec3(1.0f,  1.0f,  1.0f),
					vec3(-1.0f,  1.0f,  1.0f),
					vec3(-1.0f,  1.0f, -1.0f),

					vec3(-1.0f, -1.0f, -1.0f),
					vec3(-1.0f, -1.0f,  1.0f),
					vec3(1.0f, -1.0f, -1.0f),
					vec3(1.0f, -1.0f, -1.0f),
					vec3(-1.0f, -1.0f,  1.0f),
					vec3(1.0f, -1.0f,  1.0f	)
				};

				glGenVertexArrays(1, &m_vao);
				glGenBuffers(1, &m_vbo);

				glBindVertexArray(m_vao);
				glBindBuffer(GL_ARRAY_BUFFER, m_vbo);

				glBufferData(GL_ARRAY_BUFFER, sizeof(cubemap), &cubemap[0], GL_STATIC_DRAW);
				glEnableVertexAttribArray(0);
				glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

				glGenTextures(1, &m_id);
				glBindTexture(GL_TEXTURE_CUBE_MAP, m_id);

				int w, h;
				for (unsigned int i = 0; i < faces.size(); i++) {
					BYTE* pixels = loadImage(faces[i].c_str(), &w, &h);
					if (pixels) {
						glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, pixels);
					}
					else {
						std::string stuff = "Falied to load skymap texture: " + faces[i];
						Log::logErr(stuff.c_str());
					}
				}

				glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
				glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
				glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

			}
		public:
			Skybox(string right, string left, string top, string bottom, string front, string back) {
				load(vector<string> { right, left, top, bottom, front, back });
			}

			void update(float delta) {

			}

			void render(Shader* shader) {

			}

			//void addToScene(Scene* scene) { }
		};
	}
}

#endif
