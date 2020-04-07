#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int StrToInt(string str) {
        if (str.length() == 0) return 0;
        for (unsigned int i=0;i<str.length();i++) {
        	if ((str[i] >= 48 && str[i] <= 57) || str[i] == 43 || str[i] == 45) continue;
        	else return 0;
        }
        int f = 1;
        if (str[0] == '-') f = -1;
        long long finalNum = 0;
        int power = 0;
        for (int i=(int)str.length()-1;i>=0;i--) {
        	if (str[i] < 48 || str[i] > 57) break;
        	int now = str[i] - 48;
        	int powerNum = 1;
        	for (int i=0;i<power;i++) powerNum *= 10;  
        	finalNum += now*powerNum;
        	power++;
        }
        return f*finalNum;
    }
};

int main() {
	Solution sol;
	string str;
	cin>>str;
	cout<<sol.StrToInt(str)<<endl;
	return 0;
}