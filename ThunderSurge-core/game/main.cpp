#include "../thundersurge/core/CoreEngine.h"
#include "TestGame.h"

#include "../thundersurge/utils/fileutils.h"

int main()
{
	using namespace thundersurge;
	using namespace core;

	Game* g = new TestGame();

	CoreEngine* engine = new CoreEngine(g);
	engine->start();

	return 0;
}