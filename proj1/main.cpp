#include "givguv.h"
#include <iostream>

using givguv::GivuvMap;
using std::cout;
using std::endl;
using std::string;

int main() {
    GivuvMap map = GivuvMap(10);
    string key1 = "asdf";
    string key2 = "bbbb";
    string key3 = "dddd";
    string keyNotInDict = "foo bar";

    map.insert(key1, 222);
    map.insert(key2, 444);
    map.insert(key3, 1337);

    cout << "Value for key1: " << map.get(key1) << endl;
    cout << "Value for key2: " << map.get(key2) << endl;
    cout << "Value for key3: " << map.get(key3) << endl;
    cout << "Count: " << map.count() << endl;

    cout << "Check for a key not in the map. Is it in the map? " << map.exist(keyNotInDict) << endl;
    cout << "Check for a key (key1) in the map. Is key1 in the map? " << map.exist(key1) << endl;

    cout << "Now remove key1." << endl;
    map.remove(key1);
    cout << "Count: " << map.count() << endl;
    cout << "Check for a key (key1) in the map. Is key1 in the map? " << map.exist(key1) << endl;

    cout << "Find key for value 1337: " << map.find_key(1337) << endl;

    cout << "Copy assignment: " << endl;
    GivuvMap map2 = map;
    cout << "Find key for value 1337 in map2: " << map.find_key(1337) << endl;

    cout << "Are map and map2 equal? " << (map == map2) << endl;

    GivuvMap map3 = GivuvMap(20);
    string key4 = "mmm";
    map3.insert(key4, 1010);
    GivuvMap map4 = map + map3;
    cout << "Addition: " << map4.find_key(1337) << " and " << map4.get(key4) << endl;
    map += map3;
    cout << "Compound assignment: " << map.find_key(1337) << " and " << map.get(key4) << endl;
}
