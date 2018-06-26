#pragma once

#include "../thundersurge/core/math/math.h"

#include "../thundersurge/graphics/shader/shader.h"
#include "../thundersurge/graphics/layer/Layer2D.h"
#include "../thundersurge/graphics/entity/2d/Sprite.h"
#include "../thundersurge/graphics/entity/3d/Mesh.h"
#include "../thundersurge/graphics/buffer/VertexArray.h"
#include "../thundersurge/graphics/buffer/IndexBuffer.h"

#include "../thundersurge/core/input/input.h"

#include "../thundersurge/core/Game.h"

namespace thundersurge {

	namespace core {

		using namespace math;
		using namespace graphics;
		using namespace input;

		class TestGame : public Game {
		private:
			Shader * shader;

			Mesh* mesh;
		public:
			TestGame() {
			} 

			~TestGame() {
			}

			void init() {
				shader = new Shader("thundersurge/graphics/shader/shaders/basic.vert", "thundersurge/graphics/shader/shaders/basic.frag");
				//shader->enable();

				Vertex v;
				std::vector<Vertex> vert(8, v);
				vert[0].pos = vec3(-0.5, -0.5, -0.5);
				vert[1].pos = vec3(-0.5, 0.5, -0.5);
				vert[2].pos = vec3(0.5, 0.5, -0.5);
				vert[3].pos = vec3(0.5, -0.5, -0.5);
				vert[4].pos = vec3(0.5, -0.5, 0.5);
				vert[5].pos = vec3(0.5, 0.5, 0.5);
				vert[6].pos = vec3(-0.5, 0.5, 0.5);
				vert[7].pos = vec3(-0.5, -0.5, 0.5);

				GLuint indices[] = {
					0, 1, 3, //   1: face arrière
					0, 2, 3,
					3, 2, 5, //   2: face droite
					3, 5, 4,
					5, 2, 1, //   3: face dessue
					5, 1, 6,
					3, 4, 7, //   4: face dessous
					3, 7, 0,
					0, 7, 6, //   5: face gauche
					0, 6, 1,
					4, 5, 6, //   6: face avant
					4, 6, 7
				};

				std::vector<GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));

				mesh = new Mesh(vert, ind);
			}

			void update() {
				double x, y;
				Mouse::getMousePosition(x, y);
			}

			void render() {
				//shader->enable();
				// draw mesh
				mesh->render();
			}
		};
	}
}