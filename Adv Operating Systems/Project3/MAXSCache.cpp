#include "MAXSCache.h"

MAXSCache::MAXSCache(size_t size) {
    cachesize = size;
    currsize = 0;
}

string* MAXSCache::get(string url) {
    map<string, string>::iterator it = this->mapTable.find(url);
    if (it == mapTable.end())
        return NULL;
    else {
        return &(it->second);
    }
}

void MAXSCache::put(string url, string page) {
    set<pair<int, string> >::iterator it = order.begin();
    for (; it != order.end(); it++) {
        if (it->second == url)
            break;
    }
    if (it == order.end()) {
        while (currsize + page.size() > cachesize) {
            pair<int, string> oldurlpair = *(order.begin());
            order.erase(order.begin());
            currsize = currsize - (mapTable[oldurlpair.second]).size();
            mapTable.erase(oldurlpair.second);
        }
        currsize = currsize + page.size();
        order.insert(make_pair(page.size(), url));
    }
    mapTable[url] = page;
    //this->updateOrder(url);
}
/*
void MAXSCache::updateOrder(string url) {
    sort(order.begin(), order.end(), cmp());
}
*/
void MAXSCache::test() {
    cout << "currsize is " << currsize << endl;
}