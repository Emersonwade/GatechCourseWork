#include <iostream>
#include "FIFOCache.cpp"
#include "LRUCache.cpp"
#include "MAXSCache.cpp"

int main(){
    MAXSCache* fifoCache = new MAXSCache(50);
    fifoCache->put("1", "abcd");
    fifoCache->put("2", "secondStringTest");
    fifoCache->put("2", "secondStringTest");
    fifoCache->put("2", "hhhhh");
    fifoCache->put("3", "longgeeeeeeeeeeehndnfcnsanannan");
    fifoCache->put("1", "aaaa");
    fifoCache->put("4", "sadfaffaaf");
    fifoCache->put("5", "jnfdsjkafkj");
    fifoCache->put("6", "jnfdsjkafkj");
    fifoCache->put("7", "jnfdsjkafkj");

    
    map<string, string>::iterator it;
    for (it = (fifoCache->mapTable).begin(); it != (fifoCache->mapTable).end(); it++) {
        cout << it->first << " and " << it->second << endl;
    }
    cout << "The order is " << endl;
    for (set<pair<int, string> >::iterator it = (fifoCache->order).begin(); it != (fifoCache->order).end(); it++) {
        cout << (*it).second << " ";
    }
    cout << endl;
    //fifoCache->test();
}