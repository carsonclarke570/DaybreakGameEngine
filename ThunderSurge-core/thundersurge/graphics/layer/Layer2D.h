#pragma once

#include "Layer.h"
#include "../renderer/2d/BatchRenderer2D.h"

namespace thundersurge {

	namespace graphics {

		class Layer2D : public Layer {
		public:
			Layer2D(Shader* shader);
			~Layer2D();
		};
	}
}