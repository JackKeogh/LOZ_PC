#include "TimeKeeper.h"

Time_Keeper::Time_Keeper() {
	m_OldTime = 0;
	m_CurrentTime = 0;
	m_DeltaTime = 0.f;

	m_StartFrame = 0;
	m_FrameTime = 0;
}

void Time_Keeper::Initialise() {
	m_CurrentTime = SDL_GetTicks();
}

void Time_Keeper::AssignOldTime() {
	m_OldTime = m_CurrentTime;
}

void Time_Keeper::AssignCurrentTime() {
	m_CurrentTime = SDL_GetTicks();
}

void Time_Keeper::AssignStartFrame() {
	m_StartFrame = SDL_GetTicks();
}

void Time_Keeper::CalculateDeltaTime() {
	m_DeltaTime = (m_CurrentTime - m_OldTime) / OneSecond;
}

void Time_Keeper::CalculateFrameTime() {
	m_FrameTime = SDL_GetTicks() - m_StartFrame;
}

void Time_Keeper::Check_Delay() {
	if (m_FrameDelay > m_FrameTime)
	{
		Run_Delay();
	}
}

void Time_Keeper::Run_Delay() {
	Uint32 delay = static_cast<Uint32>(m_FrameDelay - m_FrameTime);

	SDL_Delay(delay);
}

void Time_Keeper::DisplayDeltaTime()
{
	float DT = 1000.f / (m_DeltaTime * 1000);

	std::cout << DT << std::endl;
}