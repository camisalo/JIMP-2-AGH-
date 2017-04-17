//
// Created by konrad on 15.04.17.
//

#include "WordCounter.h"

namespace datastructures {

    ////////////////////////////////// --------  WORDCOUNTER ---- WORDCOUNTER ---- WORDCOUNTER --- /////////////////////////////


    WordCounter::WordCounter() {}

    WordCounter::WordCounter(std::initializer_list<Word> init) {
        bool ok;
        for (auto v:init) {
            ok = false;
            for (auto k:contener) {
                if (k.first == v) {
                    ++k.second;
                    ok = true;
                }
            }
            if (!ok) {
                std::pair<Word, Counts> p;
                p.first = v;
                p.second = Counts();
                contener.push_back(p);
            }
        }
    }


    size_t WordCounter::DistinctWords() const {
        return contener.size();
    }

    size_t WordCounter::TotalWords() const {
        int sum = 0;
        for (auto v:contener) {
            sum += v.second.GetCount();
        }
        return (size_t) sum;
    }

    std::set<Word> WordCounter::Words() {
        std::sort(contener.begin(), contener.end());
        std::set<Word> SortedWords;
        for (auto v:contener) {
            SortedWords.emplace(v.first);
        }
        return SortedWords;
    }

    Counts WordCounter::operator[](std::string word) {
        for (auto v:contener) {
            if (word == v.first.GetWord());
            return v.second;
        }
        return Counts(0);
    }

    ////////////////////////////////// --------  WORD ---- WORD ---- WORD --- /////////////////////////////

    Word::Word() {}

    Word::Word(std::string init) : word{init} {}

    std::string Word::GetWord() const {
        return word;
    }

    void Word::SetWord(std::string set) {
        word = set;
    }

    std::ostream &operator<<(std::ostream &output, Word &in) {
        std::string out = in.GetWord();
        output << out;
        return output;
    }

    bool operator==(const Word &L, const Word &R) {
        return (L.GetWord() == R.GetWord());
    }

    bool operator>(const Word &L, const Word &R) {
        return (L.GetWord() > R.GetWord());
    }

    bool operator<(const Word &L, const Word &R) {
        return (L.GetWord() > R.GetWord());
    }


    ////////////////////////////////// --------  COUNTS ---- COUNTS ---- COUNTS --- /////////////////////////////


    Counts::Counts() : count{1} {}

    Counts::Counts(int init) : count{init} {}

    int Counts::GetCount() const {
        return count;
    }

    void Counts::SetCount(int set) {
        count = set;
    }

    Counts &Counts::operator++() {
        ++count;
    }


    bool operator==(const Counts &L, const Counts &R) {
        return (L.GetCount() == R.GetCount());
    }

    bool operator>(const Counts &L, const Counts &R) {
        return (L.GetCount() > R.GetCount());
    }

    bool operator<(const Counts &L, const Counts &R) {
        return (L.GetCount() > R.GetCount());
    }



}