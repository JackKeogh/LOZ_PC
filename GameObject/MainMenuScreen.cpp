#include "MainMenuScreen.h"

void MainMenuScreen::MouseUpdate() {
	int x = m_mouse->getRectangle().x;
	int y = m_mouse->getRectangle().y;

	SDL_GetMouseState(&x, &y);

	m_mouse->setPosition(x, y);
}

MainMenuScreen::MainMenuScreen() {
	m_mouse = new Object({ 0,0,2,2 });

	m_menu = new Menu();

	m_background = new SpriteObject("Resources/Images/MainMenu_Screen.png", { 0,0, 1280, 720 }, { 0,0,3840,2160 });
	
	m_menu->addItem(Key::Play, new UITextObject({ 0,0,0,255 }, { 56,182,241,255 }, "Play", { 10,594,0,0 }, { 0,0,0,255 }, "Resources/Fonts/Hylia.ttf"));
	m_menu->addItem(Key::Options, new UITextObject({ 0,0,0,255 }, { 56,182,241,255 }, "Options", { 10,636,0,0 }, { 0,0,0,255 }, "Resources/Fonts/Hylia.ttf"));
	m_menu->addItem(Key::Exit, new UITextObject({ 0,0,0,255 }, { 56,182,241,255 }, "Exit", { 10,678,0,0 }, { 0,0,0,255 }, "Resources/Fonts/Hylia.ttf"));
}

MainMenuScreen::~MainMenuScreen() {
	delete m_mouse;

	delete m_menu;

}

void MainMenuScreen::ExecuteEvent(SDL_Event e) {
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			std::cout << "Left Mouse Button Pressed" << std::endl;
		}
	}
}

void MainMenuScreen::Update(float dt) {
	MouseUpdate();

	Collision::Mouse_Menu_Collision(m_mouse, m_menu->getItems());
}

void MainMenuScreen::Render() {
	m_background->Draw();
	m_menu->Render();
}