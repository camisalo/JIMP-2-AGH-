//
// Created by konrad on 22.04.17.
//

#ifndef JIMP_EXERCISES_ITERABLE_H
#define JIMP_EXERCISES_ITERABLE_H

#include <vector>
#include <string>
#include <iterator>

namespace utility {

    /* class Base{
         Dereference();
         Next();
         NotEquals();
     };
 */
    class IterableIterator {
        void Begin();

        void End();
    };

    class ZipperIterator {
    public:
        ZipperIterator();

        bool NotEquals(const ZipperIterator &zip);
    };


    class Enumerate {
    public:
        Enumerate();

        Enumerate(std::vector<std::string> init);

        std::pair<int, std::string> operator:
        (
        const Enumerate &iter
        );


    private:
        std::vector<std::pair<int, std::string>> iterator;
    };

}
#endif //JIMP_EXERCISES_ITERABLE_H
