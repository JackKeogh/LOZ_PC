#include "GameSelectScreen.h"

GameSelectScreen::GameSelectScreen() {
	m_background = new SpriteObject("Resources/Images/GameSelect_Screen.png", { 0,0, 1280, 720 }, { 0,0,3840,2160 });
}

GameSelectScreen::~GameSelectScreen() {
	delete m_background;
}

void GameSelectScreen::ExecuteEvent(SDL_Event e) {

}

void GameSelectScreen::Update(float dt) {

}

void GameSelectScreen::Render() {
	m_background->Draw();
}