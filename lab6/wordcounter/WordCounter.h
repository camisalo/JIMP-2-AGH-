//
// Created by konrad on 15.04.17.
//

#ifndef JIMP_EXERCISES_WORDCOUNTER_H
#define JIMP_EXERCISES_WORDCOUNTER_H

#include <initializer_list>
#include <string>
#include <vector>


namespace datastructures {
    class Word {
    public:
        Word(std::string init);


    private:
        std::string word;
    };

    class Counts {
    public:
        Counts();

    private:
        int count;
    };


    class WordCounter {
    public:
        WordCounter();

        WordCounter(std::initializer_list<Word> init);


        int DistinctWords() const;

        int TotalWords() const;

    private:
        std::vector<std::pair<Word, Counts>> contener;

    };
}


#endif //JIMP_EXERCISES_WORDCOUNTER_H
