#pragma once
#include "TextObject.h"
#include <iostream>

class UITextObject : public TextObject
{
private:
	SDL_Color m_originalColor;
	SDL_Color m_highlightColor;
	bool m_highlighted;

public:
	UITextObject(SDL_Color o = { 255,255,255,255 }, SDL_Color h = { 56,182,241,255 }, std::string s = "Placeholder", SDL_Rect r = { 0, 0, 0, 0 },
		SDL_Color color = { 255,255,255,255 }, std::string font = "Resources/Fonts/Lucida.ttf");

	~UITextObject();

	void Highlight();

	void RemoveHighlight();

	bool is_Highlighted();
};