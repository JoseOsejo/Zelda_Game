#include "TextureManager2.h"
//#include "TextureManager.h"
//#include "Engine.h"
#include "_2Win.h"


//include camara
#include "Camera.h"

TextureManager2* TextureManager2::s_Instance = nullptr;

bool TextureManager2::Load(std::string id, std::string fileName)
{
	SDL_Surface* surface = IMG_Load(fileName.c_str());
	if (surface == nullptr)//verificar si la imagen se cargo
	{
		SDL_Log("No sirvio esta madre en la parte de cargar la textura:%s, %s", fileName.c_str(), SDL_GetError());
		return false;
	}
	SDL_Texture* texture = SDL_CreateTextureFromSurface(_2Win::GetInstance()->GetRenderer(), surface);//cargar la textura
	if (texture == nullptr)//asegurarnos que todo esto de la creacion de la texture funciona 
	{
		SDL_Log("No sirvio esta madre en la parte de crear la textura de la superficie :%s, %s", fileName.c_str(), SDL_GetError());
		return false;
	}
	m_TextureMap[id] = texture;//llamamos esto aca para que no se creee la textura dos veces o sino para que  que se cree el mapa de texturas
	return true;
}

void TextureManager2::Draw(std::string id, int x, int y, int width, int height, SDL_RendererFlip flip)//para dibujar la imagen en la pantalla
{

	SDL_Rect srcRect = { 0,0,width, height };//parte que se mostrara de la imagen
	Vector2D cam = Camera::GetInstance()->GetPosition() * 0.5;
	SDL_Rect dstRect = { x - cam.X, y - cam.Y, width, height };
	SDL_Rect destRect = { x, y, width, height };//parte que se mostrara de la imagen
	SDL_RenderCopyEx(_2Win::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &destRect, 0, nullptr, flip);//PARA TENER MAS COMPONENTES COMO EL ANGULO del pichingo y asi y poder rtarlo

}

void TextureManager2::DrawFrame(std::string id, int x, int y, int width, int height, int row, int frame, SDL_RendererFlip flip)//para dibujar la imagen en la pantalla
{
	SDL_Rect srcRect = { width * frame,height * (row - 1), width, height };
	Vector2D cam = Camera::GetInstance()->GetPosition();
	SDL_Rect dstRect = { x - cam.X, y - cam.Y, width, height };
	SDL_RenderCopyEx(_2Win::GetInstance()->GetRenderer(), m_TextureMap[id], &srcRect, &dstRect, 0, nullptr, flip);
}

void TextureManager2::DrawTile(std::string tilesetID, int tileSize, int x, int y, int row, int frame, SDL_RendererFlip flip)
{

	SDL_Rect srcRect = { frame * tileSize,tileSize * row,tileSize,tileSize };

	Vector2D cam = Camera::GetInstance()->GetPosition();
	SDL_Rect dstRect = { x - cam.X,y - cam.Y,tileSize,tileSize };
	SDL_RenderCopyEx(_2Win::GetInstance()->GetRenderer(), m_TextureMap[tilesetID], &srcRect, &dstRect, 0, 0, flip);

}
//void TextureManager::DrawTile(std::string p_id, int p_tilesize, int p_x, int p_y, int p_row, int p_frame, SDL_RendererFlip p_flip)
//{
//	SDL_Rect srcRect = { p_frame * p_tilesize, p_row * p_tilesize, p_tilesize, p_tilesize };
//
//	Vector2D camera = Camera::GetInstance()->GetPosition();
//	SDL_Rect destRect = { p_x - camera.x, p_y - camera.y, p_tilesize, p_tilesize };
//
//	SDL_RenderCopyEx(Engine::GetInstance()->GetRenderer(), TextureMap[p_id], &srcRect, &destRect, 0, nullptr, p_flip);
//}

void TextureManager2::Drop(std::string id)
{
	SDL_DestroyTexture(m_TextureMap[id]);
	m_TextureMap.erase(id);
}
void TextureManager2::Clean()
{
	//we wanna clean everything ehwn the game is closed 
	std::map<std::string, SDL_Texture*>::iterator it;
	for (it = m_TextureMap.begin(); it != m_TextureMap.end(); it++)
		SDL_DestroyTexture(it->second);

	m_TextureMap.clear();
	SDL_Log("Texture map clean up complete :) ");
}



