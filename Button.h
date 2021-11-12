#pragma once

#include "includes.h"

class Button : public sf::Drawable
{
	public:
		Button(sf::RenderWindow& _window, float _x, float _y, float _width, float _height, const std::string& text_str);
		~Button();

		bool isMouseOver();
		void onDefault();
		void onHover();
		void onClick();
		void onInactive();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		bool active = true;
		bool clicked = false;
		bool hovered = false;
		bool inactive = false;

	protected:
		sf::RectangleShape* rect;
		sf::Text* text;
		sf::Font font;
		sf::RenderWindow& window;
		float x, y, width, height;
};