#include <ncurses.h>
#include <unistd.h>
#include <chrono>
#include <thread>

#include "ft_game.hpp"
#include "ft_screen.hpp"

const int FPS = 30;

void handleInput(int ch);
void render();

int main()
{
    shmup::Core core;
    shmup::Game game(core);
    shmup::Screen screen(core);

    int ch;
    bool running = true;
    auto lastTime = std::chrono::high_resolution_clock::now();
    auto frameDuration = std::chrono::milliseconds(1000 / FPS);

    // イベントループ
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
        game.draw();

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

    return 0;
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

void render()
{
    // Clear the screen
    clear();

    // Render game state
    mvprintw(0, 0, "Press 'q' to quit");

    // Refresh the screen to show changes
    refresh();
}
