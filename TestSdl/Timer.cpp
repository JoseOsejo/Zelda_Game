#include "Timer.h"
#include <SDL2/SDL.h>
Timer* Timer::s_Instance = nullptr;

void Timer::Tick()
{
	//Delta time es la diferencia de tiempo entr entre dos evantos
	m_DeltaTime = (SDL_GetTicks() - m_LastTime) * (TARGET_FPS / 1000.0f);
	if(m_DeltaTime > TARGET_DELTATIME)
		m_DeltaTime = TARGET_DELTATIME;
	
	m_LastTime = SDL_GetTicks();

	
}