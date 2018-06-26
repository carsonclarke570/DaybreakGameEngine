#pragma once

namespace thundersurge {

	namespace core {

		class Game {
		public:
			virtual void init() = 0;
			virtual void update() = 0;
			virtual void render() = 0;
		};
	}
}