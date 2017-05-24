#include <string>
#include "test_cases.h"

using namespace std;

extern unsigned int find_offending_brackets(const string&);
extern int match_open_brackets(const string&, const size_t);
extern int match_close_brackets(const string&, const size_t);

TEST(FindOffendingBrackets, HandleEmptyLine) {
	ASSERT_EQ(0, find_offending_brackets(""));
}

//MatchOpenBrackets
TEST(MatchOpenBrackets, HandleEmptyLine) {
	ASSERT_EQ(-1, match_open_brackets("", 0));
}

TEST(MatchOpenBrackets, HandleNormalBrackets) {
	ASSERT_EQ(1, match_open_brackets("(", 0));
	ASSERT_EQ(0, match_open_brackets("(*", 0));
}

TEST(MatchOpenBrackets, HandleNoBrackets) {
	ASSERT_EQ(-1, match_open_brackets("abc", 0));
}

//MatchCloseBrackets
TEST(MatchCloseBrackets, HandleEmptyLine) {
	ASSERT_EQ(-1, match_close_brackets("", 0));
}

TEST(MatchCloseBrackets, HandleNormalBrackets) {
	ASSERT_EQ(1, match_close_brackets(")", 0));
	ASSERT_EQ(0, match_close_brackets("*)", 0));
}

TEST(MatchCloseBrackets, HandleNoBrackets) {
	ASSERT_EQ(-1, match_close_brackets("abc", 0));
}