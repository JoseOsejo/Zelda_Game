#ifndef CAMERA_H
#define CAMERA_H

#include "Point.h"
#include "Vector2D.h"
//inlcude sdl
#include "SDL2/SDL.h"
#include "Engine.h"

class Camera
{
public:

	void Update(float dt);
	inline SDL_Rect GetViewBox() { return m_ViewBox; }
	
	inline Vector2D GetPosition() 
	{
		//std::cout<<"m_Position: "<<m_Position.X<<" "<<m_Position.Y<<std::endl;

		return m_Position
			
	;}
	//update the position of reyes while moving 
	void UpdatePosition(Vector2D position);
	void UpdatePosition(float x, float y);
	
	
	
	inline void SetTarget(Point* target) { m_Target = target; }
    inline static Camera* GetInstance() { return s_Instance = (s_Instance != nullptr) ? s_Instance : new Camera(); }


private:
	Camera() {m_ViewBox={ 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };}

	
	
	Point* m_Target;//value de la camare 
	Vector2D m_Position;

	SDL_Rect m_ViewBox;
	static Camera* s_Instance;
};
//endif
#endif
