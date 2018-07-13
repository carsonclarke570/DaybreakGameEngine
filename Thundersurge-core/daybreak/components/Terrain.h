#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#define SIZE 16
#define VERTEX_COUNT 1000
#define AMPLITUDE 1
#define SEED 0xCAFE

#include "MeshRenderer.h"
#include "../core/noise/FastNoise.h"

namespace daybreak {

	namespace components {

		class Terrain : public MeshRenderer {
		private:
			float m_x, m_z;

			Mesh generate() {
				std::vector<Vertex> vertices(VERTEX_COUNT * VERTEX_COUNT); 
				std::vector<GLuint> indices(6 * (VERTEX_COUNT - 1) * (VERTEX_COUNT - 1));
				FastNoise perlin;
				perlin.SetNoiseType(FastNoise::Perlin);

				int ptr = 0;
				float x = 0.0f, y = 0.0f;
				for (float i = 0; i < VERTEX_COUNT; i += 1.0f) {
					for (float j = 0; j < VERTEX_COUNT; j += 1.0f) {
						Vertex v;
						v.pos = vec3(j / (VERTEX_COUNT - 1) * SIZE, ((perlin.GetNoise(x, y) + 1.0f) / 2.0f) * AMPLITUDE, i / (VERTEX_COUNT - 1) * SIZE);
						v.texture = vec2(j / (VERTEX_COUNT - 1), i / (VERTEX_COUNT - 1));
						vertices[ptr] = v;
						ptr++;
						x += 0.01f;
					}
					y += 0.01f;
				}

				ptr = 0;
				int topL, topR, botL, botR;
				for (int z = 0; z < VERTEX_COUNT - 1; z++) {
					for (int x = 0; x < VERTEX_COUNT - 1; x++) {
						topL = (z * VERTEX_COUNT) + x;
						topR = topL + 1;
						botL = ((z + 1) * VERTEX_COUNT) + x;
						botR = botL + 1;
						indices[ptr++] = topL;
						indices[ptr++] = botL;
						indices[ptr++] = topR;
						indices[ptr++] = topR;
						indices[ptr++] = botL;
						indices[ptr++] = botR;
					}
				}
				return Mesh(vertices, indices);
			}
		public:
			Terrain(float x, float z, const Material& material) :
				MeshRenderer(generate(), material), m_x(x), m_z(z){
			}

			float getHeight(float x, float z) {
				return Noise::perlin(x, z) * AMPLITUDE;
			}

			void update(float delta) {
				getTransform()->setTranslation(vec3((-SIZE / 2) + m_x, 0, (-SIZE / 2) + m_z));
			}
		};
	}
}

#endif
