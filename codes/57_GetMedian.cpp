#include<iostream>
#include<algorithm>
#include<vector>

using std::vector;
class Solution {
public:
    void Insert(int num) { //direct method, 3ms and 476k, insert O(1)time, median O(nlogn)time
        vec.push_back(num);
    }

    double GetMedian() { 
        std::sort(vec.begin(), vec.end());
        double temp = 0;
        if (vec.size() % 2 != 0) temp = vec[vec.size()/2];
        else {
            temp = (vec[vec.size()/2]+vec[vec.size()/2 - 1])/2.0;
        }
        return temp;
    }
private:
    vector<int> vec;
};


// https://www.nowcoder.com/questionTerminal/9be0172896bd43948f8a32fb954e1be1?f=discussion&toCommentId=6444086

class Solution {
    priority_queue<int, vector<int>, less<int> > p;    //copied other maxHeap-minHeap method, 3ms and 512k
    priority_queue<int, vector<int>, greater<int> > q;
     
public:
    void Insert(int num){
        if(p.empty() || num <= p.top()) p.push(num);
        else q.push(num);
        if(p.size() == q.size() + 2) q.push(p.top()), p.pop();
        if(p.size() + 1 == q.size()) p.push(q.top()), q.pop();
    }
    double GetMedian(){ 
      return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
    }
};

int main() {
    Solution sol;
    sol.Insert(10);
    std::cout<<sol.GetMedian();
    return 0;
}