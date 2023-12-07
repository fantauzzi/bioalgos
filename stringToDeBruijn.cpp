#include <unordered_map>
#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <fstream>

using namespace std;

using k_mer_edgelist_t = unordered_map<string, vector<string>>;

k_mer_edgelist_t DeBruijnString(string Text, int k) {
    k_mer_edgelist_t adjList;
    for (int i = 0; i <= Text.length() - k; ++i) {
        auto vertex1 = Text.substr(i, k - 1);
        assert(vertex1.length() == k - 1);
        auto vertex2 = Text.substr(i + 1, k - 1);
        assert(vertex2.length() == k - 1);
        adjList[vertex1].emplace_back(vertex2);
    }
    return adjList;
}

void dumpAdjList(k_mer_edgelist_t adjList) {
    for (const auto &pair: adjList) {
        cout << pair.first << ":";
        for (const auto &kmer: pair.second) {
            cout << " " << kmer;
        }
        cout << endl;
    }
}

int main() {
    // string s{"TAATGCCATGGGATGTT"};
    ifstream inputFile("../datasets/dataset_29887_6.txt");
    assert (inputFile.is_open());
    int k;
    string text;
    inputFile >> k;
    inputFile >> text;
    inputFile.close();

    auto res = DeBruijnString(text, k);
    dumpAdjList(res);

    return 0;
}