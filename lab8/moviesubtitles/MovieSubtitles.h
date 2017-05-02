//
// Created by konrad on 01.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iosfwd>
#include <iostream>
#include <string>
#include <sstream>
#include <regex>


namespace moviesubs {
    class MovieSubtitles {
    public:
        MovieSubtitles();

        virtual ~MovieSubtitles();

        virtual void ShiftAllSubtitlesBy(int a, int b, std::stringstream *in, std::stringstream *out) const = 0;
    };

    class MicroDvdSubtitles : public MovieSubtitles {
    public:
        MicroDvdSubtitles();

        ~MicroDvdSubtitles();

        virtual void ShiftAllSubtitlesBy(int timetomove, int framerate, std::stringstream *in,
                                         std::stringstream *out) const override;

    };

    class SubRipSubtitles : public MovieSubtitles {
    public:
        SubRipSubtitles();

        ~SubRipSubtitles();

        virtual void ShiftAllSubtitlesBy(int timetomove, int framerate, std::stringstream *in,
                                         std::stringstream *out) const override;

    };
}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
