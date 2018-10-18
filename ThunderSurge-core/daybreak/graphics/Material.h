#include "../core/math/math.h"
#include "Texture.h"

#ifndef _MATERIAL_H_
#define _MATERIAL_H_

namespace daybreak {

	namespace graphics {

		using namespace math;

		/**
		 *	The Material class handles the texture-mapping for 3-D modeling
		 *
		 *	A single material consists of three components:
		 *	- Diffuse Texture: Defines the color of the material
		 *	- Specular Texture: Defines which parts of the material are reflective
		 *	- Specular Power: Defines how reflective the material is (must be power of 2)
		 *
		 *	TO-DO:
		 *	- Add normal-mapping support
		 *
		 *	@author  Carson Clarke-Magrab
		 *	@version 1.0
		 *	@since   2018-10-09
		 */
		class Material {
		private:
			Texture m_diffuse;
			Texture m_specular;
			float m_specPow;
		public:
			/**
			 *	Material constructor.
			 *
			 *	@param diffuse The diffuse texture
			 *	@param specular The specular texture
			 *	@param float The specular power
			 *	@return A new Material object
			 */
			Material(const Texture& diffuse, const Texture& specular, float specPow)
				: m_diffuse(diffuse), m_specular(specular), m_specPow(specPow) {
			}

			/**
			 *	Material constructor.
			 *	Defaults specular power to 32.
			 *
			 *	@param diffuse The diffuse texture.
			 *	@param specular The specular texture.
			 *	@return A new Material object.
			 */
			Material(const Texture& diffuse, const Texture& specular)
				: m_diffuse(diffuse), m_specular(specular), m_specPow(32) {
			}

			/**
			 *	Material constructor.
			 *	Defaults specular power to 32.
			 *	Defaults specular texture to have no reflective quality.
			 *
			 *	@param diffuse The diffuse texture.
			 *	@return A new Material object.
			 */
			Material(const Texture& diffuse) 
				: m_diffuse(diffuse), m_specular(Texture("daybreak/res/defaults/no_spec_map.jpg")), m_specPow(32) {
			}

			/**
			 *	Material constructor.
			 *	Defaults specular power to 32.
			 *	Defaults specular texture to have no reflective quality.
			 *	Defaults diffuse texture to white.
			 *	
			 *	@return A new Material object.
			 */
			Material() 
				: m_diffuse(Texture("daybreak/res/defaults/no_diffuse_map.jpg")), m_specular(Texture("daybreak/res/defaults/no_spec_map.jpg")), m_specPow(32) {
			}

			/**
			 *	Makes this Material object the active material.
			 */
			void bind() {
				glActiveTexture(GL_TEXTURE0);
				m_diffuse.bind();
				glActiveTexture(GL_TEXTURE1);
				m_specular.bind();
			}

			/**
			 *	Stops this Material object from being the active material.
			 */
			void unbind() {
				glActiveTexture(GL_TEXTURE0);
				m_diffuse.unbind();
				m_specular.unbind();
			}

			/**
			 *	Returns the specular power.
			 *
			 *	@return The specular power.
			 */
			inline float getSpecularPower() const { return m_specPow; }
		};
	}
}

#endif
