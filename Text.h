#pragma once

#include "includes.h"

class Text : public sf::Drawable
{
	public:
		Text(float _x, float _y, int size, const std::string text_str = "", bool _center = false, sf::Color fill_color = sf::Color::White, sf::Color outline_color = sf::Color::Black, float outline_thickness = 2.0f);
		~Text();

		void setText(const std::string text_str);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	protected:
		sf::Text* text;
		sf::Font font;
		std::string current_text;
		float x, y;
		bool center;
};