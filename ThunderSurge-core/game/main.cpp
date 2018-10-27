#include "../daybreak/core/Daybreak.h"
#include "TestGame.h"


int main() {
	using namespace daybreak;
	using namespace core;

	Game* g = new TestGame();

	Daybreak::load(g);
	Daybreak::start();

	return 0;
}