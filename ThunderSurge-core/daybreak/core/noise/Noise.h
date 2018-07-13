#ifndef _NOISE_H_
#define _NOISE_H_

#define PERMUTATION_SIZE 256

#include <cstdlib>
#include <cmath>

namespace daybreak {

	namespace core {

		class Noise {
		private:
			static char permutation[2 * PERMUTATION_SIZE];

			static float fade(float t);
			static float lerp(float a, float b, float x);
			static int inc(int num);
			static int grad(int hash, float x, float y);
		public:
			static void seed(int seed);
			static float perlin(float x, float y);
		};
	}
}

#endif