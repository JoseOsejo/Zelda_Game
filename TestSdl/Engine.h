//#pragma once
#ifndef  ENGINE_H
#define  ENGINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "GameMap.h"

//#define Screen_Width 960
//#define Screen_Height 640

#define SCREEN_WIDTH 760
#define SCREEN_HEIGHT 540

class Engine
{
	public:
	static Engine* GetInstance()//get instance
	//need to chek if the object is created then we return if if not we create a isntance of it
	{
		return s_Instance= (s_Instance != nullptr)? s_Instance : new Engine();
	}
	bool Init();
	bool Clean();
	void Quit();
	
	void Update();
	void Render();//render es el que dibuja todo en pantalla
	void Events();
	
	inline bool IsRunning()//method to know if the game is running
	{	
		return m_Running;//return variable for the game
	}
	//early c++ thing that update the copiler 
	inline SDL_Renderer* GetRenderer() {return m_Renderer;}
		
private:
	//constructor should be private so not everyone will create things in there 
	Engine() {}
	bool m_Running;//variable member is runnung or not
	
	GameMap* m_LevelMap; //pointer to the map
	SDL_Window* m_Window;//window
	SDL_Renderer* m_Renderer;//renderer
	static Engine* s_Instance;
	
};
//endif
#endif
