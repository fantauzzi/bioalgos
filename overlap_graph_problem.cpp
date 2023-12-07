#include <unordered_map>
#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <fstream>
#include <cassert>

using namespace std;

using k_mer_edgelist_t = unordered_map<string, vector<string>>;
using k_mer_edgeset_t = unordered_map<string, set<string>>;

string prefix(string kmer) {
    return kmer.substr(0, kmer.length() - 1);
}

string suffix(string kmer) {
    return kmer.substr(1);
}


// Insert your OverlapGraph function here, along with any subroutines you need
k_mer_edgelist_t OverlapGraph(std::vector<std::string> Patterns) {

    /* Associate every prefix occurring in Patterns with all the k-mers in Patterns having that prefix;
     * every prefix is associated with any given k-mere at most once */
    k_mer_edgeset_t prefixes;
    for (auto kmer: Patterns) {
        prefixes[prefix(kmer)].insert(kmer);
    }

    // Compile the adjacency list for the overlap graph into `res`.
    k_mer_edgelist_t res;
    for (auto kmer: Patterns) {
        auto adjaciencies = prefixes[suffix(kmer)];
        res[kmer] = vector(adjaciencies.begin(), adjaciencies.end());
    }

    // Remove entries with empty adjacency list
    for (auto iter = res.begin(); iter != res.end();) {
        if (iter->second.empty()) {
            iter = res.erase(iter);
        } else {
            ++iter;
        }
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
    // vector<string> kmers{"AAG", "AGA", "ATT", "CTA", "CTC", "GAT", "TAC", "TCT", "TCT", "TTC"};
    auto kmers = load_dataset("../datasets/dataset_29886_10.txt");
    auto res = OverlapGraph(kmers);
    for (const auto& pair: res) {
        cout << pair.first << ":";
        for (const auto& kmer: pair.second) {
            cout << " " << kmer;
        }
        cout << endl;
    }
    return 0;
}