//
// Created by konrad on 01.05.17.
//

#include <MovieSubtitles.h>

using namespace std;
using ::moviesubs::MicroDvdSubtitles;

int main(void) {

    auto subs = make_unique<MicroDvdSubtitles>();

    std::stringstream in{"{0}{250}TEXT\n{260}{300}NEWLINE\n"};
    std::stringstream out;


    subs->ShiftAllSubtitlesBy(300, 25, &in, &out);
    return 0;
}
