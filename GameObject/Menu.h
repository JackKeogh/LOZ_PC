#pragma once
#include "UITextObject.h"
#include <iostream>
#include <map>

enum class Key {
	NONE,
	Play,
	Options,
	Exit
};

class Menu {
private:
	std::map<Key, UITextObject*> m_objects;
	Key m_highlighted;

public:
	Menu();

	~Menu();

	void addItem(Key, UITextObject* value);

	std::map<Key, UITextObject*> getItems();

	UITextObject* getItem(Key key);

	Key getActiveItem();

	void Render();
};