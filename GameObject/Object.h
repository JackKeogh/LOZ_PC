#pragma once
#include "SDL_shape.h"
#include "SDL_render.h"
#include "RenderSystem.h"

#ifndef OBJECT_H
#define OBJECT_H

class Object {
protected:
	SDL_Rect m_destination;

public:
	Object(SDL_Rect r = { 0, 0, 0, 0 });

	~Object();

	virtual void Draw();
	virtual SDL_Color getColor();
	virtual void setColor(SDL_Color c);
	virtual void setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	virtual void setColorAlpha(Uint8 a);

	void setPosition(int x, int y);
	void setPosition(SDL_Rect r);

	SDL_Rect getRectangle();
};
#endif