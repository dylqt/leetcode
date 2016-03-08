#include <stdlib.h>

#include <memory.h>
#include <string>
using namespace std;
class Solution {
public:
	string removeDuplicateLetters(string s) {
		int ahead[256] = {};
		for (char c : s)
			ahead[c]++;

		string result = " ";
		bool inresult[256] = {};

		for (char c : s) {
			ahead[c]--;
			if (inresult[c])
				continue;
			while (ahead[result.back()] && c < result.back()) {
				inresult[result.back()] = false;
				result.pop_back();
			}
			result += c;
			inresult[c] = true;
		}

		return result;
	}
};

int main()
{
	//char input[] = { 'c', 'd', 'a', 'd', 'c', 'a', 0 };
	char *input = "cdadca";
	Solution A;
	A.removeDuplicateLetters(input);
}