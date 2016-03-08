#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max = 0;
		int marked[128] = { 0 };
		int left = 0;
		int len = 0;
		for (int i = 0; i < s.size(); i++) {
			if (marked[s[i]] == 0) {
				marked[s[i]] = i + 1;
			}
			else {
				left = marked[s[i]] > left ? marked[s[i]] : left;
				marked[s[i]] = i +1;
			}
			len = i - left + 1;
			if (len > max)
				max = len;
		}
		return max;
	
	}
};

int main()
{
	string input = "eee";
	Solution A;
	int a = A.lengthOfLongestSubstring(input);
}