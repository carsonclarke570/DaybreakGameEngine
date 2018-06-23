#include "src/graphics/window.h"
#include "src/graphics/shader/shader.h"
#include "src/math/math.h"

#include "src/graphics/buffer/buffer.h"
#include "src/graphics/buffer/indexbuffer.h"
#include "src/graphics/buffer/vertexarray.h"

#include "src/graphics/renderer/renderer2d.h"
#include "src/graphics/renderer/simplerenderer2d.h"
#include "src/graphics/renderer/batchrenderer2d.h"

#include "src/graphics/staticsprite.h"
#include "src/graphics/sprite.h"
#include "src/utils/Timer.h"

#include "src/graphics/layer/Layer2D.h"

#include <time.h>

#define BATCH_RENDERER 1

int main()
{
	using namespace thundersurge;
	using namespace graphics;
	using namespace math;

	Window window("FITE ME", 960, 540);
	// glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	Mouse::init();
	Keyboard::init();

	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	Shader* s1 = new Shader("src/graphics/shader/shaders/basic.vert", "src/graphics/shader/shaders/basic.frag");
	Shader* s2 = new Shader("src/graphics/shader/shaders/basic.vert", "src/graphics/shader/shaders/basic.frag");

	Shader& shader = *s1;
	Shader& shader2 = *s2;

	shader.enable();
	shader2.enable();

	Layer2D layer(&shader);
	for (float y = -9.0f; y < 9.0f; y += 0.1) {
		for (float x = -16.0f; x < 16.0f; x += 0.1) {
			layer.add(new Sprite(x, y, 0.09f, 0.09f, math::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

	Layer2D layer2(&shader2);
	layer2.add(new Sprite(-2, -2, 4, 4, math::vec4(1, 0, 1, 1)));


	Timer time;
	float t = 0;
	unsigned int frames = 0;

	while (!window.closed())
	{
		window.clear();
		double x, y;
		Mouse::getMousePosition(x, y);
		//shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
	
		shader.enable();
		shader2.setUniform2f("light_pos", vec2(-8, -3));
		shader2.enable();
		shader2.setUniform2f("light_pos", vec2((float)(x * 32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));

		layer.render();
		layer2.render();

		window.update();

		frames++;
		if (time.elapsed() - t > 1.0f) {
			t++;
			printf("FPS: %d\n", frames);
			frames = 0;
		}
	}

	return 0;
}