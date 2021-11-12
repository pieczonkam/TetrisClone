#include "Button.h"

Button::Button(sf::RenderWindow& _window, float _x, float _y, float _width, float _height, const std::string& text_str) : window(_window), x(_x), y(_y), width(_width), height(_height)
{
	rect = new sf::RectangleShape(sf::Vector2f(width, height));
	rect->setPosition(x, y);
	rect->setFillColor(sf::Color(118, 128, 121));
	rect->setOutlineColor(sf::Color(98, 108, 101));
	rect->setOutlineThickness(-2.0f);
	
	font.loadFromFile("upheavtt.ttf");
	text = new sf::Text();
	text->setFont(font);
	text->setStyle(sf::Text::Bold);
	text->setCharacterSize(22);
	text->setString(text_str);
	text->setPosition(x + width / 2.0f - text->getLocalBounds().width / 2.0f, y + height / 2.0f - text->getLocalBounds().height - 4.0f);
	text->setFillColor(sf::Color::White);
	text->setOutlineColor(sf::Color::Black);
	text->setOutlineThickness(2.0f);
}

Button::~Button()
{
	delete rect;
	delete text;
}

bool Button::isMouseOver()
{
	sf::Vector2i mouse_position = sf::Mouse::getPosition(window);
	return mouse_position.x >= x && mouse_position.x <= x + width && mouse_position.y >= y && mouse_position.y <= y + height;
}

void Button::onDefault()
{
	if (!active)
	{
		active = true;
		hovered = false;
		clicked = false;
		inactive = false;

		rect->setFillColor(sf::Color(118, 128, 121));
		rect->setOutlineColor(sf::Color(98, 108, 101));
		text->setFillColor(sf::Color::White);
		text->setOutlineColor(sf::Color::Black);
	}
}

void Button::onHover()
{
	if (!hovered)
	{
		active = false;
		hovered = true;
		clicked = false;
		inactive = false;

		rect->setFillColor(sf::Color(98, 108, 101));
		rect->setOutlineColor(sf::Color(78, 88, 81));
		text->setFillColor(sf::Color::White);
		text->setOutlineColor(sf::Color::Black);
	}
}

void Button::onClick()
{
	if (!clicked)
	{
		active = false;
		hovered = false;
		clicked = true;
		inactive = false;

		rect->setFillColor(sf::Color(78, 88, 81));
		rect->setOutlineColor(sf::Color(58, 68, 61));
		text->setFillColor(sf::Color::White);
		text->setOutlineColor(sf::Color::Black);
	}
}

void Button::onInactive()
{
	if (!inactive)
	{
		active = false;
		hovered = false;
		clicked = false;
		inactive = true;

		rect->setFillColor(sf::Color(138, 148, 141));
		rect->setOutlineColor(sf::Color(118, 128, 121));
		text->setFillColor(sf::Color(170, 170, 170));
		text->setOutlineColor(sf::Color(110, 111, 113));
	}
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*rect);
	target.draw(*text);
}