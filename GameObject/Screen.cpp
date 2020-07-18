#include "Screen.h"

Screen::Screen() {
	m_running = true;
	m_quit = false;
	m_complete = false;
}

Screen::~Screen() {

}

void Screen::ExecuteEvent(SDL_Event e) {

}

void Screen::Update(float dt) {

}

void Screen::Render() {

}

void Screen::Reset() {
	m_running = true;
	m_quit = false;
	m_complete = false;
}

bool Screen::isRunning() {
	return m_running;
}

bool Screen::hasQuit() {
	return m_quit;
}

bool Screen::hasCompleted() {
	return m_complete;
}

void Screen::StopRunning() {
	m_running = false;
}