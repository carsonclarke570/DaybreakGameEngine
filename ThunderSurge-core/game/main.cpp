#include "../thundersurge/core/CoreEngine.h"
#include "TestGame.h"

int main()
{
	using namespace thundersurge;
	using namespace core;

	Game* g = new TestGame();

	CoreEngine* engine = new CoreEngine(g);
	engine->start();

	return 0;
}