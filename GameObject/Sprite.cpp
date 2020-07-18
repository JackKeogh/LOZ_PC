#include "Sprite.h"
#include <iostream>

Sprite::Sprite() {
	m_texture = nullptr;
	m_source = { 0,0,0,0 };
}

Sprite::Sprite(std::string c, SDL_Rect r) :
	m_source(r)
{
	SDL_Surface* surface = IMG_Load(c.c_str());

	if (!surface) {
		std::cout << IMG_GetError << std::endl;
		exit(-1);
	}
	else {
		m_texture = SDL_CreateTextureFromSurface(RenderSystem::Renderer(), surface);

		SDL_FreeSurface(surface);
	}
}

Sprite::~Sprite() {
	SDL_DestroyTexture(m_texture);
}

SDL_Rect Sprite::getSource() {
	return m_source;
}

void Sprite::setSource(int x, int y, int w, int h) {
	m_source = { x, y, w, h };
}

void Sprite::setSource(SDL_Rect r) {
	setSource(r.x, r.y, r.w, r.h);
}

void Sprite::setSourcePosition(int x, int y) {
	setSource(x, y, m_source.w, m_source.h);
}

void Sprite::setSourcePosition(SDL_Rect r) {
	setSource(r.x, r.y, m_source.w, m_source.h);
}

void Sprite::setSourceDimensions(int w, int h) {
	setSource(m_source.x, m_source.y, w, h);
}

void Sprite::setSourceDimensions(SDL_Rect r) {
	setSource(m_source.x, m_source.y, r.w, r.h);
}

SDL_Texture* Sprite::getTexture() {
	return m_texture;
}

void Sprite::loadNewTexture(const char* c) {
	SDL_DestroyTexture(m_texture);

	m_texture = IMG_LoadTexture(RenderSystem::Renderer(), c);
}

void Sprite::setTexture(SDL_Texture* t) {
	SDL_DestroyTexture(m_texture);

	m_texture = t;
}