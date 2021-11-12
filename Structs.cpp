#include "Structs.h"

// BlockMaps
std::vector<std::vector<std::vector<bool>>> BlockMaps::getRandom()
{
	std::vector<std::vector<std::vector<std::vector<bool>>>> maps = toList();
	return maps[rand() % (int)maps.size()];
}

std::vector<std::vector<std::vector<std::vector<bool>>>> BlockMaps::toList()
{
	BlockMaps obj;
	std::vector<std::vector<std::vector<std::vector<bool>>>> maps = { obj.O, obj.I, obj.T, obj.L, obj.J, obj.S, obj.Z };
	return maps;
}

// BlockColors
std::pair<sf::Color, sf::Color> BlockColors::getRandom()
{
	std::vector<std::pair<sf::Color, sf::Color>> colors = toList();
	return colors[rand() % (int)colors.size()];
}

std::vector<std::pair<sf::Color, sf::Color>> BlockColors::toList()
{
	BlockColors obj;
	std::vector<std::pair<sf::Color, sf::Color>> colors = { obj.red, obj.yellow, obj.orange, obj.blue, obj.magenta, obj.green, obj.cyan };
	return colors;
}

// Clock
// Vars
void Vars::resetBoolVars()
{
	button_pressed = false;
	game_started = false;
	game_paused = false;
	game_pausable = true;
	game_over = false;
	block_rotable = true;
}

// Music
Music::Music()
{
	music.openFromFile("Tetris_theme.wav");
	music.setLoop(true);
	music.setVolume(50.0f);
}

void Music::play()
{
	if (music.getStatus() != 2) music.play();
}

void Music::pause()
{
	if (music.getStatus() != 1) music.pause();
}

void Music::stop()
{
	if (music.getStatus() != 0) music.stop();
}