#include "ft_scene_stage.hpp"
#include "ft_character.hpp"

namespace shmup
{
	SceneStage::SceneStage(Core &core) : core(core)
	{
		// プレイヤーの配置
		id_player_1 = add_character(Character(core, CharacterType::PLAYER, Vec(ScreenWidth / 2.0, ScreenHeight * 0.8, 0)));

		// ステージ初期処理
		init_stage();
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

	const std::map<size_t, Character> &SceneStage::get_characters() const
	{
		return characters;
	}

	void SceneStage::input(KeyCode key)
	{

		Character &player = get_player();

		switch (key)
		{
			// 移動
		case KeyCode::UP:
			if (player.position.y > 0)
			{
				player.position.y--;
			}
			break;
		case KeyCode::DOWN:
			if (player.position.y < ScreenHeight - 1)
			{
				player.position.y++;
			}
			break;
		case KeyCode::LEFT:
			if (player.position.x > 0)
			{
				player.position.x--;
			}
			break;
		case KeyCode::RIGHT:
			if (player.position.x < ScreenWidth - 1)
			{
				player.position.x++;
			}
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

	void SceneStage::init_stage()
	{

		// 敵を適当に配置する
		for (int i = 0; i < 10; i++)
		{
			Character enemy(core, CharacterType::ENEMY_0, Vec(20 + i * 5, 5, 0));
			add_character(enemy);
		}
	}

	void SceneStage::fire_bullet()
	{
		// BULLET をプレイヤーの位置に生成したあと, 速度を与える
		double vy = 2.6;
		double w3way = 0.6;
		Character &player = get_player();
		{
			Character bullet(core, CharacterType::BULLET, player.position);
			size_t idx = add_character(bullet);
			get_character(idx).velocity.y = -vy / 60.0;
		}
		{
			Character bullet(core, CharacterType::BULLET, player.position);
			size_t idx = add_character(bullet);
			get_character(idx).velocity.x = -w3way / 60.0;
			get_character(idx).velocity.y = -vy / 60.0;
		}
		{
			Character bullet(core, CharacterType::BULLET, player.position);
			size_t idx = add_character(bullet);
			get_character(idx).velocity.x = +w3way / 60.0;
			get_character(idx).velocity.y = -vy / 60.0;
		}
	}

	void SceneStage::update(std::uint64_t elapsed_time)
	{
		// rbegin -> rend で逆にループしないと erase で死にます
		for (auto it = characters.rbegin(); it != characters.rend(); ++it)
		{
			Character &ch = it->second;
			ch.update(elapsed_time);

			// 画面外に出た弾を削除
			switch (ch.get_type())
			{
			case CharacterType::BULLET:
				if (ch.position.y < 0 || ch.position.y >= ScreenHeight || ch.position.x < 0 || ch.position.x >= ScreenWidth)
				{
					FTLOG << "Bullet removed: " << ch.position.x << ", " << ch.position.y << std::endl;
					characters.erase(it->first);
				}
				break;
			default:
				break;
			}
		}

		FTLOG << "Characters: " << characters.size() << std::endl;
	}

} // namespace shmpup