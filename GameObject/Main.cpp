#pragma once
#include <iostream>
#include <SDL.h>
#include "RenderSystem.h"
#include "TimeKeeper.h"
#include "TextObject.h"
#include "ScreenController.h"

int main(int argc, char* argv[])
{
	//Initialise SDL
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();
	IMG_Init(IMG_INIT_PNG);

	RenderSystem::Initialise("Zelda Rebuild", 0, 0, 1280, 720);

	Time_Keeper* m_frameControl = new Time_Keeper;
	m_frameControl->Initialise();

	// Test Object
	TextObject* m_deltaTimeText = new TextObject("0", { 0, 0, 0, 0 }, { 100,100,100,255 });

	// Test Screen Object
	ScreenController* m_controller = new ScreenController;

	while (m_controller->isRunning())
	{
		// Calculate Delta Time and display
		m_frameControl->AssignOldTime();
		m_frameControl->AssignCurrentTime();
		m_frameControl->CalculateDeltaTime();

		// Display Delta Time on Renderer
		float d = 1000 / (1000 * m_frameControl->m_DeltaTime);
		std::string s = std::to_string(static_cast<int>(d));
		m_deltaTimeText->setText(s);

		// Start frame
		m_frameControl->AssignStartFrame();

		// Event Stuff
		SDL_Event m_event;

		while (SDL_PollEvent(&m_event))
		{
			if (m_event.type == SDL_QUIT)
			{
				m_controller->StopRunning();
			}

			m_controller->ExecuteEvent(m_event);
		}
		
		// Update Stuff
		m_controller->Update(d);

		// Render Stuff
		RenderSystem::Clear();

		m_controller->Render();

#ifdef _DEBUG
		m_deltaTimeText->Draw();
#endif

		RenderSystem::Present();

		// Update Frame
		m_frameControl->CalculateFrameTime();
		m_frameControl->Check_Delay();

	}


	return 0;
}