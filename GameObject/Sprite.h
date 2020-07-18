#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "RenderSystem.h"
#include <string>

class Sprite {
protected:
	SDL_Rect m_source;
	SDL_Texture* m_texture;

public:
	Sprite();

	Sprite(std::string s, SDL_Rect r = { 0,0,0,0 });

	~Sprite();

	SDL_Rect getSource();
	void setSourcePosition(int x, int y);
	void setSourcePosition(SDL_Rect r);
	void setSourceDimensions(int w, int h);
	void setSourceDimensions(SDL_Rect r);
	void setSource(int x, int y, int w, int h);
	void setSource(SDL_Rect r);

	SDL_Texture* getTexture();
	void loadNewTexture(const char* c);
	void setTexture(SDL_Texture* t);
};