//
// Created by konrad on 11.05.17.
//


#include "Algo.h"


void ::algo::CopyInto(const std::vector<int> &v, int n_elements, std::vector<int> *out) {

    std::copy_n(v.begin(), n_elements, std::back_inserter(*out));


}

bool ::algo::Contains(const std::vector<int> &v, int element) {
    return std::find(v.begin(), v.end(), element) != v.end();
}

void algo::InitializeWith(int initial_value, std::vector<int> *v) {
    fill(v->begin(), v->end(), initial_value);
}

std::vector<int> algo::InitializedVectorOfLength(int length, int initial_value) {

    return std::vector<int>((unsigned int) length, initial_value);
}

std::vector<std::string> algo::MapToString(const std::vector<double> &v) {
    std::vector<std::string> S;
    std::transform(v.begin(), v.end(), std::back_inserter(S), [](double i) { return std::to_string(i); });
    return S;
}

std::set<std::string> algo::Values(const std::map<std::string, int> &m) {
    return std::set<std::string>();
}

std::set<std::string> algo::Keys(const std::map<std::string, int> &m) {
    return std::set<std::string>();
}


