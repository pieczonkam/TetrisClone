#include "includes.h"

#include "Frame.h"
#include "Text.h"
#include "Button.h"
#include "Block.h"
#include "Grid.h"
#include "Structs.h"

/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
float getFps(Clock& clock)
{
	return 1.0f / clock.fps.restart().asSeconds();
}

void setBlock(Block& block, Grid& grid)
{
	Vars vars;
	int blocks_x_idx = (int)((block.getPosition().x - vars.game_frame_offset.x) / vars.block_size), blocks_y_idx = (int)((block.getPosition().y - vars.game_frame_offset.y) / vars.block_size), blocks_i, blocks_j;
	int map_x_idx = blocks_x_idx + 1, map_y_idx = blocks_y_idx + 4, map_i, map_j;
	std::vector<std::vector<bool>> block_map = block.getMap();
	std::pair<sf::Color, sf::Color> block_colors = block.getColors();

	for (int i = 0; i < block.x_len; ++i)
		for (int j = 0; j < block.y_len; ++j)
		{
			blocks_i = blocks_x_idx + i;
			blocks_j = blocks_y_idx + j;
			map_i = map_x_idx + i;
			map_j = map_y_idx + j;
			if (block_map[j][i])
			{
				if (blocks_j >= 0) grid.setBlock(blocks_i, blocks_j, block_colors.first, block_colors.second);
				grid.setMap(map_i, map_j, true);
			}
		}
}

/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int main()
{
	/*
	_CrtMemState sOld;
	_CrtMemState sNew;
	_CrtMemState sDiff;
	_CrtMemCheckpoint(&sOld); //take a snapshot
	*/

	srand((unsigned int)time(NULL));

	{
		// Screen & Event
		sf::RenderWindow window(sf::VideoMode(530, 720), "Tetris", sf::Style::Titlebar | sf::Style::Close);
		sf::Image icon;
		icon.loadFromFile("tetris_logo.png");
		window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
		sf::Event event;
		window.setFramerateLimit(60);

		// Others
		Music music;
		Clock clock;
		Vars vars;
		Grid grid(vars.game_frame_offset.x, vars.game_frame_offset.y, vars.game_frame_size.x, vars.game_frame_size.y, vars.game_frame_layers.x, vars.game_frame_layers.y, vars.block_size);
		int score = 0;
		int level = 0;
		float block_y_velocity = vars.block_velocity.y + vars.block_y_added_speed_up_velocity * level;
		bool first_game = true;

		// Drawable
		Frame next_piece_frame(370.0f, 40.0f, 150.0f, 150.0f, sf::Color(118, 128, 121), sf::Color(98, 108, 101));
		Frame game_frame(10.0f, 10.0f, 350.0f, 700.0f, sf::Color(30, 30, 30), sf::Color(70, 70, 70), vars.game_frame_layers.x, vars.game_frame_layers.y, vars.block_size, sf::Color(70, 70, 70));
		Text next_piece_text(370.0f, 5.0f, 25, "Next piece");
		Text info_text(180.0f, 355.0f, 34, "", true);
		Text score_text(370.0f, 190.0f, 25, "Score:\n" + std::to_string(score));
		Text level_text(370.0f, 260.0f, 25, "Level:\n" + std::to_string(level + 1));
		Button button(window, 370.f, 660.f, 150.f, 50.f, "Start game");

		Block previous_block(vars.previous_block_position.x, vars.previous_block_position.y, vars.block_size, grid);
		Block current_block(vars.current_block_init_position.x, vars.current_block_init_position.y, vars.block_size, grid);

		/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
		// Game loop
		while (window.isOpen())
		{
			clock.delta_time = clock.game.restart().asSeconds();

			/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
			// Events
			// Events handling
			while (window.pollEvent(event))
			{
				// Exit
				if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
				// Keyboard
				if (event.type == sf::Event::KeyPressed && vars.game_started)
				{
					// Pause
					if (event.key.code == sf::Keyboard::P)
					{
						if (vars.game_pausable) vars.game_paused = !vars.game_paused;
						vars.game_pausable = false;
					}
					if (!vars.game_paused)
					{
						// Rotate
						if (event.key.code == sf::Keyboard::W && vars.block_rotable)
						{
							vars.block_rotable = false;
							current_block.rotate();
						}
						// Move right
						if (event.key.code == sf::Keyboard::D) current_block.moveRight(vars.block_velocity.x);
						// Move left 
						if (event.key.code == sf::Keyboard::A) current_block.moveLeft(vars.block_velocity.x);
						// Speed up
						if (event.key.code == sf::Keyboard::S) block_y_velocity = vars.block_y_speed_up_velocity + vars.block_y_added_speed_up_velocity * level;
					}
				}
				if (event.type == sf::Event::KeyReleased && vars.game_started)
				{
					// Pause
					if (event.key.code == sf::Keyboard::P) vars.game_pausable = true;
					if (!vars.game_paused)
					{
						// Rotate
						if (event.key.code == sf::Keyboard::W) vars.block_rotable = true;
						// Move right
						if (event.key.code == sf::Keyboard::D) current_block.dx_right = vars.block_size;
						// Move left
						if (event.key.code == sf::Keyboard::A) current_block.dx_left = vars.block_size;
						// Slow down
						if (event.key.code == sf::Keyboard::S) block_y_velocity = vars.block_velocity.y + vars.block_y_added_velocity * level;
					}
				}
				// Mouse
				if (!button.inactive)
				{
					if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left && button.isMouseOver()) vars.button_pressed = true;
					if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left && vars.button_pressed)
					{
						vars.button_pressed = false;
						if (button.isMouseOver())
						{
							grid.resetBlocks();
							grid.resetMap();
							vars.resetBoolVars();
							score = 0;
							level = 0;
							block_y_velocity = vars.block_velocity.y + vars.block_y_added_velocity * level;
							score_text.setText("Score:\n" + std::to_string(score));
							level_text.setText("Level:\n" + std::to_string(level + 1));
							current_block.setNew();
							previous_block.setNew(true);
							vars.game_started = true;
						}
					}
				}
			}

			// Button events
			if (!button.inactive)
			{
				if (button.isMouseOver())
				{
					if (vars.button_pressed) button.onClick();
					else button.onHover();
				}
				else button.onDefault();
			}

			/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
			if (vars.game_started)
			{
				first_game = false;
				button.onInactive();

				if (vars.game_paused)
				{
					music.pause();
					info_text.setText("Game paused");
				}
				else
				{
					music.play();
					info_text.setText("");

					if (!current_block.moveDown(clock.delta_time * block_y_velocity))
					{
						setBlock(current_block, grid);
						if (!grid.isGameOver())
						{
							current_block.copy(previous_block);
							previous_block.setNew(true);

							// Handle full lines
							std::vector<int> full_lines = grid.getFullLines();
							if (!full_lines.empty())
							{
								int full_lines_nmb = (int)full_lines.size();
								score += full_lines_nmb * 100;
								switch (full_lines_nmb)
								{
								case 2: score += 50; break;
								case 3: score += 150; break;
								case 4: score += 250; break;
								default: break;
								}
								for (auto line : full_lines)
									grid.moveBlocksDown(line);
							}

							score += 10;
							level = score / 1000;
							score_text.setText("Score:\n" + std::to_string(score));
							level_text.setText("Level:\n" + std::to_string(level + 1));
						}
						else
						{
							vars.game_started = false;
							button.onDefault();
						}
					}
				}
			}
			else if (!first_game)
			{
				music.stop();
				info_text.setText("Game over");
			}

			/*------------------------------------------------------------------------------------------------------------------------------------------------------------*/
			// Drawing
			window.clear(sf::Color(158, 168, 161));
			window.draw(next_piece_frame);
			window.draw(game_frame);
			window.draw(button);
			window.draw(grid);
			if (vars.game_started)
			{
				window.draw(previous_block);
				window.draw(current_block);
			}
			window.draw(next_piece_text);
			window.draw(info_text);
			window.draw(score_text);
			window.draw(level_text);
			window.display();

			// Fps counter
			std::cout << getFps(clock) << "\r";
		}
	}

	/*
	_CrtMemCheckpoint(&sNew); //take a snapshot 
	if (_CrtMemDifference(&sDiff, &sOld, &sNew)) // if there is a difference
	{
		_CrtDumpMemoryLeaks();
		_CrtMemDumpStatistics(&sDiff);
	}
	*/

	return 0;
}