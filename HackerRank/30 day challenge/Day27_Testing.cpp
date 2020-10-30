#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

int minimum_index(vector<int> seq) {
    if (seq.empty()) {
        throw invalid_argument("Cannot get the minimum value index from an empty sequence");
    }
    int min_idx = 0;
    for (int i = 1; i < seq.size(); ++i) {
        if (seq[i] < seq[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}
class TestDataEmptyArray {
public:
    static vector<int> get_array() {

        vector<int> empty_array;

        return empty_array;
        // complete this function
    }

};

class TestDataUniqueValues {
public:


    static vector<int> get_array() {

        vector<int> non_empty_vector{1,2,3,4,5,};

        return non_empty_vector;
        // complete this function
    }

    static int get_expected_result() {

        vector<int> non_empty_vector = get_array();

        int min_pos = 0;

        for(int i = 1; i < non_empty_vector.size(); ++i)
        {
            if(non_empty_vector[i] < non_empty_vector[min_pos])
                min_pos = i;

        }
        // complete this function
        return min_pos;
    }

};

class TestDataExactlyTwoDifferentMinimums {
public:
    static vector<int> get_array() {


    vector<int> two_minima_vector{1,1};

    return two_minima_vector;

        // complete this function
    }

    static int get_expected_result() {

        vector<int> expected_vector = get_array();

        int min_pos = 0;

        for(int i = 1; i < expected_vector.size(); i++)
        {
            if(expected_vector[i] < expected_vector[min_pos])
            {
                min_pos = i;
            }

        }
                return min_pos;
        // complete this function
    }

};


void TestWithEmptyArray() {
    try {
        auto seq = TestDataEmptyArray::get_array();
        auto result = minimum_index(seq);
    } catch (invalid_argument& e) {
        return;
    }
    assert(false);
}

void TestWithUniqueValues() {
    auto seq = TestDataUniqueValues::get_array();
    assert(seq.size() >= 2);

    assert(set<int>(seq.begin(), seq.end()).size() == seq.size());

    auto expected_result = TestDataUniqueValues::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

void TestWithExactlyTwoDifferentMinimums() {
    auto seq = TestDataExactlyTwoDifferentMinimums::get_array();
    assert(seq.size() >= 2);

    auto tmp = seq;
    sort(tmp.begin(), tmp.end());
    assert(tmp[0] == tmp[1] and (tmp.size() == 2 or tmp[1] < tmp[2]));

    auto expected_result = TestDataExactlyTwoDifferentMinimums::get_expected_result();
    auto result = minimum_index(seq);
    assert(result == expected_result);
}

int main() {
    TestWithEmptyArray();
    TestWithUniqueValues();
    TestWithExactlyTwoDifferentMinimums();
    cout << "OK" << endl;
    return 0;
}
