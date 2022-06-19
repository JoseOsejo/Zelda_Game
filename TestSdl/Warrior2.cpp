#include "Warrior2.h"
//#include "Warrior.h"
#include "TextureManager2.h"
#include <SDL2/SDL.h>
#include "Input.h"

//Correr en lab pero cambiando abajo la gravedad 
Warrior2::Warrior2(Properties* props) : Character(props)
{
	//Le aplicacamos las animaciones al pichingo y las fisicas 
	m_RigidBody = new RigidBody();
	m_Animation = new Animation();


	//1 row ,2 frames , velocidad de animacion
	m_Animation->SetProps(m_TextureID, 1, 8, 100);

}

void Warrior2::Draw()//draw the player on the screen 
{
	m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);

}
////////////////////////////////////////////////////////////////////
//Funcion para setear las fuerzas y gravedad aplicadas al pichinge//
void Warrior2::Update(float dt)
{
	//Aqui es donde decimos que cuando no queremos que corra el pichingo por que no hay tecla presionada
	m_Animation->SetProps("reyes_estatico", 1, 1, 100);
	m_RigidBody->UnsetForce();//con eesto lo que hacemos es que no se mueva si nadie presiona nda

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//---------------------Evaluamos las teclas presionadas por el usuario----------------------------------------\\ 

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_A))//si presionamos a
	{
		//Cuando presionamos a esta si lleva el flip horizontal para que se de la vuelta 
		m_Animation->SetProps("reyes_corriendo", 1, 8, 100, SDL_FLIP_HORIZONTAL);//le mandamos la imagen corriendo
		m_RigidBody->ApplyForceX(5 * BACKWARD);//si se le aplica fuerza va a ir cayendo para un lado
	}

	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_D))//si presionamos d
	{
		m_Animation->SetProps("reyes_corriendo", 1, 8, 100);
		m_RigidBody->ApplyForceX(5 * FORWARD);
	}
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_S))
	{
		m_Animation->SetProps("reyes_pabajo", 1, 8, 100);
		m_RigidBody->ApplyForceY(5 * DOWNWARD);

	}
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_W))
	{
		//m_Animation->SetProps("reyes_corriendo", 1, 8, 100);
		m_Animation->SetProps("reyes_parriba", 1, 8, 100);
		m_RigidBody->ApplyForceY(5 * UPWARD); //--

	}
	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_LEFT))
	{
		m_Animation->SetProps("ataqueEnfrente", 1, 5, 100);
		//m_RigidBody->ApplyForceY(0);
	}
	//while pressing altgr


	if (Input::GetInstance()->GetKeyDown(SDL_SCANCODE_RIGHT))
	{
		m_Animation->SetProps("ataqueEnfrente", 1, 5, 100, SDL_FLIP_HORIZONTAL);
		//m_RigidBody->SetGravity(-4);
		//m_RigidBody->ApplyForceY(0);
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//llamammos las updates de animacion y fisicas pues ahi esta toda la logica detras de las cositis
	m_Animation->Update();

	//SDL_Log("%f",dt);
	//m_RigidBody->Update(dt);//velocidad con la que cae el pichingo //poner 0 para clss

	m_RigidBody->Update(0.8);//velocidad con la que cae el pichingo //poner 0 para clss
	m_RigidBody->SetGravity(0);

	m_Transform->TranslateX(m_RigidBody->Position().X);
	m_Transform->TranslateY(m_RigidBody->Position().Y);

	m_Origin->X = m_Transform->X + m_Width / 2;
	m_Origin->Y = m_Transform->Y + m_Height / 2;



}
void Warrior2::UpdatePosition(float dt)
{
	m_RigidBody->Update(dt);
	m_Transform->TranslateX(m_RigidBody->Position().X);
	m_Transform->TranslateY(m_RigidBody->Position().Y);

	m_Origin->X = m_Transform->X + m_Width / 2;
	m_Origin->Y = m_Transform->Y + m_Height / 2;

	//print the position of the player
	SDL_Log("%f", m_Transform->X);
}
Vector2D Warrior2::getPosition()
{
	return Vector2D();
}
void Warrior2::Clean()
{
	TextureManager2::GetInstance()->Clean();

}
