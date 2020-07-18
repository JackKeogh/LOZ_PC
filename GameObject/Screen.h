#pragma once
#include <SDL_events.h>

class Screen {
protected:
	bool m_running;
	bool m_quit;
	bool m_complete;

public:
	Screen();

	~Screen();

	virtual void ExecuteEvent(SDL_Event e);

	virtual void Update(float dt);

	virtual void Render();

	virtual void Reset();

	bool isRunning();

	bool hasQuit();

	bool hasCompleted();

	void StopRunning();
};