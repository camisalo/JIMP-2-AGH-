//
// Created by konrad on 01.05.17.
//

#include "MovieSubtitles.h"

using ::std::cout;
using ::std::endl;

namespace moviesubs {
    MovieSubtitles::MovieSubtitles() {

    }

    MovieSubtitles::~MovieSubtitles() {}


    MicroDvdSubtitles::MicroDvdSubtitles() : MovieSubtitles() {

    }

    MicroDvdSubtitles::~MicroDvdSubtitles() {}


    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int timetomove, int framerate, std::stringstream *in,
                                                std::stringstream *out) const {
        int frametomove = ((timetomove * framerate) / 1000);
        char line[300];
        std::string start, stop;
        int i;
        std::cout << std::endl;
        while (in->getline(line, 300)) {
            start = "";
            stop = "";
            i = 1;
            if (line[0] != '\0') {
                *out << line[0];
                while (line[i] != '}') {
                    start += line[i];
                    i++;
                }
                i += 2;
                while (line[i] != '}') {
                    stop += line[i];
                    i++;
                }
                *out << (std::stoi(start) + frametomove) << "}{" << (std::stoi(stop) + frametomove) << "}";
                i++;
                while (line[i] != '\0') {
                    *out << line[i];
                    i++;
                }
                *out << "\n";
            }
        }
        cout << "ELO : " << out->str() << endl;
    }

    SubRipSubtitles::SubRipSubtitles() : MovieSubtitles() {}

    SubRipSubtitles::~SubRipSubtitles() {}


    void SubRipSubtitles::ShiftAllSubtitlesBy(int timetomove, int framerate, std::stringstream *in,
                                              std::stringstream *out) const {

    }


}