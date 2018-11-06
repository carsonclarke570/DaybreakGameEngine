#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "GameComponent.h"

#include "../graphics/SpriteRenderer.h"

namespace daybreak {

	namespace components {

		/**
			The Sprite class is a GameComponent that renders a sprite to the 
			screen.

			@author  Carson Clarke-Magrab
			@version 1.0
			@since   2018-11-03
		*/
		class Sprite : public GameComponent {
		private:
			/**
				The rendering engine for the sprite.
			*/
			SpriteRenderer* m_renderer;
			/**
				The texture of the sprite.
			*/
			Texture* m_texture;
			/**
				The shader for the sprite.
			*/
			Shader* m_shader;
		public:
			/**
				Creates a new Sprite object.

				@params texture The texture to render.
				@params shader The shader to run.
			*/
			Sprite(Texture* texture, Shader* shader);
			/**
				Destroys a Sprite object.
			*/
			~Sprite();
			/**
				[ Inherited from GameComponent ]
			*/
			void update(float delta);
			/**
				[ Inherited from GameComponent ]
			*/
			void render(Shader* shader);
			/**
				Sets the texture for rendering.

				@params texture The new texture
			*/
			void setTexture(Texture* texture);
		};
	}
}

#endif