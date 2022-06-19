#include "Engine.h"
#include "TextureManager.h"
#include "Warrior.h"
#include "Input.h"
#include "SDL2/SDL.h"
#include "Timer.h"
#include "MapParser.h"
#include <iostream>
#include "NPC.h"
#include "Camera.h"

Engine*Engine::s_Instance =nullptr;
Warrior* reyes = nullptr;//create player object and set it to nullptr so we can use it in the engine class and in the game class 
NPC* tod = nullptr;
SDL_Rect dest;
Camera* camera = nullptr;

//create a function that will return the position on x of reyes
int getX()
{
	return reyes->getPosition().X;
}
//create a function that will return the position on y of reyes
int getY()
{
	return reyes->getPosition().Y;
}

bool colision(float  x1, float y1 , float x2, float y2,int width,int height)
{
	if (x1 + 32 > x2 && x1 < x2 + 32 && y1 + 32 > y2 && y1 < y2 + 32)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//update the position of reyes while moving on the screen 



bool Engine::Init()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0 && IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) != 0)
	{
		SDL_Log("Failed :%s", SDL_GetError());
		return  false;
	}
	//create uor window                  posicion centrada                             tamano                         
	SDL_WindowFlags window_flags = (SDL_WindowFlags)( SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	
	m_Window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, window_flags);
	if (m_Window == nullptr)//verify if winqow is creqated
	{
		SDL_Log("Failed to create window%s", SDL_GetError());
		return false;
	}
	m_Renderer=SDL_CreateRenderer(m_Window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);//if it was created we draw it 
	if (m_Renderer == nullptr)//verify if renderer is created
	{
		SDL_Log("Failed to create rendererer: %s", SDL_GetError());
		return false;
	}
	

	////////////////////////////////////// Load things //////////////////////////////////////////////////////////////////////////////////////////////
	//Load map 
	/*if (!MapParser::GetInstance()->Load())
	{
		std::cout << "Failed to load map" << std::endl;
		return false;
	}

	m_LevelMap = MapParser::GetInstance()->GetMap("level11");*/
	
	//load texture	
	//animaciones Movimiento 
	//Hoal
	TextureManager::GetInstance()->Load("reyes_estatico", "C:\\Users\\jcoq2\\source\\repos\\BirchEngine - Textures\\TestSdl\\reyes_estatico.png");
	TextureManager::GetInstance()->Load("reyes_corriendo", "C:\\Users\\jcoq2\\source\\repos\\BirchEngine - Textures\\TestSdl\\tinoco.png");
	TextureManager::GetInstance()->Load("reyes_parriba", "C:\\Users\\jcoq2\\source\\repos\\BirchEngine - Textures\\TestSdl\\reyes_parriba.png");
	TextureManager::GetInstance()->Load("reyes_pabajo", "C:\\Users\\jcoq2\\source\\repos\\BirchEngine - Textures\\TestSdl\\reyes_pabajo.png");

	//npcs
	TextureManager::GetInstance()->Load("tod", "C:\\Users\\jcoq2\\source\\repos\\BirchEngine - Textures\\TestSdl\\princess.png");
	
	//atques
	TextureManager::GetInstance()->Load("ataqueEnfrente", "C:\\Users\\jcoq2\\source\\repos\\BirchEngine - Textures\\TestSdl\\ataqueEnfrente.png");
	
	//fomnods
	TextureManager::GetInstance()->Load("abc", "C:\\Users\\jcoq2\\source\\repos\\BirchEngine - Textures\\TestSdl\\abc.png");
	//TextureManager::GetInstance()->Load("version2.0", "C:\\Dev\\BirchEngine - Textures\\TestSdl\\version2.0.tmx");
	
	//TextureManager::GetInstance()->Load("mapeado", "C:\\Dev\\BirchEngine - Textures\\TestSdl\\mapeado.png");
	//reyes=new Warrior(new Properties("reyes",100,200,32,64));//este funciona con la imagen holeeee //ataque
	//reyes=new Warrior(new Properties("reyes",100,200,188,200));//este funciona con la imagen anuel
	//reyes=new Warrior(new Properties("reyes_estatico",100,200,32,64)); //movimiento normal con animacion para empezar
	
	//reyes=new Warrior(new Properties("reyes_estatico",60,478,32,64)); //movimiento normal con animacion para empezar
	reyes=new Warrior(new Properties("reyes_estatico",190, 10,32,29)); //movimiento normal con animacion para empezar
	tod=new NPC(new Properties("tod", 620,300,32,29));

	
	/*Transform tf;
	tf.Log();*/
	
	//Camera::GetInstance()->SetTarget(reyes->GetOrigin());
	
	return m_Running = true;
}
void Engine::Update()
{
	float dt = Timer::GetInstance()->GetDeltaTime();
	
	//m_LevelMap->Update();
	reyes->Update(dt);
	tod->Update(dt);
	//Camera::GetInstance()->Update(dt);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
void Engine::Render()
{
	//Con esto pues le dariamos el color y la forma a la ventana pero salddria en negronpor que ocupamos un agregar un evento alla abajo
	//SDL_SetRenderDrawColor(m_Renderer, 124, 218,254, 255);//dibujamos los colores de nuestro dibujante 
	//SDL_SetRenderDrawColor(m_Renderer, 0, 0,0, 0);//dibujamos los colores de nuestro dibujante 
	SDL_RenderClear(m_Renderer);//limpiamos el dibujante (SIN ESTO NO SE VA A PINTAR DE COLOR EL FONDO DE LA PANTALLA!!!!!!!!!!!!!!!!!!)
	//TextureManager::GetInstance()->Draw("fondo14", 0, 0, 960, 640);////mlkm
	
	//m_LevelMap->Render();
	//TextureManager::GetInstance()->Draw("abc", 0, 0, 1920, 1080);////mlkm
	TextureManager::GetInstance()->Draw("abc", 0, 0, 960, 640);////mlkm
	reyes->Draw();
	
	tod->Draw();
	
	//Dibujar el mapa 
	
	//SDL_RenderPresent(m_Renderer);//presentamos el dibujante
	
	//TextureManager::GetInstance()->Draw("mapeado",8,8, 960,640);//dibujamos la textura //ya no nos sirve por que ocupamos una que dibuje cosas moviendose
	//TextureManager::GetInstance()->Draw("mapeado",8,8, 960,640);
	
	SDL_RenderPresent(m_Renderer);//presentamos el dibujante
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void Engine::Events()
{
	Input::GetInstance()->Listen();//ahora usamos nuestros comandos de teclado de la clase input 
}


bool Engine::Clean()
{
	TextureManager::GetInstance()->Clean();
	SDL_DestroyRenderer(m_Renderer);
	SDL_DestroyWindow(m_Window);
	IMG_Quit();
	SDL_Quit();
	return false;
}

void Engine::Quit()
{
	//si el usuario le da salir pues que lo saque del programa	y cierre la ventana
	m_Running = false;
}