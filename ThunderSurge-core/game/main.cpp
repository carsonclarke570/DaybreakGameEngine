#include "../aurora/core/CoreEngine.h"
#include "TestGame.h"

#include "../aurora/utils/fileutils.h"

int main()
{
	using namespace aurora;
	using namespace core;

	Game* g = new TestGame();

	CoreEngine* engine = new CoreEngine(g);
	engine->start();

	return 0;
}