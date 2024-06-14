#include "ft_game.hpp"

namespace shmup
{
	Game::Game(Core &core) : core(core), stage(core)
	{
		FTLOG << "==== Game Session Started ====" << std::endl;
	}

	Game::~Game()
	{
		FTLOG << "==== Game Session Finished ====" << std::endl;
	}

	void Game::draw(std::uint64_t elapsed_time)
	{
		current_stage().update(elapsed_time);
	}

	void Game::input(KeyCode key)
	{
		FTLOG << "Key input: " << key << std::endl;
		current_stage().input(key);
	}

	SceneStage &Game::current_stage()
	{
		return stage;
	}
} // namespace shmpup
