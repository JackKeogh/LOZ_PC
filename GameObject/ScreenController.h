#pragma once
#include <map>
#include <string>
#include "Splash_Screen.h"
#include "TitleScreen.h"
#include "MainMenuScreen.h"

enum class ScreenType {
	Splash,
	Title,
	MainMenu,
	LoadGame
};

class ScreenController {
private:
	std::map<ScreenType, Screen*> m_screens;
	ScreenType m_current;

public:
	ScreenController();

	~ScreenController();

	void Initialise();

	void ExecuteEvent(SDL_Event e);

	void Update(float dt);

	void Render();

	void ChangeScreen();

	bool isRunning();

	void StopRunning();
};