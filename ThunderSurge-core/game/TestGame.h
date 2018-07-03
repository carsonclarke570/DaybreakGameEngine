#pragma once

#include "../thundersurge/core/math/math.h"

#include "../thundersurge/graphics/shader/shader.h"
#include "../thundersurge/graphics/shader/PhongShader.h"
#include "../thundersurge/graphics/shader/BasicShader.h"
#include "../thundersurge/graphics/renderer/Mesh.h"
#include "../thundersurge/graphics/renderer/Texture.h"
#include "../thundersurge/graphics/buffer/VertexArray.h"
#include "../thundersurge/graphics/buffer/IndexBuffer.h"

#include "../thundersurge/core/input/input.h"

#include "../thundersurge/core/Game.h"
#include "../thundersurge/core/Transform.h"

namespace thundersurge {

	namespace core {

		using namespace math;
		using namespace graphics;
		using namespace input;

		class TestGame : public Game {
		private:
			PhongShader* shader;
			Transform* transform;
			Mesh* mesh;
			Camera* camera;
			Material* material;

			float elapsed;
		public:
			TestGame() {
			} 

			~TestGame() {
			}

			void init() {
				shader = new PhongShader();
				//shader->enable();

				elapsed = 0.0f;

				Vertex v;
				std::vector<Vertex> vert(8, v);
				vert[0].pos = vec3(-0.5, -0.5,  0.5);
				vert[1].pos = vec3( 0.5, -0.5,  0.5);
				vert[2].pos = vec3( 0.5,  0.5,  0.5);
				vert[3].pos = vec3(-0.5,  0.5,  0.5);
				vert[4].pos = vec3(-0.5, -0.5, -0.5);
				vert[5].pos = vec3( 0.5, -0.5, -0.5);
				vert[6].pos = vec3( 0.5,  0.5, -0.5);
				vert[7].pos = vec3(-0.5,  0.5, -0.5);

				GLuint indices[] = {
					0, 1, 2,
					2, 3, 0,
					// right
					1, 5, 6,
					6, 2, 1,
					// back
					7, 6, 5,
					5, 4, 7,
					// left
					4, 0, 3,
					3, 7, 4,
					// bottom
					4, 5, 1,
					1, 0, 4,
					// top
					3, 2, 6,
					6, 7, 3,
				};

				std::vector<GLuint> ind(indices, indices + sizeof(indices) / sizeof(GLuint));

				mesh = new Mesh("C:/Users/birdi/3D Objects/models/guitar.obj");
				transform = new Transform();
				transform->setScale(vec3(0.5f, 0.5f, 0.5f));

				camera = new Camera();
				transform->setCamera(camera);

				Texture texture("C:/Users/birdi/3D Objects/models/capsule.jpg");
				material = new Material(texture);

				DirectionalLight d;
				d.base.color = vec3(1, 1, 1);
				d.base.intensity = 1.0f;
				d.direction = vec3(0, 1, 0);

				shader->setDirectionalLight(d);
			}

			void update(float delta) {

				camera->update(delta);

				elapsed += delta;

				float sinDelta = sin(elapsed);
				//transform->setScale(vec3(sinDelta, sinDelta, sinDelta));
				transform->setRotation(sinDelta * 180, vec3(0, 1, 0));
			}

			void render() {
				shader->enable();
				shader->update(transform->getTransform(), transform->getProjectedTransform(), *material);
				mesh->render();
			}

			bool quit() {
				return false;
			}
		};
	}
}