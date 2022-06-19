//include npc.h
#include "NPC.h"
#include "TextureManager.h"
#include <SDL2/SDL.h>
#include "Input.h"
//Correr en lab pero cambiando abajo la gravedad 

NPC::NPC(Properties* props) : Character(props)
{
	//Le aplicacamos las animaciones al pichingo y las fisicas 
	m_RigidBody = new RigidBodyNPC();
	m_Animation = new Animation();


	//1 row ,2 frames , velocidad de animacion
	m_Animation->SetProps(m_TextureID, 1, 8, 100);

}

void NPC::Draw()//draw the player on the screen 
{
	m_Animation->Draw(m_Transform->X, m_Transform->Y, m_Width, m_Height);

}
////////////////////////////////////////////////////////////////////
//Funcion para setear las fuerzas y gravedad aplicadas al pichinge//
void NPC::Update(float dt)
{
	//Aqui es donde decimos que cuando no queremos que corra el pichingo por que no hay tecla presionada
	m_Animation->SetProps("tod", 1, 1, 100);
	m_RigidBody->UnsetForce();//con eesto lo que hacemos es que no se mueva si nadie presiona nda

	////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
	/////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	//llamammos las updates de animacion y fisicas pues ahi esta toda la logica detras de las cositis
	m_Animation->Update();

	//SDL_Log("%f",dt);
	//m_RigidBody->Update(dt);//velocidad con la que cae el pichingo //poner 0 para clss

	m_RigidBody->Update(0.7);//velocidad con la que cae el pichingo //poner 0 para clss
	m_RigidBody->SetGravity(0);

	m_Transform->TranslateX(m_RigidBody->Position().X);
	m_Transform->TranslateY(m_RigidBody->Position().Y);

	m_Origin->X = m_Transform->X + m_Width / 2;
	m_Origin->Y = m_Transform->Y + m_Height / 2;



}
void NPC::Clean()
{
	TextureManager::GetInstance()->Clean();

}
