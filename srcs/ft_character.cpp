#include "ft_character.hpp"

namespace shmup
{
	Character::Character(Core &core, CharacterType type, const Vec &initial_position) : core(core), position(initial_position), velocity(Vec(0, 0, 0))
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
		FTLOG << "Character created: " << letter << " at " << position.x << ", " << position.y << std::endl;
	}

	char Character::get_letter() const
	{
		return letter;
	}

	void Character::update(std::uint64_t elapsed_time_ms)
	{
		switch (this->type)
		{
		case CharacterType::BULLET:
		{
			position.x += (double)(elapsed_time_ms * velocity.x);
			position.y += (double)(elapsed_time_ms * velocity.y);
			// FTLOG << "Bullet moved to (" << position.x << ", " << position.y << ")" << std::endl;
		}
		break;
		default:
			break;
		}
	}

} // namespace shmpup