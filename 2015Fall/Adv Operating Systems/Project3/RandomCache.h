#include <string>
#include <iostream>
#include "Cache.h"

using namespace std;

class RandomCache : public Cache {
protected:
    
public:
    RandomCache(size_t size);
    ~RandomCache(){};
    string* get(string url) {return NULL;};
    void put(string url, string page) {
        cout<<url+" page cached"<<endl;
    };
};