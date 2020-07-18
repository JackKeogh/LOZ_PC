#include "Splash_Screen.h"
#include <iostream>

SplashScreen::SplashScreen() {
	m_timer = 0.f;
	m_sprite = new SpriteObject("Resources/Images/Splash_Screen.png", { 0,0,1280,720 }, { 0,0,3840,2160 });
}

SplashScreen::~SplashScreen() {

}

void SplashScreen::ExecuteEvent(SDL_Event e) {

}

void SplashScreen::Update(float dt) {
	m_timer += 1.0f / dt;

	if (m_timer >= 10) {
		m_complete = true;
	}
}


void SplashScreen::Render() {
	m_sprite->Draw();
}

void SplashScreen::Reset() {
	Screen::Reset();

	m_timer = 0.f;
}