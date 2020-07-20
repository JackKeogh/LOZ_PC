#include "UITextObject.h"

UITextObject::UITextObject(SDL_Color o, SDL_Color h, std::string s, SDL_Rect r, SDL_Color color, std::string font) :
	m_originalColor(o), m_highlightColor(h)
{
	m_highlighted = false;

	m_destination = r;
	m_output = s;
	m_color = color;

	// Load font
	m_font = TTF_OpenFont(font.c_str(), 32);

	CreateTexture();

	if (m_texture == nullptr)
	{
		std::cout << "Failed to create texture" << std::endl;
	}
}

UITextObject::~UITextObject() {

}

void UITextObject::Highlight() {
	if (!m_highlighted)
	{
		m_highlighted = true;
		setColor(m_highlightColor);
	}
}

void UITextObject::RemoveHighlight() {
	if (m_highlighted)
	{
		m_highlighted = false;
		setColor(m_originalColor);
	}
}

bool UITextObject::is_Highlighted()
{
	return m_highlighted;
}
