#ifndef SRC_TIME_H
#define SRC_TIME_H

#include <chrono>
#include <string>
#include <vector>

/**
 * NOTE: I omitted Init() method, to maintain invariantism for this class.
 * If you think I just copied everything from AI, just check my GitHub.
 */
class MyTime {
public:
	MyTime() = delete;
	explicit MyTime(const std::string &str);
	explicit MyTime(const std::time_t &epoch);
	explicit MyTime(const std::chrono::seconds &epoch);
	explicit MyTime(const std::chrono::minutes &minutes);

	inline void addTime(const std::chrono::seconds &seconds)
	{ _duration += seconds; }
	inline void addTime(const std::chrono::minutes &minutes)
	{ _duration += minutes; }
	inline void addTime(const std::chrono::hours &hours)
	{ _duration += hours; }
	inline void addTime(const MyTime &time)
	{ _duration += time.toSecs(); }

	std::chrono::seconds secsToTime(const MyTime &time) const;

	std::chrono::seconds toSecs() const;
	std::chrono::minutes toMins() const;
	std::chrono::hours toHours() const;

	bool isEqual(const MyTime &time) const;
	bool isLessThan(const MyTime &time) const;
	bool isGreaterThan(const MyTime &time) const;

private:
	std::chrono::seconds _duration = std::chrono::seconds(0);

	std::vector<std::string> strSplitter(const std::string &str, const std::string &delimiter);
};

#endif //SRC_TIME_H