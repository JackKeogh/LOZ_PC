#pragma once
#include <iostream>
#include <map>
#include "Menu.h"
#include "SpriteObject.h"

class Collision {
public:
	static void Mouse_Menu_Collision(Object* mouse, std::map<Key, UITextObject*> items);
};