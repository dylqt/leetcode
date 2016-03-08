#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<string> findItinerary(vector<pair<string, string>> tickets) {
		vector<string> output;
		map<string, string> tktotk, retktotk;
		for (auto tmp : tickets)
		{
			tktotk[tmp.first] = tmp.second;
			retktotk[tmp.second] = tmp.first;
		}
		output.push_back((*tickets.cbegin()).first);
		for (int i = 1; i < tickets.size(); i++) {
			if
		}
		return output;
	}
};

int main()
{
	vector<pair<string, string>> input = { {"MUC","LHR"}, {"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"} };
	Solution A;
	vector<string> output;
	A.findItinerary(input);
}