#include "ft_logger.hpp"

namespace shmup
{
	Logger::Logger()
	{
		ofs.open(DefaultLogFileName, std::ios::out | std::ios::trunc);
		ofs << std::endl
			<< std::endl;
	}

	Logger::~Logger()
	{
		ofs.close();
	}

	Logger &Logger::operator<<(std::ostream &(*manip)(std::ostream &))
	{
		ofs << manip;
		return *this;
	}

	Logger &operator<<(Logger &me, std::ostream &(*manip)(std::ostream &))
	{
		me.ofs << manip;
		return me;
	}

} // namespace shmup
