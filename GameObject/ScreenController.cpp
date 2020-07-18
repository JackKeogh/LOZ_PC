#include "ScreenController.h"

ScreenController::ScreenController() {
	Initialise();
}

ScreenController::~ScreenController() {

}

void ScreenController::Initialise() {
	m_current = ScreenType::Splash;

	// Splash Screen
	m_screens.insert(std::pair<ScreenType, Screen*>(ScreenType::Splash, new SplashScreen));

	// Title Screen
	m_screens.insert(std::pair<ScreenType, Screen*>(ScreenType::Title, new TitleScreen));

	// Main Menu Screen
	m_screens.insert(std::pair<ScreenType, Screen*>(ScreenType::MainMenu, new MainMenuScreen));
}

void ScreenController::ExecuteEvent(SDL_Event e) {
	m_screens[m_current]->ExecuteEvent(e);
}

void ScreenController::Update(float dt) {

	m_screens[m_current]->Update(dt);

	ChangeScreen();
}

void ScreenController::Render() {
	m_screens[m_current]->Render();
}

void ScreenController::ChangeScreen() {
	if (m_current == ScreenType::Splash)
	{
		if (m_screens[m_current]->hasCompleted())
		{
			m_screens[m_current]->Reset();
			m_current = ScreenType::Title;
		}
	}
	else if (m_current == ScreenType::Title)
	{
		if (m_screens[m_current]->hasCompleted())
		{
			m_screens[m_current]->Reset();
			m_current = ScreenType::MainMenu;
		}
	}
	else if (m_current == ScreenType::MainMenu)
	{
		if (m_screens[m_current]->hasQuit())
		{
			StopRunning();
		}
	}
}

bool ScreenController::isRunning() {
	return m_screens[m_current]->isRunning();
}

void ScreenController::StopRunning() {
	m_screens[m_current]->StopRunning();
}