#include "Collision.h"

void Collision::Mouse_Menu_Collision(Object* mouse, std::map<Key, UITextObject*> items)
{
	SDL_Rect mouse_rect = mouse->getRectangle();

	std::map<Key, UITextObject*>::iterator iter;

	for (iter = items.begin(); iter != items.end(); iter++)
	{
		SDL_Rect item_rect = iter->second->getRectangle();

		if ((mouse_rect.x >= item_rect.x && mouse_rect.x <= item_rect.x + item_rect.w) ||
			(mouse_rect.x + mouse_rect.w >= item_rect.x && mouse_rect.x + mouse_rect.w <= item_rect.x + item_rect.w))
		{
			if ((mouse_rect.y >= item_rect.y && mouse_rect.y <= item_rect.y + item_rect.h) ||
				(mouse_rect.y + mouse_rect.h >= item_rect.y && mouse_rect.y + mouse_rect.h <= item_rect.y + item_rect.h))
			{
				iter->second->Highlight();
			}
			else
			{
				iter->second->RemoveHighlight();
			}
		}
		else
		{
			iter->second->RemoveHighlight();
		}
	}
}