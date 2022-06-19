
#ifndef CHARACTER_H
#define CHARACTER_H

//ya 
#include "GameObject.h"
#include <string>

class Character : public GameObject//what this does is that it inherits from gameobject
{
	public:
		Character(Properties* props) : GameObject(props) {}//what this does exactly is that it creates a character object and passes in the properties of the character object to the gameobject constructor
				
		virtual void Draw()=0;
		virtual void Clean()=0;
		virtual void Update(float dt)=0;
		
		
	protected:
		std::string n_Name;
};
//end if 
#endif
