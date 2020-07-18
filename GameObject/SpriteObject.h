#pragma once
#include "Object.h"
#include "Sprite.h"

class SpriteObject : public Object, Sprite
{
private:

public:
	SpriteObject(std::string c = "filepath", SDL_Rect d = { 0, 0, 32, 32 }, SDL_Rect s = { 0, 0, 32, 32 });

	~SpriteObject();

	void Draw() override;
};