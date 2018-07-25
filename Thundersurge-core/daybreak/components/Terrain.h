#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#define SEED 0xCAFE

#include "MeshRenderer.h"
#include "../core/noise/FastNoise.h"

namespace daybreak {

	namespace components {

		class Terrain : public MeshRenderer {
		private:
			float m_x, m_z;

			Mesh* generate(float size, float amplitude, int numVertices) {
				std::vector<Vertex> vertices(numVertices * numVertices);
				std::vector<GLuint> indices(6 * (numVertices - 1) * (numVertices - 1));
				FastNoise noise;
				noise.SetNoiseType(FastNoise::Simplex);
				noise.SetSeed(SEED);

				float x = 0.0f, y = 0.0f;
				float offset = 5.0f / (float) numVertices;
				int ptr = 0;
				for (float r = 0; r < numVertices; r += 1.0f) {
					x = 0;
					for (float c = 0; c < numVertices; c += 1.0f) {
						Vertex v;
						v.pos.m_x = c * size / ((float)numVertices - 1);
						v.pos.m_y = noise.GetNoise(x, y) * amplitude;
						v.pos.m_z = r * size / ((float)numVertices - 1);
						v.texture.m_x = c / (float)numVertices;
						v.texture.m_y = r / (float)numVertices;
						v.normal.m_x = 0; // 2 * amplitude * (perlin.GetNoise(x, y - offset), perlin.GetNoise(x, y + offset));
						v.normal.m_y = 4;
						v.normal.m_z = 0;// 2 * amplitude * (perlin.GetNoise(x + offset, y), perlin.GetNoise(x - offset, y));
						v.normal.normalize();
						vertices[ptr] = v;
						ptr++;
						x += offset;
					}
					y += offset;
				}

				ptr = 0;
				int topL, topR, botL, botR;
				for (int z = 0; z < numVertices - 1; z++) {
					for (int x = 0; x < numVertices - 1; x++) {
						topL = (z * numVertices) + x;
						topR = topL + 1;
						botL = ((z + 1) * numVertices) + x;
						botR = botL + 1;
						indices[ptr++] = topL;
						indices[ptr++] = botL;
						indices[ptr++] = topR;
						indices[ptr++] = topR;
						indices[ptr++] = botL;
						indices[ptr++] = botR;
					}
				}
				return new Mesh(vertices, indices);
			}
		public:
			Terrain(float size, float amplitude, int numVertices, Material* material) :
				MeshRenderer(generate(size, amplitude, numVertices), material) {
			}

			void update(float delta) {
				//getTransform()->setTranslation(vec3((-SIZE / 2), 0, (-SIZE / 2)));
			}

			//void addToScene(Scene* scene) { }
		};
	}
}

#endif
