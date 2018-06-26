#pragma once

#include "../../renderer/2d/Renderable2D.h"

namespace thundersurge {

	namespace graphics {
		
		class Sprite : public Renderable2D {
		private:
				
		public:
			Sprite(float x, float y, float width, float height, const math::vec4& color);
		};
	}
}