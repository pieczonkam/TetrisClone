#pragma once

#include "includes.h"

struct BlockMaps
{
	static std::vector<std::vector<std::vector<bool>>> getRandom();
	static std::vector<std::vector<std::vector<std::vector<bool>>>> toList();

	std::vector<std::vector<std::vector<bool>>> O = {
															{
																{ false, false, false, false }, // ....
																{ false, true, true, false },   // .xx.
																{ false, true, true, false },   // .xx.
																{ false, false, false, false }  // ....
															},
															{
																{ false, false, false, false }, // ....
																{ false, true, true, false },   // .xx.
																{ false, true, true, false },   // .xx.
																{ false, false, false, false }  // ....
															},
															{
																{ false, false, false, false }, // ....
																{ false, true, true, false },   // .xx.
																{ false, true, true, false },   // .xx.
																{ false, false, false, false }  // ....
															},
															{
																{ false, false, false, false }, // ....
																{ false, true, true, false },   // .xx.
																{ false, true, true, false },   // .xx.
																{ false, false, false, false }  // ....
															}
	};
	std::vector<std::vector<std::vector<bool>>> I = {
															{
																{ false, false, false, false }, // ....
																{ true, true, true, true },     // xxxx
																{ false, false, false, false }, // ....
																{ false, false, false, false }  // ....
															},
															{
																{ false, false, true, false },  // ..x.
																{ false, false, true, false },  // ..x.
																{ false, false, true, false },  // ..x.
																{ false, false, true, false }   // ..x.
															},
															{
																{ false, false, false, false }, // ....
																{ false, false, false, false }, // ....
																{ true, true, true, true },     // xxxx
																{ false, false, false, false }  // ....
															},
															{
																{ false, true, false, false },  // .x..
																{ false, true, false, false },  // .x..
																{ false, true, false, false },  // .x..
																{ false, true, false, false }   // .x..
															}
	};
	std::vector<std::vector<std::vector<bool>>> T = {
															{
																{ false, false, false, false }, // ....
																{ false, true, false, false },  // .x..
																{ true, true, true, false },    // xxx.
																{ false, false, false, false }  // ....
															},
															{
																{ false, false, false, false }, // ....
																{ false, true, false, false },  // .x..
																{ false, true, true, false },   // .xx.
																{ false, true, false, false }   // .x..
															},
															{
																{ false, false, false, false }, // ....
																{ false, false, false, false }, // ....
																{ true, true, true, false },    // xxx.
																{ false, true, false, false }   // .x..
															},
															{
																{ false, false, false, false }, // ....
																{ false, true, false, false },  // .x..
																{ true, true, false, false },   // xx..
																{ false, true, false, false }   // .x..
															}
	};
	std::vector<std::vector<std::vector<bool>>> L = {
															{
																{ false, false, false, false }, // ....
																{ false, false, true, false },  // ..x.
																{ true, true, true, false },    // xxx.
																{ false, false, false, false }  // ....
															},
															{
																{ false, false, false, false }, // ....
																{ false, true, false, false },  // .x..
																{ false, true, false, false },  // .x..
																{ false, true, true, false }    // .xx.
															},
															{
																{ false, false, false, false }, // ....
																{ false, false, false, false }, // ....
																{ true, true, true, false },    // xxx.
																{ true, false, false, false }   // x...
															},
															{
																{ false, false, false, false }, // ....
																{ true, true, false, false },   // xx..
																{ false, true, false, false },  // .x..
																{ false, true, false, false }   // .x..
															}
	};
	std::vector<std::vector<std::vector<bool>>> J = {
															{
																{ false, false, false, false }, // ....
																{ true, false, false, false },  // x...
																{ true, true, true, false },    // xxx.
																{ false, false, false, false }  // ....
															},
															{
																{ false, false, false, false }, // ....
																{ false, true, true, false },   // .xx.
																{ false, true, false, false },  // .x..
																{ false, true, false, false }   // .x..
															},
															{
																{ false, false, false, false }, // ....
																{ false, false, false, false }, // ....
																{ true, true, true, false },    // xxx.
																{ false, false, true, false }   // ..x.
															},
															{
																{ false, false, false, false }, // ....
																{ false, true, false, false },  // .x..
																{ false, true, false, false },  // .x..
																{ true, true, false, false }    // xx..
															}
	};
	std::vector<std::vector<std::vector<bool>>> S = {
															{
																{ false, false, false, false }, // ....
																{ false, true, true, false },   // .xx.
																{ true, true, false, false },   // xx..
																{ false, false, false, false }  // ....
															},
															{
																{ false, false, false, false }, // ....
																{ false, true, false, false },  // .x..
																{ false, true, true, false },   // .xx.
																{ false, false, true, false }   // ..x.
															},
															{
																{ false, false, false, false }, // ....
																{ false, false, false, false }, // ....
																{ false, true, true, false },   // .xx.
																{ true, true, false, false }    // xx..
															},
															{
																{ false, false, false, false }, // ....
																{ true, false, false, false },  // x...
																{ true, true, false, false },   // xx..
																{ false, true, false, false }   // .x..
															}
	};
	std::vector<std::vector<std::vector<bool>>> Z = {
															{
																{ false, false, false, false }, // ....
																{ true, true, false, false },   // xx..
																{ false, true, true, false },   // .xx.
																{ false, false, false, false }  // ....
															},
															{
																{ false, false, false, false }, // ....
																{ false, false, true, false },  // ..x.
																{ false, true, true, false },   // .xx.
																{ false, true, false, false }   // .x..
															},
															{
																{ false, false, false, false }, // ....
																{ false, false, false, false }, // ....
																{ true, true, false, false },   // xx..
																{ false, true, true, false }    // .xx.
															},
															{
																{ false, false, false, false }, // ....
																{ false, true, false, false },  // .x..
																{ true, true, false, false },   // xx..
																{ true, false, false, false }   // x...
															}
	};
};

struct BlockColors
{
	static std::pair<sf::Color, sf::Color> getRandom();
	static std::vector<std::pair<sf::Color, sf::Color>> toList();

	std::pair<sf::Color, sf::Color> red{ sf::Color::Red, sf::Color(90, 0, 0) };
	std::pair<sf::Color, sf::Color> yellow{ sf::Color(255, 255, 0), sf::Color(90, 90, 0) };
	std::pair<sf::Color, sf::Color> orange{ sf::Color(255, 131, 20), sf::Color(90, 45, 5) };
	std::pair<sf::Color, sf::Color> blue{ sf::Color::Blue, sf::Color(0, 0, 90) };
	std::pair<sf::Color, sf::Color> magenta{ sf::Color::Magenta, sf::Color(90, 0, 90) };
	std::pair<sf::Color, sf::Color> green{ sf::Color::Green, sf::Color(0, 90, 0) };
	std::pair<sf::Color, sf::Color> cyan{ sf::Color::Cyan, sf::Color(0, 90, 90) };
};

struct Clock
{
	sf::Clock game;
	sf::Clock fps;

	float delta_time = 0.0f;
};

struct Vars
{
	void resetBoolVars();

	// Bool
	bool button_pressed = false;
	bool game_started = false;
	bool game_paused = false;
	bool game_pausable = true;
	bool game_over = false;
	bool block_rotable = true;

	// Others
	const sf::Vector2f game_frame_offset{ 10.0f, 10.0f };
	const sf::Vector2f game_frame_size{ 350.0f, 700.0f };
	const sf::Vector2i game_frame_layers{ 10, 20 };
	const sf::Vector2f previous_block_position{ 375.0f, 45.0f };
	const sf::Vector2f current_block_init_position{ 115.0f, -95.0f };
	const sf::Vector2f block_velocity{ 20.0f, 70.0f };
	const float block_y_speed_up_velocity = 500.0f;
	const float block_y_added_velocity = 7.0f;
	const float block_y_added_speed_up_velocity = 50.0f;
	const float block_size = 35.0f;
};

struct Music
{
	Music();
	void play();
	void pause();
	void stop();

	sf::Music music;
};
