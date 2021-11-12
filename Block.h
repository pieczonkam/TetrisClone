#pragma once

#include "includes.h"
#include "Grid.h"
#include "Structs.h"

class Block : public sf::Drawable
{
	public:
		Block(float _x, float _y, float _size, Grid& _grid);

		std::vector<std::vector<bool>> getMap();
		std::pair<sf::Color, sf::Color> getColors();
		bool collides(float new_x, float new_y);
		sf::Vector2f getPosition();
		void setPosition(float _x, float _y);
		void copy(Block& obj);
		void setNew(bool align = false);
		void setMap();
		void setMap(std::vector<std::vector<std::vector<bool>>>& _map);
		void setColors();
		void setColors(std::pair<sf::Color, sf::Color>& _colors);
		bool moveDown(float _y);
		bool moveLeft(float _x);
		bool moveRight(float _x);
		bool rotate();
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		int x_len = 4, y_len = 4;
		float dx_left = 0.0f, dx_right = 0.0f, dy = 0.0f;

	protected:
		std::vector<std::vector<sf::RectangleShape>> rects; // 2d array of rects
		std::vector<std::vector<std::vector<bool>>> map;
		std::pair<sf::Color, sf::Color> colors;
		Grid& grid;
		int map_idx = 0, map_len = 4; // x, y size in rects
		float x_init, y_init, x, y, size; // (x, y) - left top corner of 4x4 block
};

