#include "Block.h"

Block::Block(float _x, float _y, float _size, Grid& _grid) : x(_x), y(_y), size(_size), grid(_grid)
{
	x_init = x;
	y_init = y;

	for (int i = 0; i < x_len; ++i)
	{
		std::vector<sf::RectangleShape> tmp;
		for (int j = 0; j < y_len; ++j)
		{
			sf::RectangleShape rect(sf::Vector2f(size, size));
			rect.setPosition(x + i * size, y + j * size);
			rect.setFillColor(colors.first);
			rect.setOutlineColor(colors.second);
			rect.setOutlineThickness(-2.0f);
			tmp.push_back(rect);
		}
		rects.push_back(tmp);
	}

	setMap();
	setColors();
}

std::vector<std::vector<bool>> Block::getMap()
{
	return map[map_idx];
}

std::pair<sf::Color, sf::Color> Block::getColors()
{
	return colors;
}

bool Block::collides(float new_x, float new_y)
{
	sf::Vector2i grid_len = grid.getLen();
	std::vector<std::vector<bool>> grid_map = grid.getMap();
	Vars vars;
	int x_idx = (int)((new_x - vars.game_frame_offset.x) / size) + 1, y_idx = (int)((new_y - vars.game_frame_offset.y) / size) + 4, grid_map_i, grid_map_j;

	for (int i = 0; i < x_len; ++i)
		for (int j = 0; j < y_len; ++j)
		{
			grid_map_i = x_idx + i;
			grid_map_j = y_idx + j;
			if (map[map_idx][j][i] && (grid_map_i < 0 || grid_map_i >= (grid.x_len + 2) || grid_map_j < 0 || grid_map_j >= (grid.y_len + 5) || grid_map[grid_map_i][grid_map_j])) return true;
		}
	return false;
}

sf::Vector2f Block::getPosition()
{
	return sf::Vector2f(x, y);
}

void Block::setPosition(float _x, float _y)
{
	x = _x;
	y = _y;
	for (int i = 0; i < x_len; ++i)
		for (int j = 0; j < y_len; ++j)
			rects[i][j].setPosition(x + i * size, y + j * size);
}

void Block::copy(Block& obj)
{
	setMap(obj.map);
	setColors(obj.colors);

	dx_left = dx_right = size;
	dy = 0.0f;
	BlockMaps maps;
	x = x_init;
	y = map == maps.I ? y_init + size : y_init;
	setPosition(x, y);
}

void Block::setNew(bool align)
{
	setMap();
	setColors();

	if (align)
	{
		BlockMaps maps;
		if ((map == maps.T) || (map == maps.L) || (map == maps.J) || (map == maps.S) || (map == maps.Z)) setPosition(x_init + size / 2.0f, y_init);
		else if (map == maps.I) setPosition(x_init, y_init + size / 2.0f);
		else setPosition(x_init, y_init);
	}
}

void Block::setMap()
{
	std::vector<std::vector<std::vector<bool>>> _map = BlockMaps::getRandom();
	setMap(_map);
}

void Block::setMap(std::vector<std::vector<std::vector<bool>>>& _map)
{
	map = _map;
	map_idx = 0;
}

void Block::setColors()
{
	std::pair<sf::Color, sf::Color> _colors = BlockColors::getRandom();
	setColors(_colors);
}

void Block::setColors(std::pair<sf::Color, sf::Color>& _colors)
{
	colors = _colors;
	for (int i = 0; i < x_len; ++i)
		for (int j = 0; j < y_len; ++j)
		{
			rects[i][j].setFillColor(colors.first);
			rects[i][j].setOutlineColor(colors.second);
		}
}

bool Block::moveDown(float _y)
{
	dy += _y;
	if (dy >= size)
	{
		if (collides(x, y + size)) return false;
		setPosition(x, y + size);
		dy = 0.0f;
	}
	return true;
}

bool Block::moveLeft(float _x)
{
	dx_left += _x;
	if (dx_left >= size)
	{
		if (collides(x - size, y)) return false;
		setPosition(x - size, y);
		dx_left = 0.0f;
	}
	return true;
}

bool Block::moveRight(float _x)
{
	dx_right += _x;
	if (dx_right >= size)
	{
		if (collides(x + size, y)) return false;
		setPosition(x + size, y);
		dx_right = 0.0f;
	}
	return true;
}

bool Block::rotate()
{
	int map_idx_old = map_idx;
	map_idx = (map_idx + 1) % map_len;
	if (collides(x, y))
	{
		map_idx = map_idx_old;
		return false;
	}
	return true;
}

void Block::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (int i = 0; i < x_len; ++i)
		for (int j = 0; j < y_len; ++j)
			if (map[map_idx][j][i] && rects[i][j].getPosition().y > 0.0f) target.draw(rects[i][j]); // reversed indices in map array
}