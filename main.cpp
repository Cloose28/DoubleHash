#include <iostream>
#include "DoubleHashTable.cpp"

int main() {
    int n = 10;
    int count = 0;
    int averageCollision = 0;
    srand((unsigned int) time(NULL));
    for (int j = 0; j < 50; ++j) {
        int collisionCount = 0;
        HashTable hashTable(n);
        std::vector<int> repeat;
        for (int i = 0; i < n; ++i) {
            Item item;
            while (true) {
                bool flag = true;
                item.key = rand() % 100;
                for (int k = 0; k < repeat.size(); ++k) {
                    if (repeat[k] == item.key) {
                        flag = false;
                    }
                }
                if (flag) {
                    repeat.push_back(item.key);
                    break;
                }
            }

            item.info = 110 + rand() % 100;
            int collisions;
            do {
                collisions = hashTable.insert(item);
                if (collisions == -1) {
                    hashTable.rehashTable();
                }
            } while (collisions == -1);
            collisionCount += collisions;
        }
        hashTable.print();
        std::cout << "collisionCount: " << collisionCount << "\n";
        averageCollision += collisionCount;
        count++;
    }
    std::cout << "Average collision: " << (averageCollision/(count)) << "\n";
    return 0;
}