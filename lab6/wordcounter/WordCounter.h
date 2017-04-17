//
// Created by konrad on 15.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <initializer_list>
#include <string>
#include <vector>
#include <istream>
#include <set>
#include <algorithm>

namespace datastructures {
    ////////////////////////////////// --------  WORD ---- WORD ---- WORD --- /////////////////////////////
    class Word {
    public:
        Word();

        Word(std::string init);

        std::string GetWord() const;

        void SetWord(std::string set);

    private:
        std::string word;
    };

    /////////// PRZEŁADOWANE OPERATORY //////////////////////////
    std::ostream &operator<<(std::ostream &, Word &);

    bool operator==(const Word &L, const Word &R);

    bool operator>(const Word &L, const Word &R);

    bool operator<(const Word &L, const Word &R);

    ////////////////////////////////// --------  COUNTS ---- COUNTS ---- COUNTS --- /////////////////////////////
    class Counts {
    public:
        Counts();

        Counts(int init);

        int GetCount() const;

        void SetCount(int set);

        Counts &operator++();

    private:
        int count;
    };

    /////////// PRZEŁADOWANE OPERATORY //////////////////////////
    bool operator==(const Counts &L, const Counts &R);

    bool operator>(const Counts &L, const Counts &R);

    bool operator<(const Counts &L, const Counts &R);

    ////////////////////////////////// --------  WORDCOUNTER ---- WORDCOUNTER ---- WORDCOUNTER --- /////////////////////////////
    class WordCounter {
    public:
        WordCounter();

        WordCounter(std::initializer_list<Word> init);

        size_t DistinctWords() const;

        size_t TotalWords() const;

        std::set<Word> Words();

        Counts operator[](std::string word);

    private:
        std::vector<std::pair<Word, Counts>> contener;

    };
}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
