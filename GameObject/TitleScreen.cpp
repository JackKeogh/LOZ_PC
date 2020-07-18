#include "TitleScreen.h"

#include <iostream>

TitleScreen::TitleScreen() {
	Screen();

	m_text = new TextObject("Press any button to continue...", { 408, 540, 0, 0 }, { 0, 0, 0, 1 }, "Resources/Fonts/Hylia.ttf");
	m_background = new SpriteObject("Resources/Images/Splash_Screen.png", { 0,0,1280,720 }, { 0,0,3840,2160 });

	m_fadeOut = false;
}

TitleScreen::~TitleScreen() {
	delete m_text;
	delete m_background;
}

void TitleScreen::FadeIn() {
	int alpha = m_text->getColor().a;

	if (alpha < 255.f)
	{
		alpha += 1;
	}
	else {
		m_fadeOut = true;
	}

	m_text->setColorAlpha(alpha);
}

void TitleScreen::FadeOut() {
	int alpha = m_text->getColor().a;

	if (alpha > 1)
	{
		alpha -= 1;
	}
	else {
		m_fadeOut = false;
	}

	m_text->setColorAlpha(alpha);
}

void TitleScreen::ExecuteEvent(SDL_Event e) {
	if (e.type == SDL_KEYDOWN) {
		m_complete = true;
	}
}

void TitleScreen::Update(float dt) {

	if (m_fadeOut) {
		FadeOut();
	}
	else {
		FadeIn();
	}
}

void TitleScreen::Render() {
	m_background->Draw();
	m_text->Draw();
}

void TitleScreen::Reset() {
	Screen::Reset();

	m_fadeOut = false;
	m_text->setColor(0, 0, 0, 1);
}