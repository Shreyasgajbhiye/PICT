#include <iostream>

using namespace std;

// Structure for storing key-value pairs
struct node {
    int key;
    int value;
    node* next;

    node(int k, int v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

// HashTable class
class HashTable {
private:
    static const int TABLE_SIZE = 10;
    node* table[TABLE_SIZE];

    // Hash function H(x) = (3x + 5) % 10
    int hashFunction(int key) {
        return (3 * key + 5) % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    // Insert key-value pair into the hash table
    void insert(int key, int value) {
        int index = hashFunction(key);
        node* newPair = new node(key, value);
        if (table[index] == nullptr) {
            table[index] = newPair;
        } else {
            node* current = table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newPair;
        }
    }

    // Find the value associated with the given key
    int find(int key) {
        int index = hashFunction(key);
        node* current = table[index];
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        return -1; // Return -1 if key not found
    }

    // Delete the key-value pair with the given key
    void remove(int key) {
        int index = hashFunction(key);
        node* current = table[index];
        node* prev = nullptr;
        while (current != nullptr) {
            if (current->key == key) {
                if (prev == nullptr) {
                    table[index] = current->next;
                } else {
                    prev->next = current->next;
                }
                delete current;
                return;
            }
            prev = current;
            current = current->next;
        }
    }

    // Display the hash table with buckets and links
    void display() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            cout << "Bucket " << i << ": ";
            node* current = table[i];
            while (current != nullptr) {
                cout << "(" << current->key << ", " << current->value << ") -> ";
                current = current->next;
            }
            cout << "NULL" << endl;
        }
    }

    // Destructor
    ~HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            node* current = table[i];
            while (current != nullptr) {
                node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable ht;

    // Insert some key-value pairs
    ht.insert(3, 30);
    ht.insert(7, 70);
    ht.insert(13, 130);
    ht.insert(23, 230);
    ht.insert(33, 330);
    ht.insert(43, 430);

    // Display the hash table
    cout << "Hash Table:" << endl;
    ht.display();
    cout << endl;
    // Find and display values for some keys
    cout << "Value for key 13: " << ht.find(13) << endl;
    cout << "Value for key 33: " << ht.find(33) << endl;
    cout << endl;
    // Remove a key
    ht.remove(13);
    ht.remove(7);

    // Display the hash table after removal
    cout << "Hash Table after removing key 13:" << endl;
    ht.display();

    return 0;
}
