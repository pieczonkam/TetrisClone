#include "Text.h"

Text::Text(float _x, float _y, int size, const std::string text_str, bool _center, sf::Color fill_color, sf::Color outline_color, float outline_thickness) : current_text(text_str), x(_x), y(_y), center(_center)
{
	font.loadFromFile("upheavtt.ttf");
	text = new sf::Text();
	text->setFont(font);
	text->setStyle(sf::Text::Bold);
	text->setCharacterSize(size);
	text->setString(text_str);
	center ? text->setPosition(x - text->getLocalBounds().width / 2.0f, y - text->getLocalBounds().height / 2.0f - 15.0f) : text->setPosition(x, y);
	text->setFillColor(fill_color);
	text->setOutlineColor(outline_color);
	text->setOutlineThickness(outline_thickness);
}

Text::~Text()
{
	delete text;
}

void Text::setText(const std::string text_str)
{
	if (current_text != text_str)
	{
		current_text = text_str;
		text->setString(text_str);
		if (center)
			text->setPosition(x - text->getLocalBounds().width / 2.0f, y - text->getLocalBounds().height / 2.0f - 15.0f);
	}
}

void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*text);
}