#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

string GenomePath(vector<string> path) {

    string res;
    for (const auto &kmer: path) {
        res += (res.length() == 0) ? kmer : string(kmer, kmer.length() - 1, 1);
    }
    return res;
}

vector<string> load_dataset(string filePath) {
    ifstream inputFile(filePath);
    assert(inputFile.is_open());
    vector<string> res;
    string s;
    while (inputFile >> s) {
        res.emplace_back(s);
    }
    return res;

}

int main() {
    // vector<string> path{"ACCGA", "CCGAA", "CGAAG", "GAAGC", "AAGCT"};
    vector<string> path{load_dataset("../datasets/dataset_29886_3.txt")};
    auto res = GenomePath(path);
    cout << res << endl;
    return 0;
}