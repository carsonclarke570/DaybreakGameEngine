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

#include <time.h>
#include <map>

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

	Shader shader("src/graphics/shader/shaders/basic.vert", "src/graphics/shader/shaders/basic.frag");
	shader.enable();
	shader.setUniformMat4("pr_mat", ortho);
	
	std::vector<Renderable2D*> sprites;

	srand(time(NULL));
	
	for (float y = 0; y < 9.0f; y += 0.05) {
		for (float x = 0; x < 16.0f; x += 0.05) {
			sprites.push_back(new
#if BATCH_RENDERER
			Sprite
#else
			StaticSprite
#endif
			(x, y, 0.04f, 0.04f, math::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)
#if !BATCH_RENDERER
			, shader
#endif
			));
		}
	}
		
#if BATCH_RENDERER
	Sprite sprite(5, 5, 4, 4, math::vec4(1, 0, 1, 1));
	Sprite sprite2(7, 1, 2, 3, math::vec4(0.2f, 0, 1, 1));
	BatchRenderer2D renderer;
#else
	StaticSprite sprite(5, 5, 4, 4, math::vec4(1, 0, 1, 1), shader);
	StaticSprite sprite2(7, 1, 2, 3, math::vec4(0.2f, 0, 1, 1), shader);
	SimpleRenderer2D renderer;
#endif

	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader.setUniform4f("colour", vec4(0.2f, 0.3f, 0.8f, 1.0f));

	Timer time;
	float t = 0;
	unsigned int frames = 0;

	while (!window.closed())
	{
		window.clear();
		double x, y;
		Mouse::getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x * 16.0f / 960.0f), (float)(9.0f - y * 9.0f / 540.0f)));
#if BATCH_RENDERER
		renderer.begin();
#endif
		for (int i = 0; i < sprites.size(); i++) {
			renderer.submit(sprites[i]);
		}
#if BATCH_RENDERER
		renderer.end();
#endif
		renderer.flush();
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