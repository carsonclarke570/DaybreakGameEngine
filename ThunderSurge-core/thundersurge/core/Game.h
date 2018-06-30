#pragma once

namespace thundersurge {

	namespace core {

		class Game {
		protected:
		public:
			virtual void init() = 0;
			virtual void update(float delta) = 0;
			virtual void render() = 0;
			virtual bool quit() = 0;
		};
	}
}