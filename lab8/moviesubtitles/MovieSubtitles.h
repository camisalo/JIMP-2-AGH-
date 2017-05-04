//
// Created by konrad on 04.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iosfwd>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <regex>

using namespace std;

namespace moviesubs {

    class MovieSubtitles {
    public:
        MovieSubtitles() {}

        virtual void ShiftAllSubtitlesBy(int time, int framerate, stringstream *in,
                                         stringstream *out);
    };


    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        MicroDvdSubtitles() : MovieSubtitles() {}

        void ShiftAllSubtitlesBy(int time, int framerate, stringstream *in,
                                 stringstream *out) override;

        void CheckInput(int time, int framerate);
    };



}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
