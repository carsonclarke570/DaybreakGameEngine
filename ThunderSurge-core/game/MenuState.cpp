#include "MenuState.h"

#include "../daybreak/components/MeshRenderer.h"
#include "../daybreak/components/Camera.h"
#include "../daybreak/components/FreeLook.h"
#include "../daybreak/components/FreeMove.h"

using namespace daybreak;
using namespace core;
using namespace components;

Scene* m_scene;
GameObject* m_cube;
GameObject* m_camera;
GameObject* m_sprite;
	 
MenuState::MenuState() : GameState() {

}

void MenuState::init() {
	m_scene = new Scene();

	// CAMERA

	m_camera = new GameObject();
	m_camera->addComponent(new Camera(mat4::perspective(90.0f, 16.0f / 9.0f, 0.1, 1000.0f)));
	m_camera->addComponent(new FreeLook(10.0f));
	//m_camera->addComponent(new FreeMove(1.0f));
	m_camera->getTransform()->translate(vec3(0, 0, 1));
	m_scene->addGameObject(m_camera);

	// CUBE

	m_cube = new GameObject();
	m_cube->addComponent(new MeshRenderer(new Mesh("C:/Users/birdi/source/repos/DaybreakGameEngine/ThunderSurge-core/game/res/models/cube.obj"), new Material(Texture("C:/Users/birdi/source/repos/DaybreakGameEngine/ThunderSurge-core/game/res/textures/crate.jpg"))));
	m_scene->addGameObject(m_cube);

	// SPRITE

	/*m_sprite = new GameObject();
	m_sprite->addComponent(new Sprite()); */

	// LIGHTING

	BaseLight light;
	light.ambient = vec3(0.05f, 0.05f, 0.05f);
	light.diffuse = vec3(0.4f, 0.4f, 0.4f);
	light.specular = vec3(0.5f, 0.5f, 0.5f);
	Light* dir = new DirectionalLight(light, vec3(-0.2f, -1.0f, -0.3f));
	m_scene->addLight(dir); 
}

void MenuState::dispose() {
	delete m_scene;
}

void MenuState::update(float delta) {
	
	m_scene->update(delta);
	m_cube->getTransform()->rotate(delta * 20.0f, vec3(0, 1, 0));
}

void MenuState::render() {
	m_scene->render();
}