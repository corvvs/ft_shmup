#include "ft_game.hpp"

namespace shmup
{
	Game::Game(Core &core) : core(core), stage(core)
	{
		core.log() << std::endl
				   << std::endl
				   << "==== Session Started ====" << std::endl;
	}

	Game::~Game()
	{
		core.log() << "==== Session Finished ====" << std::endl;
	}

	void Game::draw()
	{
	}

	void Game::input(KeyCode key)
	{
		current_stage().input(key);
	}

	SceneStage &Game::current_stage()
	{
		return stage;
	}
} // namespace shmpup
