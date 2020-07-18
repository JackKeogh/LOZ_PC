#pragma once
#include <iostream>
#include <SDL.h>

constexpr auto OneSecond = 1000.f;

#ifndef TIME_KEEPER_H
#define TIME_KEEPER_H

struct Time_Keeper {
	// Delta Time variables.
	Uint32 m_OldTime;
	Uint32 m_CurrentTime;
	float m_DeltaTime;

	// Frame Rate Control.
	Uint32 m_StartFrame;
	const int m_FPS = 65;
	const float m_FrameDelay = OneSecond / m_FPS;
	int m_FrameTime;

	Time_Keeper();

	void Initialise();

	void AssignOldTime();

	void AssignCurrentTime();

	void AssignStartFrame();

	void CalculateDeltaTime();

	void CalculateFrameTime();

	void Check_Delay();

	void Run_Delay();

	void DisplayDeltaTime();
};
#endif