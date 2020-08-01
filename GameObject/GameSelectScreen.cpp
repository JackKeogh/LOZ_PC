#include "GameSelectScreen.h"

GameSelectScreen::GameSelectScreen() {
	m_background = new SpriteObject("Resources/Images/GameSelect_Screen.png", { 0,0, 1280, 720 }, { 0,0,3840,2160 });
	m_mouse = new Object({ 0,0,2,2 });
}

GameSelectScreen::~GameSelectScreen() {
	delete m_background;
}

void GameSelectScreen::ExecuteEvent(SDL_Event e) {

}

void GameSelectScreen::Update(float dt) {
	Mouse_Update();
}

void GameSelectScreen::Render() {
	m_background->Draw();
}

void GameSelectScreen::Mouse_Update() {
	int x = m_mouse->getRectangle().x;
	int y = m_mouse->getRectangle().y;

	SDL_GetMouseState(&x, &y);

	m_mouse->setPosition(x, y);
}