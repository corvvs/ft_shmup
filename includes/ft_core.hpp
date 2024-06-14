#ifndef FT_CORE_HPP
#define FT_CORE_HPP

#include <string>
#include "ft_logger.hpp"

namespace shmup
{
	class Core
	{
	private:
		Logger logger;

	public:
		Core();

		Logger &log(const std::string &file = __FILE__, const int line = __LINE__);
	};

} // namespace shmpup

#endif
