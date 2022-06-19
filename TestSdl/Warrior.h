
#ifndef WARRIOR_H
#define WARRIOR_H
//ya 
#include "Character.h"
#include "Animation.h"
#include "RigidBody.h"
class Warrior : public Character
{
	public:
		Warrior(Properties* props);
		
		virtual void Draw();
		virtual void Clean();
		virtual void Update(float dt);
		//create the function getPosition

		//update x and y position while reyes is moving 
		void UpdatePosition(float dt);
		
		virtual Vector2D getPosition();
		
	private:
		
		Animation* m_Animation;//variable that will hold the animation object for the warrior
		//////////////////////////////////////////////////////////////////////////////////////
		//le inicializamos el cuerpo rigido (osea aplicamos las fisicas a nuestro pichingo como la gravedad)
		RigidBody* m_RigidBody;
};
//END IF
#endif

