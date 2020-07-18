#pragma once
#include <SDL.h>
#include <string>

#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

class RenderSystem {
private:
	static SDL_Renderer* m_renderer;
	static SDL_Window* m_window;

public:
	RenderSystem();

	~RenderSystem();

	static void Initialise(std::string title = "Game", int x = 0, int y = 0, int w = 500, int h = 500);

	static SDL_Renderer* Renderer();

	static void Clear();

	static void Present();

	static void Draw(SDL_Texture* Texture, SDL_Rect* SrcRect, SDL_Rect* DstRect);
};
#endif