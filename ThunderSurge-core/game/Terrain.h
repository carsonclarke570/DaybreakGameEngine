#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#define AMPLITUDE 1.0f

#include "../daybreak/core/noise/FastNoise.h"

#include "../daybreak/components/MeshRenderer.h"

namespace daybreak {

	namespace components {

		class Terrain : public MeshRenderer {
		private:
			FastNoise noise;

			Mesh* loadMesh(float size, float n) {
				noise.SetNoiseType(FastNoise::Perlin);
				noise.SetFrequency(1);
				std::vector<Vertex> vertices;
				std::vector<GLuint> indices((n - 1) * (n - 1) * 6);
				for (float x = 0; x < n;  x += 1.0f) {
					for (float z = 0; z < n; z += 1.0f) {
						Vertex v;
						v.pos = getPosition(x, z, size, n);
						v.normal = getNormal(x, z, size, n);
						v.color = getColor(x, z, size, n);
						vertices.push_back(v);
					}
				}

				int i = 0;
				for (float x = 0; x < n - 1; x += 1.0f) {
					for (float y = 0; y < n - 1; y += 1.0f) {
						indices[i++] = x + (y * n);
						indices[i++] = x + (y * n) + 1;
						indices[i++] = x + ((y + 1) * n) + 1;
						indices[i++] = x + (y * n);
						indices[i++] = x + ((y + 1) * n) + 1;
						indices[i++] = x + ((y + 1) * n);
					}
				}

				return new Mesh(vertices, indices);
			}

			vec3 getPosition(float x, float z, float size, float n) {
				vec3 pos;
				pos.m_x = x * (size / (n - 1)) - (size / 2);
				pos.m_y = height(x, z);
				pos.m_z = z * (size / (n - 1)) - (size / 2);
				return pos;
			}

			vec3 getNormal(float x, float z, float size, float n) {
				float L = height(x, z - 1);
				float R = height(x, z + 1);
				float D = height(x - 1, z);
				float U = height(x + 1, z);
				return vec3(D - U, 2, L - R).normalize();
			}

			vec3 getColor(float x, float z, float size, float n) {
				return vec3(0, 1, 0).lerp(vec3(1, 1, 1), height(x, z) / AMPLITUDE);
			}

			float height(float x, float z) {
				return noise.GetNoise(x, z) * 8;
			}
		public:
			Terrain(float size, float n) : MeshRenderer(loadMesh(size, n), new Material(), new Shader("game/res/shaders/terrain.vert", "game/res/shaders/terrain.frag", NULL)) {
			}
		};
	}
}

#endif