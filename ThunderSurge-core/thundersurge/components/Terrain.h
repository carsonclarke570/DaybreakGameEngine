#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include "../graphics/renderer/Mesh.h"
#include "../graphics/renderer/Texture.h"

#include "GameComponent.h"

namespace thundersurge {

	namespace components {

		class Terrain : public GameComponent {
		private:
			static const float SIZE;
			static const int VERTEX_COUNT;

			float m_x, m_y;
			Mesh m_mesh;
			Texture m_texture;
		public:

			void update(float delta) {}
			void render(Shader* shader) {}
		};
	}
}

#endif
