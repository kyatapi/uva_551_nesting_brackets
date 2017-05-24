#include <string>
#include <queue>

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

unsigned int find_offending_brackets(const string&  line) {
	unsigned int count = 0;
	queue<unsigned int> unclosed_brackets; 
	for(size_t i = 0; i < line.length();) {
		++count;
		int bracket_index = match_close_brackets(line, i);
		if(bracket_index >= 0) {
			i += supported_brackets[bracket_index].second.length();
			if (unclosed_brackets.empty() || unclosed_brackets.back() != bracket_index) {
				break;
			}
			else {
				unclosed_brackets.pop();
			}
		}
	}
	return count;
}

int main(int argc, char **argv) {
	run_test(argc, argv);

	return 0;
}