#ifndef MAPPARSER_H
#define MAPPARSER_H

#include <map>//esto es para poder crear mapa
#include <string>
#include "GameMap.h"
#include "TileLayer.h"

//#include "C:\Dev\BirchEngine - Textures\TestSdl\Vendor\tinyxml-master\tinyxml-master/tinyxml.h"
#include "Vendor\\tinyxml-master\\tinyxml-master\\tinyxml.h"


class MapParser
{
	//constructor
public:

	bool Load();
	void Clean();

	inline GameMap* GetMap(std::string id) { return m_MapDict[id]; }
	inline static MapParser* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new MapParser(); }//make sure that the is unique and exist

private:
	MapParser() {}

	bool Parse(std::string id, std::string source);
	Tileset ParseTileset(TiXmlElement* xmlTileset);
	TileLayer* ParseTileLayer(TiXmlElement* xmlLayer, std::vector<Tileset> tilesets, int tilesize, int rowcount, int colcount);
	//TileLayer* ParseTileLayer(TiXmlElement* xmlLayer,TilesetsList, int tilesize, int rowcount, int colcount);

	static MapParser* s_Instance;
	std::map<std::string, GameMap*> m_MapDict;//id of the map



};
//endif
#endif




























































//
//#include <string>
//#include <vector>
//
////#include <map>//esto es para poder crear mapa
//#include "Map2D.h"
//
////#include "GameMap.h"
//#include "TileLayer.h"
//
////#include "C:\Dev\BirchEngine - Textures\TestSdl\Vendor\tinyxml-master\tinyxml-master/tinyxml.h"
//#include "Vendor\\tinyxml-master\\tinyxml-master\\tinyxml.h"
////#include "../Xml/tynixml.h"
//
//
//class MapParser
//{
//	//constructor
//	public:
//		
//		MapParser(){}
//		//mapparser constructor
//		~MapParser(){}
//		
//		//bool Load();
//		//void Clean();
//		
//		//inline GameMap* GetMap(std::string id ) { return m_MapDict[id]; }
//		//inline static MapParser* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new MapParser(); }//make sure that the is unique and exist
//		
//		Map2D* parseMap(char* filename);
//		TileLayer* ParseTileLayer(TiXmlElement* layer,Tileset mapTileset , int numRows, int numCols);
//		Tileset parseTileset(std::string filename);
//	private:
//		//MapParser() {}
//		
//		//bool Parse(std::string id ,std::string source);
//		
//		
//		//TileLayer* ParseTileLayer(TiXmlElement* xmlLayer,TilesetsList, int tilesize, int rowcount, int colcount);
//		
//		//static MapParser* s_Instance;
//		//std::map<std::string, GameMap*> m_MapDict;//id of the map
//	
//
//	
//};
//#endif
