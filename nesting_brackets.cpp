#include <string>

#ifndef ONLINE_JUDGE
#include "test_cases.h"
extern void run_test(int argc, char **argv);
#else
inline void run_test(int argc, char **argv) {}
#endif // !ONLINE_JUDGE

using namespace std;

const pair<string, string> supported_brackets[] = {
	pair<string, string>("(*", "*)"),
	pair<string, string>("(", ")"),
	pair<string, string>("[", "]"),
	pair<string, string>("{", "}"),
	pair<string, string>("<", ">")
};

const size_t supported_brackets_count = 5;

unsigned int find_offending_brackets(const string&  line) {
	return 0;
}

int match_open_brackets(const string& line, const size_t start_from) {
	for(size_t i = 0; i < supported_brackets_count; ++i) {
		if (line.compare(start_from, supported_brackets[i].first.length(), supported_brackets[i].first) == 0) {
			return i;
		}
	}
	return -1;
}

int match_close_brackets(const string& line, const size_t start_from) {
	for(size_t i = 0; i < supported_brackets_count; ++i) {
		if (line.compare(start_from, supported_brackets[i].second.length(), supported_brackets[i].second) == 0) {
			return i;
		}
	}
	return -1;
}

int main(int argc, char **argv) {
	run_test(argc, argv);

	return 0;
}