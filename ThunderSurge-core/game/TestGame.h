#pragma once

#include "../aurora/core/math/math.h"
			
#include "../aurora/graphics/shader/shader.h"
#include "../aurora/graphics/shader/PhongShader.h"
#include "../aurora/graphics/renderer/Mesh.h"
#include "../aurora/graphics/renderer/Texture.h"
			 
#include "../aurora/core/input/input.h"
			
#include "../aurora/core/Game.h"
#include "../aurora/core/Transform.h"
#include "../aurora/core/GameObject.h"
		
#include "../aurora/components/GameComponent.h"
#include "../aurora/components/MeshRenderer.h"
#include "../aurora/components/Camera.h"
#include "../aurora/components/FreeLook.h"
#include "../aurora/components/FreeMove.h"
#include "../aurora/components/Terrain.h"

namespace aurora {

	namespace core {

		using namespace math;
		using namespace graphics;
		using namespace input;
		using namespace components;

		class TestGame : public Game {
		private:
			PhongShader* shader;

			GameObject* root;
			GameObject* planet;
			GameObject* moon;
			GameObject* camera;
			GameObject* sol;
			GameObject* terrain;

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

				camera = new GameObject();

				Mesh mesh = Mesh("C:/Users/birdi/3D Objects/res/models/cube.obj");

				camera->addComponent(new Camera(mat4::perspective(70.0f, 16.0f / 9.0f, 0.1f, 1000.0f)));
				camera->addComponent(new FreeLook(1.0f));
				camera->addComponent(new FreeMove(1.0f));
				camera->getTransform()->translate(vec3(0, 1, 0));

				root->addChild(camera);

				Texture texture("C:/Users/birdi/3D Objects/res/textures/cube.jpg");
				Texture spec("C:/Users/birdi/3D Objects/res/textures/cube_specular.jpg");
				Material material = Material(texture, spec);

				DirectionalLight d;
				d.direction = vec3(-0.2f, -1.0f, -0.3f);
				d.base.ambient = vec3(0.05f, 0.05f, 0.05f);
				d.base.diffuse = vec3(0.4f, 0.4f, 0.4f);
				d.base.specular = vec3(0.5f, 0.5f, 0.5f);

				shader->setDirectionalLight(d);

				sol = new GameObject();
				sol->addComponent(new MeshRenderer(mesh, material));
				sol->getTransform()->setScale(vec3(0.5, 0.5, 0.5));

				root->addChild(sol);

				planet = new GameObject();
				planet->addComponent(new MeshRenderer(mesh, material));

				planet->getTransform()->setScale(vec3(0.2, 0.2, 0.2));

				sol->addChild(planet);

				moon = new GameObject();
				moon->addComponent(new MeshRenderer(mesh, material));

				moon->getTransform()->setScale(vec3(0.1, 0.1, 0.1));

				planet->addChild(moon);

				terrain = new GameObject();
				terrain->addComponent(new Terrain(0, 0, material));

				root->addChild(terrain);
			}

			void update(float delta) {
				elapsed += delta;
				
				float e2 = 2 * elapsed;

				float sinDelta = sin(elapsed);
				float cosDelta = cos(elapsed);

				float s = sin(e2);
				float c = cos(e2);
				sol->getTransform()->setTranslation(vec3(sinDelta, 1, 0));
				planet->getTransform()->setTranslation(vec3(sinDelta, 0, cosDelta));
				moon->getTransform()->setTranslation(vec3(s / 2, 0, c / 2));

				sol->getTransform()->setRotation(sinDelta * 180, vec3(0, 0, 1));
				planet->getTransform()->setRotation(sinDelta * 180, vec3(1, 0, 0));
				moon->getTransform()->setRotation(sinDelta * 180, vec3(0, 1, 0));
				//std::cout << root->getTransform()->getScale() << std::endl;
				//transform->setScale(vec3(sinDelta, sinDelta, sinDelta));
				//transform->setRotation(sinDelta * 180, vec3(0, 1, 0));
				root->updateAll(delta);

				std::cout << camera->getTransform()->getRotation().getRight() << std::endl;
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