#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

using k_mer_edgelist_t = unordered_map<string, vector<string>>;

string prefix(const string &kmer) {
    return kmer.substr(0, kmer.length() - 1);
}

string suffix(const string &kmer) {
    return kmer.substr(1);
}

k_mer_edgelist_t DeBruijnKmers(vector<string> k_mers) {
    k_mer_edgelist_t adjList;
    for (const auto& kmer: k_mers) {
        adjList[prefix(kmer)].emplace_back(suffix(kmer));
    }
    return adjList;
}

void dumpAdjList(const k_mer_edgelist_t &adjList) {
    for (const auto &pair: adjList) {
        cout << pair.first << ":";
        for (const auto &kmer: pair.second) {
            cout << " " << kmer;
        }
        cout << endl;
    }
}

int main() {
    // vector<string> kmers{"GAGG", "CAGG", "GGGG", "GGGA", "CAGG", "AGGG", "GGAG"};
    ifstream inputFile("../datasets/dataset_29888_8.txt");
    assert(inputFile.is_open());
    vector<string> kmers;
    string kmer;
    while (inputFile >> kmer) {
        kmers.emplace_back(kmer);
    }
    auto res = DeBruijnKmers(kmers);

    dumpAdjList(res);
    return 0;
}