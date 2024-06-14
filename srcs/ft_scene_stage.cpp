#include "ft_scene_stage.hpp"
#include "ft_character.hpp"

namespace shmup
{
	SceneStage::SceneStage(Core &core) : core(core)
	{
		characters.push_back(Character(core, CharacterType::PLAYER, Vec(10, 10, 0)));
		idx_player = 0;
	}

	void SceneStage::input(KeyCode key)
	{

		Character &player = characters[idx_player];

		switch (key)
		{
		case KeyCode::UP:
			player.position.y--;
			break;
		case KeyCode::DOWN:
			player.position.y++;
			break;
		case KeyCode::LEFT:
			player.position.x--;
			break;
		case KeyCode::RIGHT:
			player.position.x++;
			break;
		default:
			break;
		}

		core.log() << "Player moved to " << player.position.x << ", " << player.position.y << std::endl;
	}

	const std::vector<Character> &SceneStage::get_characters() const
	{
		return characters;
	}

} // namespace shmpup