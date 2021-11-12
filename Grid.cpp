#include "Grid.h"

Grid::Grid(float _x, float _y, float _width, float _height, int _x_len, int _y_len, float _block_size) : x(_x), y(_y), width(_width), height(_height), x_len(_x_len), y_len(_y_len), block_size(_block_size)
{
	for (int i = 0; i < x_len; ++i)
	{
		std::vector<sf::RectangleShape> blocks_tmp;
		for (int j = 0; j < y_len; ++j)
		{
			sf::RectangleShape rect(sf::Vector2f(block_size, block_size));
			rect.setPosition(x + i * block_size, y + j * block_size);
			rect.setFillColor(sf::Color::Transparent);
			rect.setOutlineColor(sf::Color::Transparent);
			rect.setOutlineThickness(-2.0f);
			blocks_tmp.push_back(rect);
		}
		blocks.push_back(blocks_tmp);
	}
	for (int i = 0; i < x_len + 2; ++i)
	{
		std::vector<bool> map_tmp;
		for (int j = 0; j < y_len + 5; ++j)
		{
			if (i == 0 || i == x_len + 1 || j == y_len + 4) map_tmp.push_back(true);
			else map_tmp.push_back(false);
		}
		map.push_back(map_tmp);
	}
}

sf::Vector2i Grid::getLen()
{
	return sf::Vector2i(x_len, y_len);
}

std::vector<std::vector<bool>> Grid::getMap()
{
	return map;
}

void Grid::resetBlocks()
{
	for(int i = 0; i < x_len; ++i)
		for (int j = 0; j < y_len; ++j)
		{
			blocks[i][j].setFillColor(sf::Color::Transparent);
			blocks[i][j].setOutlineColor(sf::Color::Transparent);
		}
}

void Grid::resetMap()
{
	for (int i = 0; i < x_len + 2; ++i)
		for (int j = 0; j < y_len + 5; ++j)
		{
			if (i == 0 || i == x_len + 1 || j == y_len + 4) map[i][j] = true;
			else map[i][j] = false;
		}
}


void Grid::setBlock(int _x, int _y, sf::Color fill_color, sf::Color outline_color)
{
	blocks[_x][_y].setFillColor(fill_color);
	blocks[_x][_y].setOutlineColor(outline_color);
}

void Grid::setMap(int _x, int _y, bool value)
{
	map[_x][_y] = value;
}

bool Grid::isLineFull(int _y)
{
	for (int i = 1; i < x_len + 1; ++i)
		if (!map[i][_y]) return false;
	return true;
}

std::vector<int> Grid::getFullLines()
{
	std::vector<int> full_lines;
	for (int j = 4; j < y_len + 4; ++j)
		if (isLineFull(j))
			full_lines.push_back(j - 4);
	return full_lines;
}

bool Grid::isGameOver()
{
	for (int i = 1; i < x_len + 1; ++i)
		for (int j = 0; j < 4; ++j)
			if (map[i][j]) return true;
	return false;
}

void Grid::moveBlocksDown(int _y) // _y - full line
{
	_y -= 1;
	// blocks array
	int y_idx;
	for (int i = 0; i < x_len; ++i)
	{
		for (int j = _y; j >= 0; --j)
		{
			y_idx = j + 1;
			if (y_idx < y_len) setBlock(i, y_idx, blocks[i][j].getFillColor(), blocks[i][j].getOutlineColor());
		}
		setBlock(i, 0, sf::Color(30, 30, 30), sf::Color(30, 30, 30));
	}
	// map array
	for (int i = 1; i < x_len + 1; ++i)
	{
		for (int j = _y + 4; j >= 4; --j)
		{
			y_idx = j + 1;
			if (y_idx < y_len + 5) setMap(i, y_idx, map[i][j]);
		}
		setMap(i, 4, false);
	}
}

void Grid::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0, map_i = 1; i < x_len; ++i, ++map_i)
		for (int j = 0, map_j = 4; j < y_len; ++j, ++map_j)
			if (map[map_i][map_j]) target.draw(blocks[i][j]); // map starts from 1 because 0 index is for wall (4 in y axis because of extra space above game frame)
}