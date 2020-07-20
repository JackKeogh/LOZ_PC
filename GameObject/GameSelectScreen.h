#pragma once
#include "Screen.h"
#include "SpriteObject.h"
#include <iostream>

class GameSelectScreen : public Screen {
private:
	SpriteObject* m_background;

public:
	GameSelectScreen();

	~GameSelectScreen();

	void ExecuteEvent(SDL_Event e) override;

	void Update(float dt) override;

	void Render() override;
};