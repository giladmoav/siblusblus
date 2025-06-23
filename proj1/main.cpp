#include <algorithm>
#include <functional>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using namespace std;

// excercise 1
char ex1(string& str, char num) {
    return accumulate(str.begin(), str.end(), num, bit_xor<>{});
}

// excercise 2
string ex2(string& str) {
    return accumulate(str.rbegin(), str.rend(), string(), [](string str1, char str2) { return str1 + str2; });
}

// excercise 3
bool ex3(vector<string>& names_vector) {
    return all_of(names_vector.begin(), names_vector.end(),
                  [](string& name) { return all_of(name.begin(), name.end(), isupper); });
}

// excercise 4
vector<int> ex4(vector<vector<int>>& vector_of_vectors) {
    return accumulate(
        vector_of_vectors.begin(), vector_of_vectors.end(), vector<int>(), [](vector<int> result, vector<int> element) {
            return get<1>(make_tuple(copy(element.begin(), element.end(), back_inserter(result)), result));
        });
}

int main() {
    string aaa = "ABCD";
    cout << ex1(aaa, 66) << endl;
    cout << ex2(aaa) << endl;
    vector<string> bad = {"ASD", "Aa"};
    vector<string> good = {"ASD", "AA"};
    cout << "GOOD: " << ex3(good) << " BAD: " << ex3(bad) << endl;
    vector<vector<int>> vector_of_vectors = {{1, 2}, {3}, {5, 6}};
    for (int elem : ex4(vector_of_vectors)) {
        cout << elem << ", ";
    }
}
