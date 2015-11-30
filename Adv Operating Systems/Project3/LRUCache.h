#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class LRUCache {
protected:
    size_t cachesize;
    size_t currsize;
public:
    map<string, string> mapTable;
    vector<string> order;
    LRUCache(size_t size);
    ~LRUCache(){};
    string* get(string url);
    void put(string url, string page);
private:
    void updateOrder(string url);
};