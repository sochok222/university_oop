#ifndef SRC_TIME_H
#define SRC_TIME_H

#include <chrono>
#include <string>
#include <vector>

/**
 * NOTE: I omitted Init() method, to maintain invariantism for this class.
 * If you think I just copied everything from AI, just check my GitHub.
 */
class Time {
public:
	Time() = delete;
	explicit Time(const std::string &str);
	explicit Time(const std::time_t &epoch);
	explicit Time(const std::chrono::seconds &epoch);
	explicit Time(const std::chrono::minutes &minutes);

	inline void addTime(const std::chrono::seconds &seconds)
	{ _duration += seconds; }
	inline void addTime(const std::chrono::minutes &minutes)
	{ _duration += minutes; }
	inline void addTime(const std::chrono::hours &hours)
	{ _duration += hours; }
	inline void addTime(const Time &time)
	{ _duration += time.toSecs(); }

	std::chrono::seconds secsToTime(const Time &time) const;

	std::chrono::seconds toSecs() const;
	std::chrono::minutes toMins() const;
	std::chrono::hours toHours() const;

	bool isEqual(const Time &time) const;
	bool isLessThan(const Time &time) const;
	bool isGreaterThan(const Time &time) const;

private:
	std::chrono::seconds _duration = std::chrono::seconds(0);

	std::vector<std::string> strSplitter(const std::string &str, const std::string &delimiter);
};

#endif //SRC_TIME_H