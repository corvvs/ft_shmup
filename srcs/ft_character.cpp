#include "ft_character.hpp"

namespace shmup
{
	Character::Character(Core &core, CharacterType type, const Vec &initial_position) : core(core), position(initial_position)
	{
		this->type = type;
		switch (type)
		{
		case CharacterType::PLAYER:
			letter = '@';
			color = Color::WHITE;
			break;
		case CharacterType::BULLET:
			letter = '|';
			color = Color::YELLOW;
			break;
		case CharacterType::ENEMY_0:
			letter = '*';
			color = Color::RED;
			break;
		default:
			throw "Invalid character type";
		}
		core.log() << "Character created: " << letter << " at " << position.x << ", " << position.y << std::endl;
	}

} // namespace shmpup