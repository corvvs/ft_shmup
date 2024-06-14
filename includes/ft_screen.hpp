#ifndef FT_SCREEN_HPP
#define FT_SCREEN_HPP

#include <chrono>
#include "ft_core.hpp"

namespace shmup
{
	/**
	 * ゲームを描画するスクリーンを表すクラス
	 * ncurses依存は基本的にこのクラス内に押し込まれる
	 */
	class Screen
	{
		Core &core;

	public:
		// 最終描画時刻
		std::chrono::milliseconds last_drawn_time;

		// スクリーンを初期化する
		Screen(Core &core);

		~Screen();

		// スクリーンを描画する
		void render();
	};
}

#endif
