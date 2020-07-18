#include "RenderSystem.h"

SDL_Renderer* RenderSystem::m_renderer = 0;
SDL_Window* RenderSystem::m_window = 0;

RenderSystem::RenderSystem() {

}

RenderSystem::~RenderSystem() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void RenderSystem::Initialise(std::string title, int x, int y, int w, int h) {
	if (x == 0 && y == 0) {
		m_window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w, h, NULL);
	}
	else {
		m_window = SDL_CreateWindow(title.c_str(), x, y, w, h, NULL);
	}

	m_renderer = SDL_CreateRenderer(m_window, -1, NULL);
}

SDL_Renderer* RenderSystem::Renderer() {
	return m_renderer;
}

void RenderSystem::Clear() {
	SDL_RenderClear(m_renderer);
}

void RenderSystem::Present() {
	SDL_RenderPresent(m_renderer);
}

void RenderSystem::Draw(SDL_Texture* texture, SDL_Rect* SrcRect, SDL_Rect* DstRect) {
	SDL_RenderCopy(m_renderer, texture, SrcRect, DstRect);
}