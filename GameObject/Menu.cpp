#include "Menu.h"

Menu::Menu() {
	m_highlighted = Key::NONE;
}

Menu::~Menu() {
	m_objects.clear();
}

void Menu::addItem(Key key, UITextObject* value) {
	m_objects.insert(std::pair<Key, UITextObject*>(key, value));
}

std::map<Key, UITextObject*> Menu::getItems() {
	return m_objects;
}

UITextObject* Menu::getItem(Key key) {
	return m_objects[key];
}

Key Menu::getActiveItem() {
	return m_highlighted;
}

void Menu::Render() {
	std::map<Key, UITextObject*>::iterator iter;

	for (iter = m_objects.begin(); iter != m_objects.end(); iter++)
	{
		iter->second->Draw();
	}
}