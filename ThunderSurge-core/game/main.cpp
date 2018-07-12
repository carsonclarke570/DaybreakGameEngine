#include "../daybreak/core/CoreEngine.h"
#include "TestGame.h"

#include "../daybreak/utils/fileutils.h"

int main()
{
	using namespace daybreak;
	using namespace core;

	Game* g = new TestGame();

	CoreEngine* engine = new CoreEngine(g);
	engine->start();

	return 0;
}