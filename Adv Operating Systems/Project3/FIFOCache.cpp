#include "FIFOCache.h"

FIFOCache::FIFOCache(size_t size) {
    cachesize = size;
    currsize = 0;
}

string* FIFOCache::get(string url) {
    map<string, string>::iterator it = this->mapTable.find(url);
    if (it == mapTable.end())
        return NULL;
    else {
        return &(it->second);
    }
}

void FIFOCache::put(string url, string page) {
    vector<string>::iterator it = find(order.begin(), order.end(), url);
    if (it == order.end()) {
        while (currsize + page.size() > cachesize) {
            string oldurl = order.front();
            order.erase(order.begin());
            currsize = currsize - (mapTable[oldurl]).size();
            mapTable.erase(oldurl);
        }
        currsize = currsize + page.size();                
        order.push_back(url);
    }

    mapTable[url] = page;
}

void FIFOCache::updateOrder(string url) {
}