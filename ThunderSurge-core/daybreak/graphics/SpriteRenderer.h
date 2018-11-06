#ifndef _SPRITE_RENDERER_H_
#define _SPRITE_RENDERER_H_

#include "Shader.h"

namespace daybreak {

	namespace graphics { 

		/**
			The SpriteRenderer class implements a backend system for rendering 
			individual sprite objects to the screen.

			@author  Carson Clarke-Magrab
			@version 1.0
			@since   2018-11-03
		 */
		class SpriteRenderer {
		private:
			/**
				The vertex array object for the sprite
			*/
			GLuint m_vao;
		public:
			/**
				Creates a new SpriteRenderer Object
			*/
			SpriteRenderer();
			/**
				Destroys a SpriteRenderer Object
			*/
			~SpriteRenderer();
			/**
				Renders a sprite to the screen using a specific shader and
				transformation.

				@params texture The texture of the sprite
				@params shader The shader to be computed on the sprite
				@params transform A transformation definining the postion, 
						scale and rotation of the sprite
			*/
			void render(Texture* texture, Shader* shader, Transform* transform);
		private:
			/**
				Initializes buffer data
			*/
			void init();
		};
	}
}

#endif
