//
// Created by konrad on 01.05.17.
//

#include "MovieSubtitles.h"

using ::std::cout;
using ::std::endl;

namespace moviesubs {
    MovieSubtitles::MovieSubtitles() {}

    MovieSubtitles::~MovieSubtitles() {}

    MicroDvdSubtitles::MicroDvdSubtitles() : MovieSubtitles() {}

    MicroDvdSubtitles::~MicroDvdSubtitles() {}

    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int timetomove, int framerate,
                                                std::stringstream *in,
                                                std::stringstream *out) const {

        if (timetomove < 0)
            throw NegativeFrameAfterShift();




        int frametomove = ((timetomove * framerate) / 1000);
        char line[300];
        std::string start, stop;
        int i, l = 1;
        std::cout << std::endl;
        while (in->getline(line, 300)) {

            std::string check;
            int h = 0;
            while (line[h] != '\0') {
                check += line[h];
                h++;
            }
            this->ChechLine(check);



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
                if (std::stoi(start) > std::stoi(stop)) {
                    std::string excep;
                    excep += "At line ";
                    excep += l;
                    excep += ": ";
                    int k = 0;
                    cout << excep << endl;
                    while (line[k] != '\0') {
                        excep += line[k];
                        k++;
                    }
                    cout << excep << endl;
                    throw SubtitleEndBeforeStart(l, excep);
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
            l++;
        }
    }

    void MicroDvdSubtitles::ChechLine(std::string line) const {
        std::string frames, temp;
        int p = 0, l = 0, i = 0;
        bool empty = true;
        std::string A = "0123456789";
        while (p < 2 && i < line.length()) {
            frames += line[i];
            i++;
            if (line[i] == '}')
                p++;
            else if (line[i] == '{')
                l++;
        }
        if (l != 2 || p != 2)
            throw InvalidSubtitleLineFormat();
        i = 0;
        temp = "";
        while (line[i] != '}') {
            empty = false;
            for (int m = 0; m < 10; m++) {
                if (line[i] != A[m])
                    throw InvalidSubtitleLineFormat();
            }
            i++;
        }
        if (empty)
            throw InvalidSubtitleLineFormat();
    }

    SubRipSubtitles::SubRipSubtitles() : MovieSubtitles() {}

    SubRipSubtitles::~SubRipSubtitles() {}


    void SubRipSubtitles::ShiftAllSubtitlesBy(int timetomove, int framerate,
                                              std::stringstream *in,
                                              std::stringstream *out) const {

        if (timetomove < 0)
            throw NegativeFrameAfterShift();


        int hr, min, sec, msec, TIME, T1, T2;
        int lineNuber, i, k = 0;
        char line[300];
        std::string temp, number, message;

        while (in->getline(line, 300)) {

            i = 0;
            number = "";
            message = "";
            while (line[i] != '\0') {
                number += line[i];
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

                if (j == 0)
                    T1 = TIME - timetomove;
                else
                    T2 = TIME - timetomove;

                hr = TIME / 3600000;
                min = (TIME - (hr * 3600000)) / 60000;
                sec = (TIME - (hr * 3600000) - (min * 60000)) / 1000;
                msec = TIME % 1000;

                if (hr < 10) {
                    *out << "0" << hr << ":";
                } else {
                    *out << hr << ":";
                }

                if (min < 10) {
                    *out << "0" << min << ":";
                } else {
                    *out << min << ":";
                }

                if (sec < 10) {
                    *out << "0" << sec << ",";

                } else {
                    *out << sec << ",";
                }

                if (msec < 100) {
                    *out << "0" << msec;
                } else if (msec < 10) {
                    *out << "00" << msec;
                } else {
                    *out << msec;
                }

                if (j == 0) {
                    *out << " --> ";
                }

                i += 5;
            }
            if (T1 > T2) {
                message = CreateTime(T1, T2);
                throw SubtitleEndBeforeStart(std::stoi(number), message);
            }
            /////////////////////

            *out << "\n";

            while (in->getline(line, 300)) {
                i = 0;
                while (line[i] != '\0') {
                    *out << line[i];
                    i++;
                }
                *out << '\n';
                if (line[0] == '\0')
                    break;
            }
        }


        std::string SubRipSubtitles::CreateTime(int T1, int T2) const {
            std::string message = "";
            hr = T1 / 3600000;
            min = (T1 - (hr * 3600000)) / 60000;
            sec = (T1 - (hr * 3600000) - (min * 60000)) / 1000;
            msec = T1 % 1000;

            if (hr < 10) {
                message += "0" + std::to_string(hr) + ":";
            } else {
                message += std::to_string(hr) + ":";
            }

            if (min < 10) {
                message += "0" + std::to_string(min) + ":";
            } else {
                message += std::to_string(min) + ":";
            }

            if (sec < 10) {
                message += "0" + std::to_string(sec) + ",";

            } else {
                message += std::to_string(sec) + ",";
            }

            if (msec < 100) {
                message += "0" + std::to_string(msec);
            } else if (msec < 10) {
                message += "00" + std::to_string(msec);
            } else {
                message += std::to_string(msec);
            }

            message += " --> ";
            ////////////////////////////////////////////////

        }
    }




}