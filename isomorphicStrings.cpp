#include <map>
#include <set>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;
class Solution {
	unordered_map<char, int> chs, cht;
	unordered_set<int> indexs, indext;
public:
	bool isIsomorphic(string s, string t) {
		int i = 0;
		for (auto c : s)
		{
			if (chs.find(c) != chs.cend())
			{
				indexs.insert(chs[c]);
				indexs.insert(i);
			}
			else
				chs.insert({ c, i });
			i++;
		}
		i = 0;
		for (auto c : t)
		{
			if (cht.find(c) != cht.cend())
			{
				indext.insert(cht[c]);
				indext.insert(i);
			}
			else
				cht.insert({ c, i });
			i++;
		}
		auto setPtr = indexs.cbegin();
		if (indext.size() != indexs.size())
		{
			return false;
		}
		while (setPtr != indexs.cend())
		{
			cout << *setPtr << endl;
			if (indext.find(*setPtr) == indext.end())
				return false;
			setPtr++;
		}
		return true;
	}
};

int main()
{
	Solution A;
	A.isIsomorphic("aba", "baa");
}