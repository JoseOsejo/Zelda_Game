#include "Input.h"
#include "Engine.h"

Input* Input::s_Instance = nullptr; //inicializamos el puntero a nullptr o rel instance

Input::Input()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);


}

void Input::Listen()   //Metodo que nos sirve para detectar cual tecla presiono el ususairo 
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			case SDL_QUIT:Engine::GetInstance()->Quit(); break;
			case SDL_KEYDOWN: KeyDown(); break;
			case SDL_KEYUP: KeyUp(); break;
		}
	}
}

//method GetKeyDown
bool Input::GetKeyDown(SDL_Scancode key) //metodo para saber si el usuario presiono una tecla hacia abajo
{
	/*if(m_KeyStates[key]==1)
		return true;
	return false;*/
	return (m_KeyStates[key] == 1); //forma mas optimizada de hacerlo en comparacion a lo de arribe 
}


//method key up 
void Input::KeyUp()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}
void  Input::KeyDown()
{
	m_KeyStates = SDL_GetKeyboardState(nullptr);
}




