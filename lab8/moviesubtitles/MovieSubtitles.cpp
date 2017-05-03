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


    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int timetomove, int framerate,
                                                std::stringstream *in,
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
                *out << (std::stoi(start) + frametomove) << "}{"
                     << (std::stoi(stop) + frametomove) << "}";
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


    void SubRipSubtitles::ShiftAllSubtitlesBy(int timetomove, int framerate,
                                              std::stringstream *in,
                                              std::stringstream *out) const {
        int hr, min, sec, msec, TIME;
        int lineNuber, i;
        char line[300];
        std::string temp;

        while (in->getline(line, 300)) {
            i = 0;
            while (line[i] != '\0') {
                *out << line[i];
                i++;
            }
            *out << '\n';
            i = 0;
            in->getline(line, 300);
            for (int j = 0; j < 2; ++j) {
                TIME = timetomove;
                temp = "";
                while (line[i] != ':') {
                    temp += line[i];
                    i++;
                }
                TIME += std::stoi(temp) * 3600000;
                temp = "";
                i++;

                while (line[i] != ':') {
                    temp += line[i];
                    i++;
                }
                TIME += std::stoi(temp) * 60000;
                temp = "";
                i++;

                while (line[i] != ',') {
                    temp += line[i];
                    i++;
                }
                TIME += std::stoi(temp) * 1000;
                temp = "";
                i++;

                while (line[i] != ' ') {
                    temp += line[i];
                    i++;
                }
                TIME += std::stoi(temp);

                hr = TIME / 3600000;
                min = (TIME - (hr * 3600000)) / 60000;
                sec = (TIME - (hr * 3600000) - (min * 60000)) / 1000;
                msec = TIME % 1000;

                if (hr < 10)
                    *out << "0" << hr << ":";
                else
                    *out << hr << ":";

                if (min < 10)
                    *out << "0" << min << ":";
                else
                    *out << min << ":";

                if (sec < 10)
                    *out << "0" << sec << ",";
                else
                    *out << sec << ",";

                if (msec < 100)
                    *out << "0" << msec;
                else if (msec < 10)
                    *out << "00" << msec;
                else
                    *out << msec;

                if (j == 0)
                    *out << " --> ";

                i += 5;
            }
            *out << "\n";

            while (in->getline(line, 300) && line[0] != '\0') {
                i = 0;
                while (line[i] != '\0') {
                    *out << line[i];
                    i++;
                }
                *out << '\n';
            }
            *out << '\n';
        }
    }
}