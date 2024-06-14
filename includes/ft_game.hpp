#ifndef FT_GAME_H
#define FT_GAME_H

#include "ft_enum.hpp"
#include "ft_core.hpp"

namespace shmup
{
	class Game
	{

	private:
		Core core;

	public:
		// ゲームを作成する
		Game();

		// [インターフェース]

		// ゲームの状態をスクリーンに描画する
		void draw();

		// ゲームに入力を与える
		void input(keycode);
	};

} // namespace shmpup

#endif