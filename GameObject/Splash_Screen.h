#pragma once
#include "Screen.h"
#include "SpriteObject.h"

class SplashScreen : public Screen
{
private:
	float m_timer;
	SpriteObject* m_sprite;
	
public:
	SplashScreen();

	~SplashScreen();

	void ExecuteEvent(SDL_Event e) override;

	void Update(float dt) override;

	void Render() override;

	void Reset() override;

};