#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PriorityQueue
{
    private:
        vector<int> data;
    public:
        int size()
        {
            return data.size();
        }
        bool empty()
        {
            return data.empty();
        }
        void push(int element)
        {
            data.push_back(element);
            sort(data.begin(), data.end());
        }
        int pop()
        {
            int element = data.front();
            data.erase(data.begin());
            return element;
        }
        int top()
        {
            return data.front();
        }
};

int main()
{
    PriorityQueue pq;
    pq.push(30);
    pq.push(5);
    pq.push(12);
    pq.push(1);

    cout << "Size: " << pq.size() << endl;

    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    
    return 0;
}