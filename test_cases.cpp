#include <string>
#include "test_cases.h"

using namespace std;

extern int find_offending_brackets(const string&  line);

TEST(Nesting_Brackets, HandleEmptyLine) {
	ASSERT_EQ(-1, find_offending_brackets(""));
}