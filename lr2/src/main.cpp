#include <iostream>
#include "Time.h"
#include <thread>

using namespace std;

int main()
{
	cout << "try1" << endl;
	try {
		Time time("12:12");
	} catch (const invalid_argument &e) {
		cout << "Caught " << e.what() << " exception!" << endl;
	}

	cout << "try2" << endl;
	try {
		Time time("25:12:");
	} catch (const invalid_argument &e) {
		cout << "Caught " << e.what() << " exception!" << endl;
	}

	cout << "try3" << endl;
	try {
		Time time("25:12:99");
	} catch (const invalid_argument &e) {
		cout << "Caught " << e.what() << " exception!" << endl;
	}

	cout << "try4" << endl;
	try {
		Time time1("23:12:59");
		Time time2("12:44:28");
		cout << "secs from time2 to time1 " << time2.secsToTime(time1) << endl;
	} catch (const invalid_argument &e) {
		cout << "Caught " << e.what() << " exception!" << endl;
	}

	{
		Time start(chrono::time_point_cast<chrono::seconds>(chrono::system_clock::now()).time_since_epoch());
		this_thread::sleep_for(chrono::seconds(1));
		Time end(chrono::time_point_cast<chrono::seconds>(chrono::system_clock::now()).time_since_epoch());

		cout << "time elapsed " << start.secsToTime(end) << endl;

		cout << "start to seconds " << start.toSecs() << endl;
		cout << "start to minutes " << start.toMins() << endl;
		cout << "start to hours " << start.toHours() << endl;
	}

	return 0;
}