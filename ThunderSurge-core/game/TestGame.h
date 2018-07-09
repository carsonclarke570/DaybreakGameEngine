#pragma once

#include "../thundersurge/core/math/math.h"

#include "../thundersurge/graphics/shader/shader.h"
#include "../thundersurge/graphics/shader/PhongShader.h"
#include "../thundersurge/graphics/renderer/Mesh.h"
#include "../thundersurge/graphics/renderer/Texture.h"

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
			Camera* camera;

			GameObject* root;
			GameObject* planet;
			GameObject* moon;

			float elapsed;
		public:
			TestGame() {
			} 

			~TestGame() {
			}

			void init() {

				root = new GameObject();
				shader = new PhongShader();
				elapsed = 0.0f;

				Mesh mesh = Mesh("C:/Users/birdi/3D Objects/res/models/cube.obj");

				camera = new Camera(vec3(0, 1, 0));
				Transform::setCamera(camera);

				Texture texture("C:/Users/birdi/3D Objects/res/textures/cube.jpg");
				Texture spec("C:/Users/birdi/3D Objects/res/textures/cube_specular.jpg");
				Material material = Material(texture, spec);

				DirectionalLight d;
				d.direction = vec3(-0.2f, -1.0f, -0.3f);
				d.base.ambient = vec3(0.05f, 0.05f, 0.05f);
				d.base.diffuse = vec3(0.4f, 0.4f, 0.4f);
				d.base.specular = vec3(0.5f, 0.5f, 0.5f);

				shader->setDirectionalLight(d);

				root->addComponent(new MeshRenderer(mesh, material));
				
				root->getTransform()->setScale(vec3(0.5, 0.5, 0.5));

				planet = new GameObject();
				planet->addComponent(new MeshRenderer(mesh, material));

				planet->getTransform()->setScale(vec3(0.2, 0.2, 0.2));

				root->addChild(planet);

				moon = new GameObject();
				moon->addComponent(new MeshRenderer(mesh, material));

				moon->getTransform()->setScale(vec3(0.1, 0.1, 0.1));

				planet->addChild(moon);
			}

			void update(float delta) {

				camera->update(delta);

				elapsed += delta;
				
				float e2 = 2 * elapsed;

				float sinDelta = sin(elapsed);
				float cosDelta = cos(elapsed);

				float s = sin(e2);
				float c = cos(e2);
				planet->getTransform()->setTranslation(vec3(sinDelta, 0, cosDelta));
				moon->getTransform()->setTranslation(vec3(s / 2, 0, c / 2));

				planet->getTransform()->setRotation(sinDelta * 180, vec3(1, 0, 0));
				moon->getTransform()->setRotation(sinDelta * 180, vec3(0, 1, 0));
				//std::cout << root->getTransform()->getScale() << std::endl;
				//transform->setScale(vec3(sinDelta, sinDelta, sinDelta));
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