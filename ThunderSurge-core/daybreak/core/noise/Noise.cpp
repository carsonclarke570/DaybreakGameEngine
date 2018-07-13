#include "Noise.h"

namespace daybreak {

	namespace core {
	
		char Noise::permutation[2 * PERMUTATION_SIZE];

		void Noise::seed(int seed) {
			srand(seed);
			int r;
			for (int i = 0; i < PERMUTATION_SIZE; i++) {
				r = rand() % PERMUTATION_SIZE;
				permutation[i] = r;
				permutation[i + PERMUTATION_SIZE] = r;
			}
		}

		float Noise::perlin(float x, float y) {
			x = fmod(x, PERMUTATION_SIZE);
			y = fmod(y, PERMUTATION_SIZE);

			int xi = (int)x & (PERMUTATION_SIZE - 1);
			int yi = (int)y & (PERMUTATION_SIZE - 1);
			float xf = x - (int)x;
			float yf = y - (int)y;

			float u = fade(xf);
			float v = fade(xf);

			int aa, ab, ba, bb;
			aa = permutation[permutation[xi] + yi];
			ab = permutation[permutation[xi] + inc(yi)];
			ba = permutation[permutation[inc(xi)] + yi];
			bb = permutation[permutation[inc(xi)] + inc(yi)];

			float x0, x1;

			x0 = lerp(grad(aa, xf, yf), grad(ba, xf - 1, yf), u);
			x1 = lerp(grad(ab, xf, yf - 1), grad(bb, xf - 1, yf - 1), u);

			return (lerp(x0, x1, v) + 1.0f) / 2.0f;
		}

		float Noise::fade(float t) {
			return t * t * t * (t * (t * 6 - 15) + 10);
		}

		float Noise::lerp(float a, float b, float x) {
			return a + x * (b - a);
		}

		int Noise::inc(int num) {
			return (++num) % PERMUTATION_SIZE;
		}

		int Noise::grad(int hash, float x, float y) {
			switch (hash & 0xF) {
				case 0x0: return  x + y;
				case 0x1: return -x + y;
				case 0x2: return  x - y;
				case 0x3: return -x - y;
				case 0x4: return  x + y;
				case 0x5: return -x + y;
				case 0x6: return  x - y;
				case 0x7: return -x - y;
				case 0x8: return  x + y;
				case 0x9: return -x + y;
				case 0xA: return  x - y;
				case 0xB: return -x - y;
				case 0xC: return  x + y;
				case 0xD: return -x + y;
				case 0xE: return  x - y;
				case 0xF: return -x - y;
				default: return 0;
			}
		}
	}
}