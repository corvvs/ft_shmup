#include "ft_screen.hpp"
#include <ncurses.h>

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

	void Screen::render()
	{
		// Clear the screen
		clear();

		// Render game state
		mvprintw(0, 0, "Press 'q' to quit");

		// Refresh the screen to show changes
		refresh();
	}

} // namespace shmpup
