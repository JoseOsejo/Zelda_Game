#include "Animation.h"
#include "TextureManager.h"

void Animation::Update()
{
	m_SpriteFrame = (SDL_GetTicks()/m_AnimSpeed) % m_FrameCount;//esto sirve para que cambie de frame cada cierto tiempo (en este caso cada 100 milisegundos) y que no se pase de los frames que hay en la animacion
}
void Animation::Draw(float x, float y, int spritWidth, int spriteHeight)
{
	TextureManager::GetInstance()->DrawFrame(m_TextureID, x, y, spritWidth, spriteHeight, m_SpriteRow,m_SpriteFrame, m_Flip);
}
void Animation::SetProps(std::string textureID, int spriteRow, int frameCount, int animSpeed, SDL_RendererFlip flip)
{	
	m_TextureID=textureID;	
	m_SpriteRow=spriteRow;
	m_FrameCount=frameCount;
	m_AnimSpeed=animSpeed;
	m_Flip=flip;
}



