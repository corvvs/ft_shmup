#ifndef FT_GAME_HPP
#define FT_GAME_HPP

#include "ft_enum.hpp"
#include "ft_core.hpp"
#include "ft_scene_stage.hpp"

namespace shmup
{
	class Game
	{

	private:
		Core &core;

		SceneStage stage;

	public:
		// ゲームを作成する
		Game(Core &core);

		~Game();

		// [インターフェース]

		// ゲームの状態を進め, スクリーンに描画する.
		// タイマーにより起動される.
		void draw();

		// ゲームに入力を与える.
		// キーイベント発生時に呼び出される.
		void input(KeyCode);

		// 現在のステージへの参照を返す
		SceneStage &current_stage();
	};

} // namespace shmpup

#endif