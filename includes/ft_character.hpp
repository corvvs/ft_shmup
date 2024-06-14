#ifndef FT_CHARACTER_HPP
#define FT_CHARACTER_HPP

#include "ft_position.hpp"
#include "ft_enum.hpp"
#include "ft_core.hpp"

namespace shmup
{
	class Character
	{
		Core &core;

		// キャラクター種別
		CharacterType type;

		// キャラクターの文字
		char letter;

		// キャラクターの色
		Color color;

		// キャラクターの現在位置
		Vec position;

	public:
		Character(Core &core, CharacterType type, const Vec &initial_position);
	};
}

#endif
