#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include "../daybreak/core/GameState.h"

using namespace daybreak;
using namespace core;

class MenuState : public GameState {
private:
	Scene* m_scene;
public:
	MenuState();

	void init();
	void dispose();

	void update(float delta);
	void render();
};

#endif