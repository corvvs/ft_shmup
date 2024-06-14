#include <ncurses.h>
#include <unistd.h>
#include <chrono>
#include <thread>

#include "ft_game.hpp"

const int FPS = 30;

void initialize();
void cleanup();
void handleInput(int ch);
void update();
void render();

int main()
{
    initialize();

    int ch;
    bool running = true;
    auto lastTime = std::chrono::high_resolution_clock::now();
    auto frameDuration = std::chrono::milliseconds(1000 / FPS);

    while (running)
    {
        // Handle input
        ch = getch();
        if (ch != ERR)
        {
            if (ch == 'q')
            { // 'q' to quit
                running = false;
            }
            else
            {
                handleInput(ch);
            }
        }

        // Update game state
        update();

        // Render the screen
        render();

        // Cap the frame rate
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = currentTime - lastTime;
        if (elapsed < frameDuration)
        {
            std::this_thread::sleep_for(frameDuration - elapsed);
        }
        lastTime = currentTime;
    }

    cleanup();
    return 0;
}

void initialize()
{
    initscr();             // Start curses mode
    cbreak();              // Line buffering disabled
    noecho();              // Don't echo while we do getch
    nodelay(stdscr, TRUE); // Non-blocking input
    keypad(stdscr, TRUE);  // Enable F1, F2, arrow keys, etc.
    curs_set(0);           // Hide the cursor
    timeout(0);            // Non-blocking input
}

void cleanup()
{
    endwin(); // End curses mode
}

void handleInput(int ch)
{
    // Handle input
    switch (ch)
    {
    case KEY_UP:
        // Handle up arrow key
        break;
    case KEY_DOWN:
        // Handle down arrow key
        break;
    case KEY_LEFT:
        // Handle left arrow key
        break;
    case KEY_RIGHT:
        // Handle right arrow key
        break;
    default:
        break;
    }
}

void update()
{
    // Update game state
}

void render()
{
    // Clear the screen
    clear();

    // Render game state
    mvprintw(0, 0, "Press 'q' to quit");

    // Refresh the screen to show changes
    refresh();
}
