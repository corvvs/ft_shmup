#ifndef FT_CORE_HPP
#define FT_CORE_HPP

#include "ft_logger.hpp"

namespace shmup
{
	class Core
	{
	private:
		Logger logger;

	public:
		Core();

		Logger &log();
	};

} // namespace shmpup

#endif
