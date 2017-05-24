#include <string>
#include "test_cases.h"

using namespace std;

extern unsigned int find_offending_brackets(const string&);

TEST(FindOffendingBrackets, HandleEmptyLine) {
	ASSERT_EQ(0, find_offending_brackets(""));
}