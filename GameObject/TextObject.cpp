#include "TextObject.h"

void TextObject::CreateTexture() {
	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
	}

	SDL_Surface* surface = TTF_RenderText_Solid(m_font, m_output.c_str(), m_color);
	m_texture = SDL_CreateTextureFromSurface(RenderSystem::Renderer(), surface);

	m_destination.w = surface->w;
	m_destination.h = surface->h;

	SDL_FreeSurface(surface);
}

TextObject::TextObject(std::string s, SDL_Rect r, SDL_Color c, std::string font) :
	m_output(s), m_color(c)
{
	m_destination = r;

	// Load font
	m_font = TTF_OpenFont(font.c_str(), 32);

	CreateTexture();
}

TextObject::~TextObject() {
	TTF_CloseFont(m_font);

	SDL_DestroyTexture(m_texture);
}

void TextObject::Draw()
{
	RenderSystem::Draw(m_texture, NULL, &m_destination);
}

void TextObject::setText(std::string s) {
	m_output = s;

	CreateTexture();
}

SDL_Color TextObject::getColor() {
	return m_color;
}

void TextObject::setColor(SDL_Color c) {
	setColor(c.r, c.g, c.b, c.a);
}

void TextObject::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	m_color = { r, g, b, a };
	
	CreateTexture();
}

void TextObject::setColorAlpha(Uint8 a) {
	setColor(m_color.r, m_color.g, m_color.b, a);
}