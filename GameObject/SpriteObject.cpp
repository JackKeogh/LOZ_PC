#include "SpriteObject.h"

SpriteObject::SpriteObject(std::string c, SDL_Rect r, SDL_Rect s) :
	Object(r), Sprite(c, s)
{
	
}

SpriteObject::~SpriteObject() {

}

void SpriteObject::Draw() {
	RenderSystem::Draw(m_texture, &m_source, &m_destination);
}