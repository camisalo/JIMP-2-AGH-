//
// Created by konrad on 24.04.17.
//

#ifndef JIMP_EXERCISES_KSZTALT_H
#define JIMP_EXERCISES_KSZTALT_H

#include <iostream>
#include <vector>
#include <cstdlib>

class Ksztalt {
public:
    Ksztalt();

    virtual void rysuj() = 0;
};

class Trojkat : public Ksztalt {
public:
    Trojkat(int a);

    virtual void rysuj() override;

private:
    int a_;
};

class Kwadrat : public Ksztalt {
public:
    Kwadrat(int a);

    virtual void rysuj() override;

private:
    int a_;
};

class Kolo : public Ksztalt {
public:
    Kolo(int r);

    virtual void rysuj() override;

private:
    int r_;
};


#endif //JIMP_EXERCISES_KSZTALT_H
