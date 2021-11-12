#pragma once

#include "includes.h"

class Frame : public sf::Drawable
{
	public:
		Frame(float x, float y, float width, float height, sf::Color fill_color, sf::Color outline_color = sf::Color::Transparent, int x_len = 0, int y_len = 0, float block_size = 0.0f, sf::Color mesh_color = sf::Color::Transparent, float outline_thickness = 2.0f);
		~Frame();

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	protected:
		sf::RectangleShape* rect;
		std::vector<std::vector<sf::RectangleShape>> mesh;
};