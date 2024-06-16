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

	public:
		// キャラクターの現在位置
		// 面倒なのでpublicにしてしまう
		Vec position;

		// キャラクターの速度
		// 使わないこともある
		Vec velocity;

		// 削除マーク
		bool marked_for_deletion;

		Character(Core &core, CharacterType type, const Vec &initial_position);

		char get_letter() const;
		CharacterType get_type() const;

		// キャラクターの状態を更新する
		// elapsed_time: 前回の更新からの経過時間(ms)
		void update(std::uint64_t elapsed_time);
	};
}

#endif
