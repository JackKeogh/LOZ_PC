#pragma once
#include "Screen.h"
#include "SpriteObject.h"
#include "TextObject.h"

class TitleScreen : public Screen
{
private:
	Object* m_text;
	Object* m_background;
	bool m_fadeOut;

	void FadeIn();

	void FadeOut();

public:
	TitleScreen();

	~TitleScreen();

	void ExecuteEvent(SDL_Event e) override;

	void Update(float dt) override;

	void Render() override;

	void Reset() override;
};