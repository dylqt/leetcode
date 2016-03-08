#include <vector>
#include <stack>
#include <iostream>


using namespace std;

class Solution {
public:
	int calculate(string s) {
		
		// change s to nibolan
		int index = 0;
		vector<int> nibolan;
		stack<int> sign;
		stack<int> deal;
		int outi = 0;
		while (s[index] != '\0') {
			// pass the first space
			while (s[index] == ' ') {
				index++;
			}
			if (s[index] == '\0')
				break;
			outi = stoi(s, index);
			if (outi >= 0) {
				nibolan.push_back(outi);
			}
			else {
				if (outi + (int)('(') == 0 || outi + (int)('+') == 0 ||
					outi + (int)('-') == 0)
					sign.push(outi);
				if (outi + (int)(')') == 0) {
					while (sign.top() + (int)('(') != 0) {
						nibolan.push_back(sign.top());
						sign.pop();
					}
					sign.pop();
				}
			}
		}
		for (int i = 0; i < sign.size();) {
			nibolan.push_back(sign.top());
			sign.pop();
		}

		for (int i = 0; i < nibolan.size(); i++) {
			if (nibolan[i] >= 0)
				deal.push(nibolan[i]);
			else {
				int numr = deal.top();
				deal.pop();
				int numl = deal.top();
				deal.pop();
				int numGet = 0;
				if (-nibolan[i] == (int)('+'))
					numGet = numl + numr;
				if (-nibolan[i] == (int)('-'))
					numGet = numl - numr;
				deal.push(numGet);
			}
		}
		return deal.top();
	}
private:
	int stoi(string s, int &i) {
		
		int output = 0;
		// start from num
		if (s[i] >= '0' && s[i] <= '9') {
			while (s[i] >= '0' && s[i] <= '9') {
				output = output * 10 + s[i] - '0';
				i++;
			}
			return output;
		}
		else {
			output = (int)(-s[i]);
			i++;
			return output;
		}
	}

};

int main()
{
	string input = " 5 + (10 + 9) - 4";
	Solution A;
	int result = 0;
	result = A.calculate(input);
}