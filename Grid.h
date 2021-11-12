#pragma once

#include "includes.h"

class Grid : public sf::Drawable
{
	public:
		Grid(float _x, float _y, float _width, float _height, int _x_len, int _y_len, float _block_size);

		sf::Vector2i getLen();
		std::vector<std::vector<bool>> getMap();
		void resetBlocks();
		void resetMap();
		void setBlock(int _x, int _y, sf::Color fill_color, sf::Color outline_color);
		void setMap(int _x, int _y, bool value);
		bool isLineFull(int _y);
		std::vector<int> getFullLines();
		bool isGameOver();
		void moveBlocksDown(int _y);
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

		int x_len, y_len;

	protected:
		std::vector<std::vector<sf::RectangleShape>> blocks;
		std::vector<std::vector<bool>> map;
		float x, y, width, height, block_size;
};