#include "MyTime.h"

using namespace std;

MyTime::MyTime(const string &str)
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

MyTime::MyTime(const std::time_t &epoch)
{ _duration = chrono::seconds(epoch); }

MyTime::MyTime(const std::chrono::seconds &epoch)
{ _duration = epoch; }

MyTime::MyTime(const std::chrono::minutes &minutes)
{ _duration = chrono::duration_cast<chrono::seconds>(minutes); }

std::chrono::seconds MyTime::secsToTime(const MyTime &time) const
{
	if (time.toSecs() <= this->toSecs())
		return std::chrono::seconds(0);
	return time.toSecs() - this->toSecs();
}

std::chrono::seconds MyTime::toSecs() const
{ return _duration; }

std::chrono::minutes MyTime::toMins() const
{ return chrono::duration_cast<chrono::minutes>(_duration); }

std::chrono::hours MyTime::toHours() const
{ return chrono::duration_cast<chrono::hours>(_duration); }

bool MyTime::isEqual(const MyTime &time) const
{ return this->toSecs() == time.toSecs(); }

bool MyTime::isLessThan(const MyTime &time) const
{ return this->toSecs() < time.toSecs(); }

bool MyTime::isGreaterThan(const MyTime &time) const
{ return this->toSecs() > time.toSecs(); }

// Found on stackoverflow. https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
std::vector<std::string> MyTime::strSplitter(const std::string &str, const std::string &delimiter)
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
