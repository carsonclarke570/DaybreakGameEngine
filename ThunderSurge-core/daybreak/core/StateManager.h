#ifndef _STATE_MANAGER_H_
#define	_STATE_MANAGER_H_

#include "GameState.h"

namespace daybreak {

	namespace core {

		/**
			The GameManager class allows the user to load multiple GameStates to
			memory and intuitively switch between them.

			To understand the function of GameStates:
			Calling the load() function will call the respective GameState's
			init() function, which (if the user implements properly) should
			instantiate all data (Scenes, Objects, Classes, etc.). It then will
			be added to the list of loaded game states where it will remain in
			memory until the unload() function is called.

			@author  Carson Clarke-Magrab
			@version 1.0
			@since   2018-10-21
		 */
		class StateManager {

		private:

			/**
				The active state.
			 */
			static GameState* m_activeState;

		public:
			
			/**
				Changes the active state. Calls dispose() on the old state 
				before calling init()

				@param state The new state to enter.
			*/
			static void change(GameState* state);

			/**
				Updates the active GameState.

				@param delta The time since the last update call
			*/
			static void update(float delta);

			/**
				Renders the active GameState.
			*/
			static void render();
		};
	}
}

#endif 
