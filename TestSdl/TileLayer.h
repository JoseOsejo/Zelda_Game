#ifndef TILELAYER_H
#define TILELAYER_H


#pragma once
//include layer.h
#include"Layer.h"
#include<string>
#include<vector>

struct Tileset
{
	int FirstID, LastID;
	int RowCount, ColCount;
	int TileCount, TileSize;
	std::string Name, Source;
};

using TilesetsList = std::vector<Tileset>;
using TileMap = std::vector<std::vector<int> >;


class TileLayer : public Layer
{
public:
	TileLayer(int tilesize, int rowcount, int colcount, TileMap tilemap, TilesetsList tilesets);
	virtual void Render();
	virtual void Update();
	inline TileMap GetTilemap() { return m_Tilemap; }


private:
	int m_TileSize;
	int m_RowCount, m_ColCount;


	TileMap m_Tilemap;
	TilesetsList m_Tilesets;

};
//enif
#endif

























































//
//#include<string>
//#include<vector>
//#include"Layer.h"
//#include"Vector2D.h"
//struct Tileset
//{
//	std::string name , source;
//	int tileWidth, tileHeight;
//	int tileCount;
//	int numRows, numCols;
//};
//
////using TilesetsList = std::vector<Tileset> ;
////using TileMap = std::vector<std::vector<int> >;
//
//
//class TileLayer: public Layer
//{
//	public :
//		TileLayer(std::vector<std::vector<int> > tileIDs,Tileset tileset);
//		virtual ~TileLayer() {}
//		
//		virtual void render();
//		virtual void update();
//		//inline TileMap GetTilemap() { return m_Tilemap; }
//		
//		void setNumRows(int numRows){m_numRows = numRows;}
//		void setNumCols(int numCols){m_numCols = numCols;}
//
//		
//	private:
//		int m_numRows, m_numCols;
//		Vector2D m_pos;
//		Vector2D m_vel;
//		std::vector<std::vector<int> > m_tileIDs;
//		Tileset m_Tilesets;
//		
//};
//#endif
