#pragma once
#include "Screen.h"
#include "SpriteObject.h"
#include <iostream>

class GameSelectScreen : public Screen {
private:
	SpriteObject* m_background;
	Object* m_mouse;

	void Mouse_Update();

public:
	GameSelectScreen();

	~GameSelectScreen();

	void ExecuteEvent(SDL_Event e) override;

	void Update(float dt) override;

	void Render() override;
};