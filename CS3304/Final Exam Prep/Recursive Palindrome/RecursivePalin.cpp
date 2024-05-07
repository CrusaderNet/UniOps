#include <iostream>
#include <string>

using namespace std;

bool isPalidromeDetector(const string& str, int start, int finish)
{
    if (start >= finish)
    {
        return true;
    }
    
    if (str[start] != str[finish])
    {
        return false;
    }
    
    return isPalidromeDetector(str, start + 1, finish - 1);
}

bool isPalidrome(const string& str)
{
    return isPalidromeDetector(str, 0, str.length() - 1); 
}

int main()
{
    string words[] = {"", "mom", "abba", "moxm", "abc", "ab", "kayak", "k", "moavom", "Dad", "DAD"};
    
    for(const string& word : words)
    {
        if(isPalidrome(word))
        {
            cout << "\"" << word << "\" is a palidrome.\n";
        }
        
        else
        {
            cout << "\"" << word << "\" is not a palidrome.\n";
        }
    }
    
    return 0;
}