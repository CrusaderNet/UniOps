#include <iostream>
#include <set>
#include <vector>

using namespace std;

// Driver code
int main()
{
    
    struct uniWord
    {
        string wordName;
        int count;
    };

    set<string> unigrams;
    set<string>::iterator it;

    vector<uniWord> wordVec;
    bool isPresent = false;

    string str = "c-a-t cat? CAT in the hat bike";

    //Create Uniword Vector
    string tempWord = "";
    for (auto x : str) 
    {
        if (x == ' ')
        {
            
            for(string::iterator i = tempWord.begin(); i != tempWord.end(); i++)
            {
                if(!isalpha(tempWord.at(i - tempWord.begin())))
                {
                    tempWord.erase(i);
                    i--;
                }
            }

                for(int i = 0; i < wordVec.size(); i++){
                    if(tempWord == wordVec[i].wordName){
                        wordVec[i].count++;
                        isPresent = true;
                    }
                }
                if(isPresent = false){
                    uniWord temp;
                    temp.count = 1;
                    temp.wordName = tempWord;
                }

                cout << tempWord << endl;
                tempWord = "";
        }
        else {
            x = tolower(x);
            tempWord = tempWord + x;
        }
    }
    //last word addition wordVec
    for(string::iterator i = tempWord.begin(); i != tempWord.end(); i++)
            {
                if(!isalpha(tempWord.at(i - tempWord.begin())))
                {
                    tempWord.erase(i);
                    i--;
                }
            }

                for(int i = 0; i < wordVec.size(); i++){
                    if(tempWord == wordVec[i].wordName){
                        wordVec[i].count++;
                        isPresent = true;
                    }
                }
                if(isPresent = false){
                    uniWord temp;
                    temp.count = 1;
                    temp.wordName = tempWord;
                }

                cout << tempWord << endl;
                tempWord = "";

    //Parse and take in words to a set
    string word = "";
    for (auto x : str) 
    {
        if (x == ' ')
        {
            
            for(string::iterator i = word.begin(); i != word.end(); i++)
            {
                if(!isalpha(word.at(i - word.begin())))
                {
                    word.erase(i);
                    i--;
                }
            }

                unigrams.insert(word);
                cout << word << endl;
                word = "";
        }
        else {
            x = tolower(x);
            word = word + x;
        }
    }
    //last word addition
    for(string::iterator i = word.begin(); i != word.end(); i++)
            {
                if(!isalpha(word.at(i - word.begin())))
                {
                    word.erase(i);
                    i--;
                }
            }
                unigrams.insert(word);
                cout << word << endl;
                word = "";

    cout << "Total Unigrams: " << unigrams.size() << endl;

    for (it = unigrams.begin(); it != unigrams.end(); it++){
        for(int i = 0; i < wordVec.size(); i++){
            if(wordVec[i].wordName == (*it)){
                cout << "Word: " << *it << "  Count: " << wordVec[i].count << endl;
                break;
            }
        }
    }

    return 0;
}