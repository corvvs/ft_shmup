#include "ft_scene_stage.hpp"
#include "ft_character.hpp"

namespace shmup
{
	SceneStage::SceneStage(Core &core) : core(core)
	{
		characters.push_back(Character(core, CharacterType::PLAYER, Vec(10, 10, 0)));
		idx_player = 0;
	}

} // namespace shmpup