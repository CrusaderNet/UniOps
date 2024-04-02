#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Deque
{
    private:
        vector<T> data;

    public:
        int size()
        {
            return data.size();
        }

        bool empty()
        {
            return data.empty();
        }

        void push_front(T element)
        {
            data.insert(data.begin(), element);
        }

        void push_back(T element)
        {
            data.push_back(element);
        }

        T pop_front()
        {
            T element = data.front();
            data.erase(data.begin());
            return element;
        }

        T pop_back()
        {
            T element = data.end();
            data.pop_back();
            return element;
        }

        T front()
        {
            return data.front();
        }

        T back()
        {
            return data.end();
        }
};