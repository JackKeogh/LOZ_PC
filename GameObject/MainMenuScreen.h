#pragma once
#include "Screen.h"
#include "Menu.h"
#include "SpriteObject.h"
#include <iostream>
#include "Collision.h"

class MainMenuScreen : public Screen
{
private:
	Object* m_mouse;
	Menu* m_menu;
	SpriteObject* m_background;

	void MouseUpdate();

public:

	MainMenuScreen();

	~MainMenuScreen();

	void ExecuteEvent(SDL_Event e) override;

	void Update(float dt) override;

	void Render() override;

};