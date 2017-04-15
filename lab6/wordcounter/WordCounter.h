//
// Created by konrad on 15.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <initializer_list>
#include <string>
#include <vector>


namespace datastructures {
    class WordCounter {
    public:
        WordCounter();

        WordCounter(std::initializer_list<Word> init);


        DistinctWords() const;

        TotalWords() const;

    private:
        std::vector<std::pair<Word, Counts>>;

    };

    class Word {
    public:
        Word();

    private:
        std::string word;
    };

    class Counts {
    public:
        Counts();

    private:
        int count;
    };
}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
