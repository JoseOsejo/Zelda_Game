#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H
#include "IObject.h"
#include "Transform.h"
#include "SDL2/SDL.h"
//inclide point
#include "Point.h"
//ya creo
struct Properties {

public:
	Properties(std::string textureID, int x, int y, int width, int height, SDL_RendererFlip flip = SDL_FLIP_NONE) {//what this does is create a new object with the given parameters and set the default values for the rest of the parameters to 0 
		X = x;
		Y = y;
		Flip = flip;
		Width = width;
		Height = height;
		TextureID = textureID;
	}

public:
	std::string TextureID;
	int Width, Height;
	float X, Y;
	SDL_RendererFlip Flip;
};

//esto se hace para que se pueda heredar  de IObject y de GameObject para que se pueda usar el metodo draw;;
class GameObject : public IObject {

public:
	GameObject(Properties* props) : m_TextureID(props->TextureID),
		m_Width(props->Width), m_Height(props->Height), m_Flip(props->Flip) {

		m_Transform = new Transform(props->X, props->Y);

		float px = props->X + props->Width / 2;
		float py = props->Y + props->Height / 2;
		m_Origin = new Point(px, py);
	}
	inline Point* GetOrigin() { return m_Origin; }
	
	//como estamos haciendo herencia de la clase IObject, esta clase tiene todos los metodos de IObject
	virtual void Draw() = 0;
	virtual void Clean() = 0;
	virtual void Update(float dt) = 0;


protected:
	Point* m_Origin;
	Transform* m_Transform;
	int m_Width, m_Height;
	std::string m_TextureID;
	SDL_RendererFlip m_Flip;

};
#endif // !GAMEOBJECT_H

