#include "MapParser.h"

MapParser* MapParser::s_Instance = nullptr;
using TilesetsList = std::vector<Tileset>;


bool MapParser::Load()
{
	//return Parse("level11","version2.0.tmx");
	if (!Parse("level11", "version2.0.tmx"))
		return false;
	return true;

}

bool MapParser::Parse(std::string id, std::string source)
{
	//create a xMl document 
	TiXmlDocument xml;
	xml.LoadFile(source);
	//check if the document is loaded
	if (xml.Error())
	{
		std::cerr << "Error en el pedillo de subir el archive" << source << std::endl;
		return false;
	}

	//create a root element
	TiXmlElement* root = xml.RootElement();

	int colcount, rowcount, tilesize = 0;

	root->Attribute("width", &colcount);
	root->Attribute("height", &rowcount);
	root->Attribute("tilewidth", &tilesize);

	//parse tile sets
	TilesetsList tilesets;
	for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("tileset"))
		{
			tilesets.push_back(ParseTileset(e));
		}

	}
	////////////////////////////////////////////////////////////////////////////////////////////////////
	//parse layers
	GameMap* gamemap = new GameMap();//creamos el mpaa
	for (TiXmlElement* e = root->FirstChildElement(); e != nullptr; e = e->NextSiblingElement())
	{
		if (e->Value() == std::string("layer"))
		{
			TileLayer* tilelayer = ParseTileLayer(e, tilesets, tilesize, rowcount, colcount);
			gamemap->m_MapLayers.push_back(tilelayer);
		}
	}
	m_MapDict[id] = gamemap;
	return true;
}

Tileset MapParser::ParseTileset(TiXmlElement* xmlTileset)
{
	Tileset tileset;
	//get the attributes
	tileset.Name = xmlTileset->Attribute("name");
	xmlTileset->Attribute("firstgid", &tileset.FirstID);

	xmlTileset->Attribute("tilecount", &tileset.TileCount);
	tileset.LastID = (tileset.FirstID + tileset.TileCount) - 1;

	xmlTileset->Attribute("columns", &tileset.ColCount);
	tileset.RowCount = tileset.ColCount / tileset.ColCount;
	xmlTileset->Attribute("tilewidth", &tileset.TileSize);


	TiXmlElement* image = xmlTileset->FirstChildElement();
	tileset.Source = image->Attribute("source");
	return tileset;
}


TileLayer* MapParser::ParseTileLayer(TiXmlElement* xmlLayer, std::vector<Tileset> tilesets, int tilesize, int rowcount, int colcount)
{
	TiXmlElement* data = 0;
	for (TiXmlElement* e = xmlLayer->FirstChildElement(); e != nullptr; e = e->NextSiblingElement()) {
		if (e->Value() == std::string("data"))
		{
			data = e;
			break;
		}
	}
	std::string matrix(data->GetText());
	std::istringstream iss(matrix);
	std::string id;

	TileMap tilemap(rowcount, std::vector<int>(colcount, 0));
	for (int row = 0; row <= rowcount; row++)
	{
		for (int col = 0; col <= colcount; col++)
		{
			getline(iss, id, ',');
			std::stringstream convertor(id);
			convertor >> tilemap[row][col];

			if (!iss.good())
				break;
		}
	}
	return (new TileLayer(tilesize, colcount, rowcount, tilemap, tilesets));
}
//TileLayer* MapParser::ParseTileLayer(TiXmlElement* xmlLayer, TilesetsList tilesets, int tilesize, int rowcount, int colcount)
//{
//	TiXmlElement* data =0;
//	for (TiXmlElement* e = xmlLayer->FirstChildElement(); e != nullptr; e=e->NextSiblingElement()) {
//		if (e->Value() == std::string("data"))
//		{
//			data = e;
//			break;
//		}
//	}
//	std::string matrix(data->GetText());
//	std::istringstream iss(matrix);
//	std::string id;
//
//	TileMap tilemap(rowcount, std::vector<int>(colcount, 0));
//	for (int row = 0; row <= rowcount; row++) 
//	{
//		for (int col = 0; col <= colcount; col++)
//		{
//			getline(iss, id, ',');
//			std::stringstream convertor(id);
//			convertor >> tilemap[row][col];
//
//			if (!iss.good())
//			break;
//		}
//	}
//	return (new TileLayer(tilesize, colcount, rowcount, tilemap, tilesets));
//}
void MapParser::Clean()
{
	std::map<std::string, GameMap*>::iterator it;
	for (it = m_MapDict.begin(); it != m_MapDict.end(); it++)
		it->second = nullptr;

	m_MapDict.clear();

}









































//#include "MapParser.h"
//#include <iostream>
//#include <sstream>
//Map2D* MapParser::parseMap(char* filename) {
//	TiXmlDocument xml;
//	xml.LoadFile(filename);
//	if (xml.Error()) {
//		std::cerr << "Failed to load the:" << filename << std::endl;
//	}
//	TiXmlElement* root = xml.RootElement();
//	int numCols, numRows, tileWidth, tileHeight;
//
//	root->Attribute("Width", &numCols);
//	root->Attribute("height", &numRows);
//	root->Attribute("tilewidth", &tileWidth);
//	root->Attribute("tileheight", &tileHeight);
//
//	TiXmlElement* tileset;
//	for (TiXmlElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
//		if (e->Value() == std::string("tileset")) {
//			tileset = e;
//			break;
//		}
//	}
//	std::string ts_file = tileset->Attribute("source");
//	Tileset mapTileset = parseTileset(("C:\Dev\BirchEngine - Textures\TestSdl" + ts_file));
//
//	TiXmlElement* layer;
//	for (TiXmlElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
//		if (e->Value() == std::string("layer")) {
//			layer = e;
//			break;
//		}
//	}
//	TileLayer* mapTileLayer = ParseTileLayer(layer, mapTileset, numRows, numCols);
//
//	mapTileLayer->setNumCols(numCols);
//	mapTileLayer->setNumRows(numRows);
//
//	Map2D* map2d = new Map2D();
//	map2d->m_layers.push_back(mapTileLayer);
//	return map2d;
//
//}
//
//TileLayer* MapParser::ParseTileLayer(TiXmlElement* layer, Tileset mapTileset, int numRows, int numCols){
//	
//	std::vector<std::vector<int> > mapIDs(numRows, std::vector<int>(numCols, 0));
//	TiXmlElement* data = layer->FirstChildElement();
//	const char* tileIDs = data->GetText();
//	std::string _tile(tileIDs);
//
//	std::stringstream iss(_tile);
//	for (int row = 0; row < numRows; row++) {
//		for (int col = 0; col < numCols; col++) {
//			std::string id;
//			getline(iss, id, ',');
//
//			if (!iss.good())
//				break;
//
//			std::stringstream convertor(id);
//			convertor >> mapIDs[row][col];
//
//		}
//	}
//	TileLayer* mapLayer = new TileLayer(mapIDs, mapTileset);
//
//	std::cout << "ts name: " << mapTileset.name << std::endl;
//	std::cout << "ts source: " << mapTileset.source << std::endl;
//	std::cout << "ts numRows: " << mapTileset.numRows << std::endl;
//	std::cout << "ts numCols: " << mapTileset.numCols << std::endl;
//
//
//	std::cout << "ts tileCount: " << mapTileset.tileCount << std::endl;
//	std::cout << "ts tileWidth: " << mapTileset.tileWidth << std::endl;
//
//	for (int i = 0; i < numRows; i++) {
//		for (int j = 0; j < numCols; j++) {
//			std::cout << mapIDs[i][j] << " ";
//		}
//		std::cout << std::endl;
//	}
//	return 0;
//}
//	
//Tileset MapParser::parseTileset(std::string filename) {
//		Tileset mapTileset;
//		TiXmlDocument xml_ts;
//		xml_ts.LoadFile(filename);
//		if (xml_ts.Error()) {
//			std::cerr << "Failed to load the:" << filename << std::endl;
//		}
//
//		TiXmlElement* ts_root = xml_ts.RootElement();
//		mapTileset.name = ts_root->Attribute("name");
//		ts_root->Attribute("tileWidth", &mapTileset.tileWidth);
//		ts_root->Attribute("tileheight", &mapTileset.tileHeight);
//		ts_root->Attribute("tilecount", &mapTileset.tileCount);
//		ts_root->Attribute("columns", &mapTileset.numCols);
//		mapTileset.numRows = mapTileset.tileCount / mapTileset.numCols;
//		
//		TiXmlElement* image = ts_root->FirstChildElement();
//		mapTileset.source = image->Attribute("source");
//
//		//TiXmlElement* tileset;
//		//for (TiXmlElement* e = root->FirstChildElement(); e != NULL; e = e->NextSiblingElement()) {
//		//	if (e->Value() == std::string("tileset")) {
//		//		tileset = e;
//		//		break;
//		//	}
//		//}
//		//std::string ts_file = tileset->Attribute("source");
//		//Tileset mapTileset = parseTileset(("C:\Dev\BirchEngine - Textures\TestSdl" + ts_file));
//
//		return mapTileset;
//	}
//
//
