#include "Time.h"

using namespace std;

Time::Time(const string &str)
{
	auto tokens = strSplitter(str, ":");
	if (tokens.size() != 3) {
		throw invalid_argument("Unexpected input");
	}

	const auto hours = chrono::hours(stoll(tokens[0]));
	if (hours.count() > 23)
		throw invalid_argument("Unexpected input");

	const auto mins = chrono::minutes(std::stoll(tokens[1]));
	if (mins.count() > 59)
		throw invalid_argument("Unexpected input");

	const auto secs = chrono::seconds(std::stoll(tokens[2]));
	if (secs.count() > 59)
		throw invalid_argument("Unexpected input");

	_duration += hours;
	_duration += mins;
	_duration += secs;
}

Time::Time(const std::time_t &epoch)
{ _duration = chrono::seconds(epoch); }

Time::Time(const std::chrono::seconds &epoch)
{ _duration = epoch; }

Time::Time(const std::chrono::minutes &minutes)
{ _duration = chrono::duration_cast<chrono::seconds>(minutes); }

void Time::addSeconds(const std::chrono::seconds &seconds)
{ _duration += seconds; }

void Time::addMinutes(const std::chrono::minutes &minutes)
{ _duration += minutes; }

void Time::addHours(const std::chrono::hours &hours)
{ _duration += hours; }

void Time::addTime(const Time &time)
{ _duration += time.toSecs(); }

std::chrono::seconds Time::secsToTime(const Time &time) const
{
	if (time.toSecs() <= this->toSecs())
		return std::chrono::seconds(0);
	return time.toSecs() - this->toSecs();
}

std::chrono::seconds Time::toSecs() const
{ return _duration; }

std::chrono::minutes Time::toMins() const
{ return chrono::duration_cast<chrono::minutes>(_duration); }

std::chrono::hours Time::toHours() const
{ return chrono::duration_cast<chrono::hours>(_duration); }

bool Time::isEqual(const Time &time) const
{ return this->toSecs() == time.toSecs(); }

bool Time::isLessThan(const Time &time) const
{ return this->toSecs() < time.toSecs(); }

bool Time::isGreaterThan(const Time &time) const
{ return this->toSecs() > time.toSecs(); }

// Found on stackoverflow. https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> Time::strSplitter(const std::string &str, const std::string &delimiter)
{
	std::vector<std::string> tokens;
	size_t pos = 0;
	std::string token;

	std::string copy = str;
	while ((pos = copy.find(delimiter)) != std::string::npos) {
		token = copy.substr(0, pos);
		tokens.push_back(token);
		copy.erase(0, pos + delimiter.length());
	}
	tokens.push_back(copy);

	return tokens;
}
