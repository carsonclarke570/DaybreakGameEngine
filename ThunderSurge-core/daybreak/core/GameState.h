#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

#include "scene/Scene.h"

#include <map>

namespace daybreak {
	namespace core {

		/**
		 	The GameState class allows the user to generalize gameplay across
			multiple states.
		 
		 	@author  Carson Clarke-Magrab
		 	@version 1.0
		 	@since   2018-10-09
		 */
		class GameState {
		public:

			/**
			 	Update logic within GameState
			 	
			 	@param delta The elapsed time since the previous frame
			 */
			virtual void update(float delta) = 0;

			/**
			 	Render associated objects to the screen.
			 */
			virtual void render() = 0;

			/**
				Initialize all data associated with the GameState.
			*/
			virtual void init() = 0;

			/**
				Destroy all data initialized/created during the course of the
				GameState's existence.
			*/
			virtual void dispose() = 0;
		};
	}
}

#endif

