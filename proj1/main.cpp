#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;
using namespace std::placeholders;

int main() {
    // 1
    vector<int> vec = {1, 2, 3, 4, 1337, 1338, 2222};

    // 2
    cout << count(vec.begin(), vec.end(), 4) << endl;

    // 3
    cout << count_if(vec.begin(), vec.end(), bind(greater<>(), _1, 4)) << endl;

    // 4
    vec.erase(remove_if(vec.begin(), vec.end(), bind(greater<>(), 8, _1)), vec.end());

    // 5
    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout, "\n"));

    // 6
    vector<int> vec2;

    // 7
    transform(next(vec.begin()), vec.end(), vec.begin(), back_inserter(vec2), minus<>{});

    // 8
    copy(vec2.begin(), vec2.end(), ostream_iterator<int>(cout, "\n"));

    // 9
    cout << accumulate(vec2.begin(), vec2.end(), 0) << endl;
}
