//#pragma once
#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H
//#ifndef TEXTUREMANAGER_H
//#define TEXTUREMANAGER_H
//include strin and sdl 
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
class TextureManager
{
	public:
	
		static TextureManager* GetInstance() { return s_Instance = (s_Instance != nullptr)? s_Instance:new TextureManager();}

		bool Load(std::string id , std::string filename);
		void Drop(std::string id);
		void Clean();//if we dont clean it will stay at memory and it wil crash
		
		
		void Draw(std::string id,int x,int y,int width,int height,SDL_RendererFlip flip = SDL_FLIP_NONE);
		void DrawTile(std::string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip = SDL_FLIP_NONE);
		void DrawFrame(std::string id,int x,int y,int width,int height,int row,int frame,SDL_RendererFlip flip = SDL_FLIP_NONE);
		
	private:
		TextureManager() {}
		std::map<std::string, SDL_Texture*> m_TextureMap;
		static TextureManager* s_Instance;
};
//ENDIF
#endif

