#pragma once

#include "../renderer/2d/Renderer2D.h"
#include "../renderer/2d/Renderable2D.h"

namespace thundersurge {

	namespace graphics {
		
		class Layer {
		protected:
			Renderer2D* m_renderer;
			std::vector<Renderable2D*> m_renderables;
			Shader* m_shader;
			math::mat4 m_projection;

			Layer(Renderer2D* renderer, Shader* shader, math::mat4 projection);
		public:
			virtual ~Layer();
			virtual void add(Renderable2D* renderable);
			virtual void render();
		};
	}
}