#ifndef FT_SCENE_STAGE_HPP
#define FT_SCENE_STAGE_HPP

#include <vector>
#include <map>
#include "ft_character.hpp"
#include "ft_core.hpp"

namespace shmup
{
	class SceneStage
	{
		Core &core;
		std::map<size_t, Character> characters;
		size_t id_player_1;
		size_t char_idx;

		size_t add_character(const Character &ch);
		void fire_bullet();

	public:
		SceneStage(Core &core);

		// ステージに入力を与える.
		// キーイベント発生時に呼び出される.
		void input(KeyCode);

		const std::map<size_t, Character> &get_characters() const;

		Character &get_player();
		Character &get_character(size_t idx);

		void update(std::uint64_t elapsed_time);
	};
}

#endif
