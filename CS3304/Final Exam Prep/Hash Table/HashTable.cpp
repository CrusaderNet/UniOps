//THIS CODE WAS SOURCED FROM CHATGPT. DO NOT USE THIS CODE FOR ACADEMIC PURPOSES. THIS IS ONLY FOR REFERENCE PURPOSES.

#include <iostream>
#include <vector>
#include <list>
#include <string>

using namespace std;

// Hash function to compute the index from the key
int hashFunction(const string& key, int tableSize) {
    int hash = 0;
    for (char c : key) {
        hash += c;
    }
    return hash % tableSize;
}

// Hash table implementation with chaining to handle collisions
class HashTable {
private:
    int size; // Size of the hash table
    vector<list<pair<string, int>>> table; // Vector of lists to store key-value pairs

public:
    // Constructor to initialize the hash table with a given size
    HashTable(int tableSize) : size(tableSize), table(tableSize) {}

    // Function to insert a key-value pair into the hash table
    void insert(const string& key, int value) {
        int index = hashFunction(key, size);
        table[index].push_back(make_pair(key, value));
    }

    // Function to retrieve the value associated with a given key
    // Returns -1 if the key is not found
    int get(const string& key) {
        int index = hashFunction(key, size);
        for (const auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second; // Return the value if the key is found
            }
        }
        return -1; // Key not found
    }
};

int main() {
    HashTable hashTable(10); // Create a hash table with size 10

    // Insert some key-value pairs
    hashTable.insert("apple", 10);
    hashTable.insert("banana", 20);
    hashTable.insert("orange", 30);

    // Retrieve values using keys
    cout << "Value for key 'apple': " << hashTable.get("apple") << endl;
    cout << "Value for key 'banana': " << hashTable.get("banana") << endl;
    cout << "Value for key 'orange': " << hashTable.get("orange") << endl;

    return 0;
}