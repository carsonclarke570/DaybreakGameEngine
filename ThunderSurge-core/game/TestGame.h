#pragma once

#include "../thundersurge/core/math/math.h"

#include "../thundersurge/graphics/shader/shader.h"
#include "../thundersurge/graphics/shader/PhongShader.h"
#include "../thundersurge/graphics/renderer/Mesh.h"
#include "../thundersurge/graphics/renderer/Texture.h"
#include "../thundersurge/graphics/buffer/VertexArray.h"
#include "../thundersurge/graphics/buffer/IndexBuffer.h"

#include "../thundersurge/core/input/input.h"

#include "../thundersurge/core/Game.h"
#include "../thundersurge/core/Transform.h"
#include "../thundersurge/core/GameObject.h"

#include "../thundersurge/components/GameComponent.h"
#include "../thundersurge/components/MeshRenderer.h"

namespace thundersurge {

	namespace core {

		using namespace math;
		using namespace graphics;
		using namespace input;
		using namespace components;

		class TestGame : public Game {
		private:
			PhongShader* shader;
			Transform* transform;
			Mesh* mesh;
			Camera* camera;
			Material* material;

			GameObject* root;

			float elapsed;
		public:
			TestGame() {
			} 

			~TestGame() {
			}

			void init() {

				root = new GameObject();

				shader = new PhongShader();
				//shader->enable();

				elapsed = 0.0f;

				mesh = new Mesh("C:/Users/birdi/3D Objects/res/models/cube.obj");
				transform = new Transform();
				transform->setScale(vec3(0.5f, 0.5f, 0.5f));

				camera = new Camera();
				transform->setCamera(camera);

				Texture texture("C:/Users/birdi/3D Objects/res/textures/cube.jpg");
				material = new Material(texture);

				DirectionalLight d;
				d.direction = vec3(-0.2f, -1.0f, -0.3f);
				d.base.ambient = vec3(0.05f, 0.05f, 0.05f);
				d.base.diffuse = vec3(0.4f, 0.4f, 0.4f);
				d.base.specular = vec3(0.5f, 0.5f, 0.5f);

				shader->setDirectionalLight(d);

				root->addComponent(new MeshRenderer(*mesh, *material));
			}

			void update(float delta) {

				camera->update(delta);

				elapsed += delta;

				float sinDelta = sin(elapsed);
				//transform->setScale(vec3(sinDelta, sinDelta, sinDelta));
				transform->setRotation(90.0f, vec3(0, 0, 1));
				transform->setRotation(-90.0f, vec3(1, 0, 0));
				//transform->setRotation(sinDelta * 180, vec3(0, 1, 0));
				root->updateAll(delta);
			}

			void render() {
				root->renderAll(shader);
				//shader->enable();
				//shader->update(*transform, *material);
				//mesh->render();
			}

			bool quit() {
				return false;
			}
		};
	}
}