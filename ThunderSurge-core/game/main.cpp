#include "../daybreak/core/Daybreak.h"
#include "../daybreak/utils/fileutils.h"
#include "TestGame.h"

#include "../daybreak/core/ui/UIElement.h"


int main() {
	using namespace daybreak;
	using namespace core;

	Game* g = new TestGame();

	Daybreak::load(g);
	Daybreak::start();

	UIElement* element = new UIElement();

	return 0;
}