#include "LRUCache.h"

LRUCache::LRUCache(size_t size) {
    cachesize = size;
    currsize = 0;
}

string* LRUCache::get(string url) {
    map<string, string>::iterator it = this->mapTable.find(url);
    if (it == mapTable.end())
        return NULL;
    else {
        this->updateOrder(url);
        return &(it->second);
    }
}

void LRUCache::put(string url, string page) {
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
    else {
        order.erase(it);
        order.push_back(url);
    }
    
    mapTable[url] = page;
}

void LRUCache::updateOrder(string url) {
    vector<string>::iterator it = find(order.begin(), order.end(), url);
    if (it == order.end()) {
        order.push_back(url);
    }
    else {
        order.erase(it);
        order.push_back(url);
    }
}