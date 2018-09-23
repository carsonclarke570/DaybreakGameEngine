#include "Terrain.h"

namespace daybreak {

	namespace components {

		Mesh* Terrain::load(std::string file) {
			std::ifstream lvlfile;
			lvlfile.open(file);

			float tilesize;
			lvlfile >> m_numcols >> m_numrows >> tilesize;

			if (m_numcols == 0 || m_numrows == 0) {
				Log::logErr(std::string("Error loading level map: " + file).c_str());
				exit(1);
			}

			m_levelmap = new Tile[m_numrows * m_numcols];

			float ht;
			for (int row = 0; row < m_numrows; row++) {
				for (int col = 0; col < m_numcols; col++) {
					// Load Tile Details
					lvlfile >> ht;
					m_levelmap[row * m_numcols + col].height = ht;
				}
			}

			std::vector<Vertex> vertices;
			std::vector<unsigned int> indices;

			
			for (int row = 0; row <= m_numrows; row++) {
				for (int col = 0; col <= m_numcols; col++) {
					Vertex v;
					v.color = vec3(1, 1, 0);
					v.normal = vec3(0, 1, 0); //CHANGE THIS
					v.pos = vec3((float)row * tilesize, 0, (float)col * tilesize);
					v.texture = vec2(1.0f / (float) m_numrows, 1.0f / (float) m_numcols);
					vertices.push_back(v);
				}
			}

			for (int row = 0; row < m_numrows; row++) {
				for (int col = 0; col < m_numcols; col++) {
					int ll = row * m_numcols + col;
					int lr = row * m_numcols + col + 1;
					int ul = (row + 1) * m_numcols + col;
					int ur = (row + 1) * m_numcols + col + 1;

					indices.push_back(ll);
					indices.push_back(ul);
					indices.push_back(ur);
					indices.push_back(ll);
					indices.push_back(ur);
					indices.push_back(lr);
				}
			}

			/**for (int row = 0; row < height; row++) {
				for (int col = 0; col < width; col++) {
					std::cout << m_levelmap[row * width + col].height;
				}
				std::cout << std::endl;
			}**/
			return new Mesh(vertices, indices);
		}

		float Terrain::calcHeight(int row, int col) {

			// (Literal) edge cases
			if (row == 0) {
				if (col > 0 && col < m_numcols) 
					return (getTile(0, col - 1).height + getTile(0, col).height) / 2.0f;
				else if (col == 0) 
					return getTile(0, 0).height;
				else 
					return getTile(0, m_numcols - 1).height;
			}
			if (row == m_numrows) {
				if (col > 0 && col < m_numcols) 
					return (getTile(m_numrows - 1, col - 1).height + getTile(m_numrows - 1, col).height) / 2.0f;
				else if (col == 0)
					return getTile(m_numrows - 1, 0).height;
				else
					return getTile(m_numrows - 1, m_numcols - 1).height;
			}
			if (col == 0) {
				if (row > 0 && row < m_numrows)
					return (getTile(row - 1, 0).height + getTile(row, 0).height) / 2.0f;
			}
			if (col == m_numcols) {
				if (row > 0 && row < m_numrows)
					return (getTile(row - 1, m_numcols - 1).height + getTile(row, m_numcols - 1).height) / 2.0f;
			}

			return (getTile(row - 1, col - 1).height + getTile(row - 1, col).height + getTile(row, col - 1).height + getTile(row, col).height) / 4.0f;
		}
		
		Terrain::Terrain(std::string file)
			: MeshRenderer(load(file)) {
		}

		Tile& Terrain::getTile(int row, int col) {
			return m_levelmap[row * m_numcols + col];
		}
	}
}
