//
// Created by axeld on 9/06/2022.
//

#ifndef GOODTIMES_MOTIVATION_H
#define GOODTIMES_MOTIVATION_H

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <cassert>
#include <mapidbg.h>
#include <windows.h>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

class motivation {

public:

    // Default constructor.
    motivation();

    // Constructor where you can already give a list of quotes, so they are added from the start.
    // And a boolean if you want my quotes removed (= true) or not (= false).
    motivation(const vector<string>&, bool);

    // Choose how many motivational quotes you want to receive, and how frequently they should appear.
    void giveMotivations(int, double);

    // You can add your own motivational quotes if you want!
    void addOwnQuote(string&);

    // If you wish, you can remove my self-added quotes from the vector
    // However do keep in mind that this potentially can leave you with an empty vector
    // If this is the case you cannot use giveMotivations()
    void deleteInitialQuotes();

private:

    // All quotes are saved inside a vector, some of my own are always in there at the start.
    vector<string> quotes = {"Yanfei says you got this, because it is the law!", "Keep up the good work fam!",
                             "You are doing great right now, continue a bit more and then take a well-deserved break!",
                             "It is fine to take a rest from time to time, do whatever is necessary for you and your health.",
                             "You rock!", "Whether it is your job, a paper or an exam you are working for, you will prevail!",
                             ""};

    vector<string> initialQuotes;

    bool initialQuotesRemoved = false;

};


#endif //GOODTIMES_MOTIVATION_H
