#include <iostream>
#include <vector>

class Solution {
public:
    int Add(int num1, int num2)
    {
    	std::vector<char> vec1,vec2,vec3;
    	do{
    		vec1.push_back(0);
    	}while(vec1.size()<(unsigned int)num1);
    	do{
    		vec2.push_back(0);
    	}while(vec2.size()<(unsigned int)num2);
    	vec3.insert(vec3.end(),vec1.begin(),vec1.end());//将vec1压入
        vec3.insert(vec3.end(),vec2.begin(),vec2.end());//继续将vec2压入
        return (int)vec3.size();
    }
};

int main(){
	Solution a;
	std::cout<<a.Add(999,999);   //这种vector的方法内存超了，无法通过
	return 0;
}