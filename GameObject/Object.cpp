#include "Object.h"

Object::Object(SDL_Rect rect) :
	m_destination(rect)
{

}

Object::~Object() {
}

void Object::Draw()
{
	
}

SDL_Color Object::getColor() {
	return { 0,0,0,0 };
}

void Object::setColor(SDL_Color c) {

}

void Object::setColor(Uint8 r, Uint8 g, Uint8 b, Uint8 a) {

}

void Object::setColorAlpha(Uint8 a) {

}

void Object::setPosition(int x, int y) {
	m_destination.x = x;
	m_destination.y = y;
}

void Object::setPosition(SDL_Rect r)
{
	setPosition(r.x, r.y);
}

SDL_Rect Object::getRectangle()
{
	return m_destination;
}