#include <ncurses.h>
#include <unistd.h>
#include <chrono>
#include <thread>

#include "ft_core.hpp"
#include "ft_game.hpp"
#include "ft_screen.hpp"

const int FPS = 30;

void handleInput(shmup::Core &core, shmup::Game &game, int ch);

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
                handleInput(core, game, ch);
            }
        }

        // Cap the frame rate
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> elapsed = currentTime - lastTime;

        // Update game state
        auto elapsedMs = std::chrono::duration_cast<std::chrono::milliseconds>(elapsed).count();
        game.draw(elapsedMs);

        // Render the screen
        screen.render(game.current_stage());

        if (elapsed < frameDuration)
        {
            std::this_thread::sleep_for(frameDuration - elapsed);
        }
        lastTime = currentTime;
    }

    return 0;
}

void handleInput(shmup::Core &core, shmup::Game &game, int ch)
{
    FTLOG << "Key input: " << ch << std::endl;
    // Handle input
    switch (ch)
    {
    case KEY_UP:
        // Handle up arrow key
        game.input(shmup::KeyCode::UP);
        break;
    case KEY_DOWN:
        // Handle down arrow key
        game.input(shmup::KeyCode::DOWN);
        break;
    case KEY_LEFT:
        // Handle left arrow key
        game.input(shmup::KeyCode::LEFT);
        break;
    case KEY_RIGHT:
        // Handle right arrow key
        game.input(shmup::KeyCode::RIGHT);
        break;
    case ' ':
        // Handle space key
        game.input(shmup::KeyCode::SPACE);
        break;
    default:
        break;
    }
}
