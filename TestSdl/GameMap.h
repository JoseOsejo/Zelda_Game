#pragma once


#include <vector>
//include vector 2d
//#include <Vector2D.h>
#include "Layer.h"


class GameMap
{
	public:
		void Render()
		{
			for (unsigned int i = 0; i < m_MapLayers.size(); i++)
				m_MapLayers[i]->Render();

		}
		void Update()
		{
			for (unsigned int i = 0; i < m_MapLayers.size(); i++)
				m_MapLayers[i]->Update();


		}

		std::vector <Layer*> GewtMapLayers() { return m_MapLayers; }

		private:
			friend class MapParser;//clase friend da accseso al componente map
			std::vector<Layer*> m_MapLayers;



	
};

