//
// Created by konrad on 01.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H

#include <iosfwd>
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
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

        void ChechLine(std::string line) const;

    };

    class SubRipSubtitles : public MovieSubtitles {
    public:
        SubRipSubtitles();

        ~SubRipSubtitles();

        virtual void ShiftAllSubtitlesBy(int timetomove, int framerate, std::stringstream *in,
                                         std::stringstream *out) const override;

        std::string CreateTime(int T1, int T2) const;

    };

    class DataValidationError : public std::runtime_error {
    public:
        DataValidationError(const std::string inf = "something went wrong") : std::runtime_error(inf) {}
    };

    class NegativeFrameAfterShift : public DataValidationError {
    public:
        NegativeFrameAfterShift() : DataValidationError("Negative Frame after Shift") {}
    };

    class SubtitleEndBeforeStart : public DataValidationError {
    public:
        SubtitleEndBeforeStart(int line, const std::string message) : line{line}, DataValidationError(
                "At line " + std::to_string(line) + ": " + message) {}

        int LineAt() const { return line; }

    private:
        int line;
    };

    class InvalidSubtitleLineFormat : public DataValidationError {
    public:
        InvalidSubtitleLineFormat() : DataValidationError() {}

    };

    class MissingTimeSpecification : public DataValidationError {
    public:
        MissingTimeSpecification() : DataValidationError("missing time") {}
    };

    class OutOfOrderFrames : public DataValidationError {
        OutOfOrderFrames() : DataValidationError("Missing order frames") {}

    };
}


#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
