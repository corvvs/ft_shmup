#include "ft_scene_stage.hpp"
#include "ft_character.hpp"

namespace shmup
{
	SceneStage::SceneStage(Core &core) : core(core)
	{
		id_player_1 = add_character(Character(core, CharacterType::PLAYER, Vec(10, 10, 0)));
	}

	size_t SceneStage::add_character(const Character &ch)
	{
		size_t idx = char_idx++;
		characters.insert(std::make_pair(idx, ch));
		FTLOG << "Character added: " << ch.get_letter() << " at " << ch.position.x << ", " << ch.position.y << std::endl;
		return idx;
	}

	Character &SceneStage::get_player()
	{
		return characters.find(id_player_1)->second;
	};

	Character &SceneStage::get_character(size_t idx)
	{
		return characters.find(idx)->second;
	}

	void SceneStage::input(KeyCode key)
	{

		Character &player = get_player();

		switch (key)
		{
			// 移動
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
			// 射撃
		case KeyCode::SPACE:
			fire_bullet();
			break;
		default:
			break;
		}

		FTLOG << "Player moved to " << player.position.x << ", " << player.position.y << std::endl;
	}

	void SceneStage::fire_bullet()
	{
		Character &player = get_player();
		Character bullet(core, CharacterType::BULLET, player.position);
		size_t idx = add_character(bullet);
		get_character(idx).velocity.y = -1 / 60.0;
	}

	const std::map<size_t, Character> &SceneStage::get_characters() const
	{
		return characters;
	}

	void SceneStage::update(std::uint64_t elapsed_time)
	{
		for (auto &pair : characters)
		{
			pair.second.update(elapsed_time);
		}
	}

} // namespace shmpup