#include "GameComponent.h"

#include "../graphics/Mesh.h"
#include "../graphics/Material.h"

#ifndef _MESH_RENDERER_H_
#define _MESH_RENDERER_H_

namespace daybreak {

	namespace components {

		using namespace graphics;

		class MeshRenderer : public GameComponent {
		private:
			Mesh* m_mesh;
			Material* m_material;
		public:
			MeshRenderer(Mesh* mesh, Material* material) 
				: m_mesh(mesh), m_material(material) {
			}

			~MeshRenderer() {
				//delete m_mesh;
				//delete m_material;
			}

			void update(float delta) { }

			void render(Shader* shader) {
				shader->enable();
				m_material->bind();
				shader->setUniformMat4("model", getTransform()->getTransform());
				shader->setUniform1i("material.diffuse", 0);
				shader->setUniform1i("material.specular", 1);
				shader->setUniform1f("material.specPow", m_material->getSpecularPower());
				m_mesh->render();
				m_material->unbind();
				shader->disable();
			}

			//void addToScene(Scene* scene) { }
		};
	}
}

#endif