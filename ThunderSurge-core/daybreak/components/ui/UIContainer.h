#ifndef _UI_CONTAINER_H_
#define _UI_CONTAINER_H_

#include "../GameComponent.h"

namespace daybreak {
	
	namespace components {

		class UIElement;

		/**
		 	The UIContainer class bundles multiple UIElements.
		 
		 	@author  Carson Clarke-Magrab
		 	@version 1.0
		 	@since   2018-11-01
		*/
		class UIContainer : public GameComponent {
		private:
			/**
				The children elements of the UIContainer
			*/
			std::vector<UIElement*> m_elements;
		public:
			/**
				Create a new UIContainer object
			*/
			UIContainer();
			/**
				Delete a UIContainer object
			*/
			~UIContainer();
			/**
				[ Inherited from GameComponent ]
			*/
			void render(Shader* shader);
			/**
				[ Inherited from GameComponent ]
			*/
			void update(float delta);
			/**
				Adds a UIElement to the the container.

				@params element The UIElement to add
			*/
			void addElement(UIElement* element);
		};
	}
}

#endif
