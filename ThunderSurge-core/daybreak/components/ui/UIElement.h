#ifndef _UI_ELEMENT_H_
#define _UI_ELEMENT_H_

#include "../../core/Math.h"
#include "../../core/Transform.h"

#include "UIContainer.h"

#include <vector>

namespace daybreak {

	namespace components {

		using namespace core;

		/**
		 	The UIElement handles generalizing individual UI components

			Examples of UIElement
			- Buttons
			- Text

			NOTES:
			- For simplicity sake each individual UIElemenet will, for now,
			  render itself instead of submitting to a batch renderer
		 
		 	@author  Carson Clarke-Magrab
		 	@version 1.0
		 	@since   2018-10-18
		 */
		class UIElement {
		private:
			/**
				The transform of the UIElement
			*/
			Transform* m_transform;
			/**
				The parent UIContainer
			*/
			UIContainer* m_parent;
		public:
			/**
				Create a new UIElement object
			*/
			UIElement();

			/**
				Delete a UIElement 
			*/
			~UIElement();
			
			/**
				Inherited function to handle updating the UIElement

				@param The time passed since the previous frame
			*/
			virtual void update(float delta) = 0;
			/**
				Inherited function to handle rendering the UIElement
			*/
			virtual void render() = 0;
			/**
				Get's the UIElement's transform by applying the parent 
				transformation matrix to this element's matrix.

				@returns A transfromation matrix
			*/
			mat4& getTransform();
		};
	}
}

#endif