#include "ft_core.hpp"

namespace shmup
{
	Core::Core()
	{
	}

	Logger &Core::log(const std::string &file, const int line)
	{
		return logger << "[" << file << ":" << line << "] ";
	}
} // namespace shmpup
