#include "Layer2D.h"

namespace thundersurge {

	namespace graphics {

		Layer2D::Layer2D(Shader* shader)
			: Layer(new BatchRenderer2D(), shader, math::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f)) {
		}

		Layer2D::~Layer2D() {
			
		}
	}
}