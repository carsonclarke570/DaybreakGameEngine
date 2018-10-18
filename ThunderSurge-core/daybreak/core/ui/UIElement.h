#ifndef _UI_ELEMENT_H_
#define _UI_ELEMENT_H_

#include "../math/math.h"

namespace daybreak {
	namespace core {

		/**
		 	The UIElement handles generalizing individual UI components
		 
		 	A UIElement can have any number of children components that all 
			inherit a relative transformation from their parent. 

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
				Parent UIElement pointer
			*/
			UIElement* m_parent;

			/**
				List of all child elements
			*/
			std::vector<UIElement*> m_children;

			/**
				The inherited transform of the object.
				It is simply the aggregate of all its parents transforms
			*/
			vec2 m_transform;
		public:
			/**
				Create a new UIElement object
			*/
			UIElement();

			/**
				Delete a UIElement 

				TO-DO: Design a intelligent way to automatically delete all
				       child objects
			*/
			virtual ~UIElement();

			
			/**
				Inherited function to handle updating the UIElement

				@param The time passed since the previous frame
			*/
			virtual void update(float delta);

			/**
				Inherited function to handle rendering the UIElement
			*/
			virtual void render();

			/**
				Updates this UIElement and then all of its children

				@param The time passed since the previous frame
			*/
			void updateAll(float delta);

			/**
				Renders this UIElement and then all of its children
			*/
			void renderAll();
		};
	}
}

#endif