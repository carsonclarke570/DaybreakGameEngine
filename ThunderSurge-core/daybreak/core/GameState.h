#ifndef _GAME_STATE_H_
#define _GAME_STATE_H_

#include "scene/Scene.h"

#include <map>

namespace daybreak {
	namespace core {

		/**
		 	The GameState class allows the user to load multiple game states to 
		 	memory and intuitively switch between them. Every game state will 
		 	have a list of Scene's that it can also intuitively switch between.
		 
		 	To understand the function of GameStates:
		 	Calling the load() function will call the respective GameState's 
		 	init() function, which (if the user implements properly) should 
		 	instantiate all data (Scenes, Objects, Classes, etc.). It then will
		 	be added to the list of loaded game states where it will remain in
		 	memory until the unload() function is called.
		 
		 	@author  Carson Clarke-Magrab
		 	@version 1.0
		 	@since   2018-10-09
		 */
		class GameState {
		private:

			/**
			 	The active state.
			 */
			static GameState* m_activeState;

			/**
			 	All states loaded into memory.
			 */
			static std::map<std::string, GameState*> m_states;

			/**
				All scene's associated with the game state
			*/
			std::map<std::string, Scene*> m_scenes;

			/**
				The active Scene
			*/
			Scene* m_activeScene;

			/**
				Initialize all data associated with the GameState.
			*/
			virtual void init();

			/**
				Destroy all data initialized/created during the course of the
				GameState's existence.
			*/
			virtual void dispose();

		public:

			/**
				Constructs a new GameState object.
			*/
			GameState();

			/**
				Destroys a GameState object.
			*/
			~GameState();

			/**
			 	Update logic within GameState
			 	
			 	@param delta The elapsed time since the previous frame
			 */
			virtual void update(float delta);

			/**
			 	Render associated objects to the screen.
			 */
			virtual void render();

			

			/**
			 	Calls the active state's update() function
			 
			 	@param delta The elapsed time since the previous frame
			 */
			void updateActive(float delta);

			/**
			 	Calls the active state's render() function
			 */
			void renderActive();

			/**
			 	Gets a state by name if it's been loaded into memory.
			 
			 	@param name Name of the GameState
			 	@return A pointer to the GameState or null if it doesn't exist.
			 */
			static GameState* get(std::string name);

			/**
			 	Sets the current state to a GameState loaded to memory.
			 
			 	@param name Name of the GameState
			 */
			static void set(std::string name);

			/**
			 	Loads a given GameState into memory by calling init()

				@param name The name the state will be refered to by
				@param state The state to load
				@return True if it sucessfully loads, otherwise false
			*/
			static bool load(std::string name, GameState* state);

			/**
				Unloads a given state from memory by calling dispose()

				@param name Name of the GameState
				@return True if it sucessfully unloaded, otherwise false
			*/
			static bool unload(std::string name);

			/**
				Adds a loaded scene into program memory

				@param name The name the scene will be refered
				@scene The scene to be loaded
				@return True if the scene loads properly, otherwise false
			*/
			bool loadScene(std::string name, Scene* scene);

			/**
				Unloads (deletes) a loaded scene from program memory.

				@param name The name of the scene
				@return True if the scene was succesfully unloaded, otherwise 
						false
			*/
			bool unloadScene(std::string name);

			/**
				Sets the active scene to a loaded scene.

				@param name The name of the scene to set
				@return True if the scene was set, false otherwise
			*/
			bool setScene(std::string name);
		};
	}
}

#endif

