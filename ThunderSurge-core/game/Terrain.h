#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include <fstream>

#include "../daybreak/components/MeshRenderer.h"

namespace daybreak {

	namespace components {

		struct Tile {
			float height;
		};

		class Terrain : public MeshRenderer {
		private:
			Tile* m_levelmap;
			int m_numrows, m_numcols;

			Mesh* load(std::string file);
			float calcHeight(int row, int col);
		public:
			Terrain(std::string file);

			Tile& getTile(int row, int col);
		};
	}
}

#endif