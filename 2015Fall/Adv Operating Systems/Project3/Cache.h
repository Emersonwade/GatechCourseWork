#include <string>
#include <iostream>

using namespace std;

class Cache {
protected:
    size_t cachesize;
public:
    Cache(size_t size):cachesize(size){};
    virtual ~Cache(){};
    virtual string* get(string url) {return NULL;};
    virtual void put(string url, string page) {
        cout<<url+" page cached"<<endl;
    };
};