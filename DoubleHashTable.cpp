#include <iostream>
#include <vector>

struct Item {
    int key;
    int info;
};

class HashTable {
private:
    Item* array;
    int N, M;

public:
    HashTable(int maxN) {
        M = 2*maxN;
        N = 0;
        array = new Item[M];
        for (int i = 0; i < M; ++i) {
            array[i].key = NULL;
        }
    }

    int hash(int key, int M) {
        return key % M;
    }

    inline int hashTwo(int key) {
        return (key % 97) + 1;
    }

    void rehashTable() {
        std::vector<Item> items;
        for (int j = 0; j < M; ++j) {
            if (array[j].key != NULL && array[j].key != -1) {
                items.push_back(array[j]);
            }
        }
        M += M;
        N = 0;
        free(array);
        array = new Item[M];
        for (int i = 0; i < M; ++i) {
            array[i].key = NULL;
        }
        for (int k = 0; k < items.size(); ++k) {
            insert(items[k]);
        }
    }

    int count() const { return N; }

    int insert(Item item) {
        int countCollision = 0;
        int i = hash(item.key, M);
        int k = hashTwo(item.key);
        int tmp = NULL;

        while (array[i].key != NULL) {
            if (tmp == NULL) {
                tmp = array[i].key;
            } else {
                if (array[i].key == tmp) {
                    countCollision = -1;
                    break;
                }
            }
            ++countCollision;
            i = (i + k) % M;
        }
        if (countCollision != -1) {
            std::cout << i << " ";
            array[i] = item;
            ++N;
        }
        return countCollision;
    }

    Item search(int key) {
        int i = hash(key, M);
        int k = hashTwo(key);
        while (array[i].key != NULL) {
            if (array[i].key == key) {
                return array[i];
            } else {
                i += k % M;
            }
        }
        Item item;
        item.key = NULL;
        return item;
    }

    void remove(int key){
        int i = hash(key, M);
        int k = hashTwo(key);
        while (array[i].key != NULL) {
            if (array[i].key == key) {
                break;
            } else {
                i += k % M;
            }
        }
        if (array[i].key == NULL) return;
        array[i].key = -1;
        --N;
    }

    void print() {
        std::cout << "\n";
        for (int i = 0; i < M; ++i) {
            if (array[i].key == NULL || array[i].key == -1) continue;
            std::cout << "Index: " << i << ", Item.key: " << array[i].key << ", Item.info: " << array[i].info << "\n";
        }
    }
};
