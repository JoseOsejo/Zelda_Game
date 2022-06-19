
#ifndef NPC_H
#define NPC_H
//ya 
#include "Character.h"
#include "Animation.h"
#include "RigidBodyNPC.h"
class NPC : public Character
{
public:
	NPC(Properties* props);

	virtual void Draw();
	virtual void Clean();
	virtual void Update(float dt);

private:

	Animation* m_Animation;//variable that will hold the animation object for the warrior
	//////////////////////////////////////////////////////////////////////////////////////
	//le inicializamos el cuerpo rigido (osea aplicamos las fisicas a nuestro pichingo como la gravedad)
	RigidBodyNPC* m_RigidBody;
};
//END IF
#endif

