#include "Frame.h"

Frame::Frame(float x, float y, float width, float height, sf::Color fill_color, sf::Color outline_color, int x_len, int y_len, float block_size, sf::Color mesh_color, float outline_thickness)
{
	rect = new sf::RectangleShape(sf::Vector2f(width, height));
	rect->setPosition(x, y);
	rect->setFillColor(fill_color);
	rect->setOutlineColor(outline_color);
	rect->setOutlineThickness(outline_thickness);

	for (int i = 0; i < x_len; ++i)
	{
		std::vector<sf::RectangleShape> mesh_tmp;
		for (int j = 0; j < y_len; ++j)
		{
			sf::RectangleShape rect(sf::Vector2f(block_size, block_size));
			rect.setPosition(x + i * block_size, y + j * block_size);
			rect.setFillColor(fill_color);
			rect.setOutlineColor(mesh_color);
			rect.setOutlineThickness(-outline_thickness / 2.0f);
			mesh_tmp.push_back(rect);
		}
		mesh.push_back(mesh_tmp);
	}
}

Frame::~Frame()
{
	delete rect;
}

void Frame::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(*rect);
	
	int x_len = (int)mesh.size(), y_len;
	if (x_len > 0)
	{
		y_len = (int)mesh[0].size();
		for (int i = 0; i < x_len; ++i)
			for (int j = 0; j < y_len; ++j)
				target.draw(mesh[i][j]);
	}
}