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

		// ステージの初期処理
		void init_stage();

		// プレイヤーが弾を発射する
		void fire_bullet();

		// 弾との当たり判定
		bool is_bullet_collided(const Character &ch);
	
		// 同じ位置か判定
		bool is_same_position(const Vec &v1, const Vec &v2);

	public:
		SceneStage(Core &core);

		// ステージに入力を与える.
		// キーイベント発生時に呼び出される.
		void input(KeyCode);

		const std::map<size_t, Character> &get_characters() const;

		Character &get_player();

		// 指定した番号のキャラクターを返す
		// キャラクターが存在しない番号を入力した時の動作は不定
		Character &get_character(size_t idx);

		// ステージを時間経過させる
		// elapsed_time: 前回の更新からの経過時間(ms)
		void update(std::uint64_t elapsed_time);
	};
}

#endif
