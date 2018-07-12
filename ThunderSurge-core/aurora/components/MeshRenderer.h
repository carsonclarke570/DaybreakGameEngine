#include "GameComponent.h"

#include "../graphics/renderer/Mesh.h"
#include "../graphics/renderer/Material.h"

#ifndef _MESH_RENDERER_H_
#define _MESH_RENDERER_H_

namespace aurora {

	namespace components {

		using namespace graphics;

		class MeshRenderer : public GameComponent {
		private:
			Mesh m_mesh;
			Material m_material;
		public:
			MeshRenderer(const Mesh& mesh, const Material& material) 
				: m_mesh(mesh), m_material(material) {
			}

			void update(float delta) {}

			void render(Shader* shader) {
				shader->enable();
				shader->update(getTransform(), m_material);
				m_mesh.render();
			}
		};
	}
}

#endif