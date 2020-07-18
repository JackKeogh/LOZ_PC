#pragma once
#include <string>
#include <SDL_ttf.h>
#include "Object.h"

#ifndef TEXTOBJECT_H
#define TEXTOBJECT_H

class TextObject : public Object {
protected:
	std::string m_output;
	TTF_Font* m_font;
	SDL_Color m_color;
	SDL_Texture* m_texture;

	void CreateTexture();

public:
	TextObject(std::string output = "placeholder", SDL_Rect r = { 0, 0, 0, 0 }, SDL_Color color = { 255, 255, 255, 255 }, std::string font = "Resources/Fonts/Lucida.ttf");

	~TextObject();

	void Draw() override;

	void setText(std::string s);

	SDL_Color getColor() override;

	void setColor(SDL_Color c) override;
	void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a = 255) override;
	void setColorAlpha(Uint8 a) override;
};
#endif