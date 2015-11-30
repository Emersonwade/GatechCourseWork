#include <string>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

class MAXSCache {
    // struct cmp
    // {
    //     bool operator ()(const pair<int, string> &a, const pair<int, string> &b)
    //     {
    //         return a.first > b.first;
    //     }
    // };
protected:
    size_t cachesize;
    size_t currsize;
public:
    map<string, string> mapTable;
    set<pair<int, string>, greater<pair<int, string> > > order;
    MAXSCache(size_t size);
    ~MAXSCache(){};
    string* get(string url);
    void put(string url, string page);
    void test();
private:
    void updateOrder(string url);
};