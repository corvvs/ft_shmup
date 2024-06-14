#ifndef FT_SCENE_STAGE_HPP
#define FT_SCENE_STAGE_HPP

#include <vector>
#include "ft_character.hpp"
#include "ft_core.hpp"

namespace shmup
{
	class SceneStage
	{
		Core &core;
		std::vector<Character> characters;
		unsigned int idx_player;

	public:
		SceneStage(Core &core);

		// ステージに入力を与える.
		// キーイベント発生時に呼び出される.
		void input(KeyCode);

		const std::vector<Character> &get_characters() const;
	};
}

#endif