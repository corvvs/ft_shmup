#ifndef FT_ENUM_HPP
#define FT_ENUM_HPP

namespace shmup
{

	// キャラクター
	enum CharacterType
	{
		PLAYER,
		BULLET,

		ENEMY_0,
	};

	// 色
	enum Color
	{
		BLACK,
		RED,
		GREEN,
		YELLOW,
		BLUE,
		MAGENTA,
		CYAN,
		WHITE,
	};

	// キー入力
	enum KeyCode
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
		SPACE,
		ENTER,
		OTHER,
	};
} // namespace shmup

#endif