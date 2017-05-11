//
// Created by konrad on 11.05.17.
//

#ifndef JIMP_EXERCISES_ALGO_H
#define JIMP_EXERCISES_ALGO_H

#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>


namespace algo {

    void CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out);

    bool Contains(const std::vector<int> &v, int element);


    void InitializeWith(int initial_value, std::vector<int> *v);

    std::vector<int> InitializedVectorOfLength(int length, int initial_value);

    std::vector<std::string> MapToString(const std::vector<double> &v);


    std::set<std::string> Keys(const std::map<std::string, int> &m);

    std::set<std::string> Values(const std::map<std::string, int> &m);

}


#endif //JIMP_EXERCISES_ALGO_H
