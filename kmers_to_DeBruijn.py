def DeBruijnKmers(k_mers):
    adj_list = {}
    for kmer in k_mers:
        prefix = kmer[:-1]
        suffix = kmer[1:]
        current = adj_list.get(prefix, [])
        current.append(suffix)
        adj_list[prefix] = current

    return adj_list


if __name__ == '__main__':
    kmers = ["GAGG", "CAGG", "GGGG", "GGGA", "CAGG", "AGGG", "GGAG"]
    res = DeBruijnKmers(kmers)
    print(res)
