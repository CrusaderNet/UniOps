//THIS CODE SOURCED FROM CHATGPT. DO NOT USE THIS CODE FOR ACADEMIC PURPOSES. THIS IS ONLY FOR REFERENCE PURPOSES.

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Custom hash function that causes collisions
int customHash(const string& key) {
    // This hash function simply takes the length of the string as the hash value
    return key.length();
}

int main() {
    // Input values
    vector<string> inputs = {"apple", "banana", "orange", "grape", "watermelon", "kiwi", "pear", "strawberry"};

    // Find collisions
    vector<vector<string>> collisions(20); // Assuming the range of hash values is 20
    for (const string& input : inputs) {
        int hashValue = customHash(input);
        collisions[hashValue].push_back(input);
    }

    // Output collisions
    cout << "Hash Collisions:\n";
    for (int i = 0; i < collisions.size(); ++i) {
        if (collisions[i].size() > 1) {
            cout << "Hash value " << i << " maps to: ";
            for (const string& input : collisions[i]) {
                cout << input << " ";
            }
            cout << endl;
        }
    }

    return 0;
}