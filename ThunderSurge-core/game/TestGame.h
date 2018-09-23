#pragma once

#include "../daybreak/graphics/shader.h"
#include "../daybreak/graphics/Mesh.h"
#include "../daybreak/graphics/Texture.h"
			
#include "../daybreak/core/input/input.h"
#include "../daybreak/core/math/math.h"
#include "../daybreak/core/noise/Noise.h"
			
#include "../daybreak/core/Game.h"
#include "../daybreak/core/Transform.h"
#include "../daybreak/core/GameObject.h"

#include "../daybreak/core/scene/SceneManager.h"
			
#include "../daybreak/components/GameComponent.h"
#include "../daybreak/components/MeshRenderer.h"
#include "../daybreak/components/Camera.h"
#include "../daybreak/components/FreeLook.h"
#include "../daybreak/components/FreeMove.h"
#include "Terrain.h"


namespace daybreak {

	namespace core {

		using namespace math;
		using namespace graphics;
		using namespace input;
		using namespace components;

		class TestGame : public Game {
		private:
			Scene* solar_system;
			Scene* ground;

			Light* dir;
			SpotLight* spot;

			GameObject* planet;
			GameObject* moon;
			GameObject* camera;
			GameObject* sol;
			GameObject* terrain;

			float elapsed, x;
		public:
			TestGame() {
			} 

			~TestGame() {
			}

			void init() {

				solar_system = new Scene();
				ground = new Scene();

				elapsed = 0.0f;
				
				camera = new GameObject();

				Mesh* mesh = new Mesh("C:/Users/birdi/3D Objects/res/models/cube.obj");

				camera->addComponent(new Camera(mat4::perspective(45.0f, 16.0f / 9.0f, 1e-6f, 1000.0f)));
				camera->addComponent(new FreeLook(10.0f));
				camera->addComponent(new FreeMove(1.0f));
				camera->getTransform()->translate(vec3(0, 0, 0));

				solar_system->addGameObject(camera);
				ground->addGameObject(camera);

				Texture texture("C:/Users/birdi/3D Objects/res/textures/cube.jpg");
				Texture spec("C:/Users/birdi/3D Objects/res/textures/cube.jpg");
				Material* material = new Material(texture);


				Skybox* sky = new Skybox(
					1000.0f,
					"C:/Users/birdi/3D Objects/res/textures/right.jpg", 
					"C:/Users/birdi/3D Objects/res/textures/left.jpg",
					"C:/Users/birdi/3D Objects/res/textures/top.jpg",
					"C:/Users/birdi/3D Objects/res/textures/bottom.jpg",
					"C:/Users/birdi/3D Objects/res/textures/front.jpg",
					"C:/Users/birdi/3D Objects/res/textures/back.jpg"
				);

				solar_system->addSkybox(sky); 

				BaseLight light;
				light.ambient = vec3(0.05f, 0.05f, 0.05f);
				light.diffuse = vec3(0.4f, 0.4f, 0.4f);
				light.specular = vec3(0.5f, 0.5f, 0.5f);

				dir = new DirectionalLight(light, vec3(-0.2f, -1.0f, -0.3f));
				
				BaseLight light2;
				light2.ambient = vec3(0.0f, 0.0f, 0.0f);
				light2.diffuse = vec3(1.0f, 1.0f, 1.0f);
				light2.specular = vec3(1.0f, 1.0f, 1.0f);

				Attenuation attn;
				attn.constant = 1.0f;
				attn.linear = 0.09f;
				attn.quadratic = 0.032f;

				spot = new SpotLight(light2, attn, camera->getTransform()->getTranslation(), camera->getTransform()->getRotation().getForward(), cos(toRadians(12.5f)), cos(toRadians(15.0f)));
				
				BaseLight light3;
				light3.ambient = vec3(0.05f, 0.05f, 0.05f);
				light3.diffuse = vec3(0.8f, 0.8f, 0.8f);
				light3.specular = vec3(1.0f, 1.0f, 1.0f);

				Attenuation attn2;
				attn2.constant = 1.0f;
				attn2.linear = 0.09f;
				attn2.quadratic = 0.032f;

				Light* point = new PointLight(light3, attn2, vec3(0, 1, 0));
				
				//solar_system->addLight(point);
				solar_system->addLight(spot);
				solar_system->addLight(dir);
				ground->addLight(dir);

				sol = new GameObject();
				sol->addComponent(new MeshRenderer(mesh, material, new Shader("daybreak/graphics/shaders/forward-lighting.vert", "game/res/shaders/red.frag")));
				sol->getTransform()->setScale(vec3(0.2, 0.2, 0.2));

				solar_system->addGameObject(sol);

				planet = new GameObject();
				planet->addComponent(new MeshRenderer(mesh, material));

				planet->getTransform()->setScale(vec3(0.2, 0.2, 0.2));

				sol->addChild(planet);

				moon = new GameObject();
				moon->addComponent(new MeshRenderer(mesh, material));

				moon->getTransform()->setScale(vec3(0.1, 0.1, 0.1));

				planet->addChild(moon);

				terrain = new GameObject();
				terrain->addComponent(new Terrain("game/res/maps/test-level.txt"));
				terrain->getTransform()->translate(vec3(0, -2, 0));

				ground->addGameObject(terrain);
				solar_system->addGameObject(terrain);

				SceneManager::add("Sol", solar_system);
				SceneManager::add("Ter", ground);
				SceneManager::setActive("Sol");
				//PostFX::setPostFX(new Shader("game/res/shaders/postfx.vert", "game/res/shaders/postfx.frag", NULL, false));
			}

			void update(float delta) {
				elapsed += delta;
				
				float e2 = 2 * elapsed;

				float sinDelta = sin(elapsed);
				float cosDelta = cos(elapsed);

				float s = sin(e2);
				float c = cos(e2);
				planet->getTransform()->setTranslation(vec3(2 * sinDelta, 0, 2 * cosDelta));
				moon->getTransform()->setTranslation(vec3(s / 2, 0, c / 2));
				//sol->getTransform()->setTranslation(vec3(0, 1, 0));

				sol->getTransform()->setRotation(sinDelta * 180, vec3(0, 0, 1));
				planet->getTransform()->setRotation(sinDelta * 180, vec3(1, 0, 0));
				moon->getTransform()->setRotation(sinDelta * 180, vec3(0, 1, 0));

				spot->position = camera->getTransform()->getTranslation();
				spot->direction = camera->getTransform()->getRotation().getForward();

				x += delta;

				if (Keyboard::isKeyPressed(KEY_C)) {
					x = 0.0f;
					if (SceneManager::getActive().compare("Sol") == 0) {
						SceneManager::setActive("Ter");
					} else if (SceneManager::getActive().compare("Ter") == 0) {
						SceneManager::setActive("Sol");
					}
				}

				SceneManager::update(delta);
			}

			void render() {
				SceneManager::render();
			}

			bool quit() {
				return false;
			}
		};
	}
}