#include "ft_screen.hpp"
#include <ncurses.h>
#include <string>

const std::string frame_horizon = std::string(ScreenWidth - 2, '-');

namespace shmup
{
	Screen::Screen(Core &core) : core(core)
	{
		initscr();			   // Start curses mode
		cbreak();			   // Line buffering disabled
		noecho();			   // Don't echo while we do getch
		nodelay(stdscr, TRUE); // Non-blocking input
		keypad(stdscr, TRUE);  // Enable F1, F2, arrow keys, etc.
		curs_set(0);		   // Hide the cursor
		timeout(0);			   // Non-blocking input
	}

	Screen::~Screen()
	{
		endwin(); // End curses mode
	}

	void Screen::render(const SceneStage &stage)
	{
		// Clear the screen
		clear();

		// Render game state
		mvprintw(1, 1, "Press 'q' to quit");

		const auto &characters = stage.get_characters();

		for (auto it = characters.begin(); it != characters.end(); ++it)
		{
			const auto &character = it->second;
			mvaddch(character.position.y + 0.5, character.position.x + 0.5, character.get_letter());
		}

		// 画面フレームの描画
		mvaddch(0, 0, '+');
		mvaddch(0, ScreenWidth - 1, '+');
		mvprintw(0, 1, frame_horizon.c_str());

		mvaddch(ScreenHeight - 1, 0, '+');
		mvaddch(ScreenHeight - 1, ScreenWidth - 1, '+');
		mvprintw(ScreenHeight - 1, 1, frame_horizon.c_str());

		for (int i = 1; i < ScreenHeight - 1; i++)
		{
			mvaddch(i, 0, '|');
			mvaddch(i, ScreenWidth - 1, '|');
		}

		// Refresh the screen to show changes
		refresh();
	}
} // namespace shmpup
