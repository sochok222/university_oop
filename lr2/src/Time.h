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

	void addSeconds(const std::chrono::seconds &seconds);
	void addMinutes(const std::chrono::minutes &minutes);
	void addHours(const std::chrono::hours &hours);

	void addTime(const Time &time);

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