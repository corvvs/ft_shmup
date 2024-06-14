#ifndef FT_LOGGER_HPP
#define FT_LOGGER_HPP

#include <string>
#include <fstream>

const std::string DefaultLogFileName = "log.txt";

namespace shmup
{
	class Logger
	{
	public:
		std::ofstream ofs;

		Logger();
		~Logger();

		template <typename T>
		Logger &operator<<(const T &value)
		{
			ofs << value;
			return *this;
		}

		Logger &operator<<(std::ostream &(*manip)(std::ostream &));
	};

	template <typename T>
	Logger &operator<<(Logger &me, const T &value)
	{
		me.ofs << value;
		return me;
	}

	Logger &operator<<(Logger &me, std::ostream &(*manip)(std::ostream &));
} // namespace shmup

#endif
