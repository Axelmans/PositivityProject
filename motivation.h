//
// Created by axeld on 9/06/2022.
//

#ifndef GOODTIMES_MOTIVATION_H
#define GOODTIMES_MOTIVATION_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
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

    /* Default constructor, start with an empty list or with my list of self-included quotes!
     * True = start with empty list, false = start with my quotes. */
    motivation(bool);

    /* Constructor where you can already give a list of quotes, so they are added from the start.
     * And a boolean if you want my quotes removed (= true) or not (= false). */
    motivation(const vector<string>&, bool);

    /* Constructor that accepts a string that represents a filename of a text file, every line from the txt file
     * will be seen as a quote. */
    motivation(const string&, bool);

    /* Choose how many motivational quotes you want to receive, and how frequently they should appear. */
    void giveMotivations(int, double);

    /* You can add your own motivational quotes if you want! */
    void addOwnQuote(const string&);

    /* If you wish, you can remove my self-added quotes from the vector
     * However do keep in mind that this potentially can leave you with an empty vector
     * If this is the case you cannot use giveMotivations(). */
    void deleteInitialQuotes();

    /* Delete a given quote if it is in the list. */
    void deleteQuote(const string&);

    /* Delete a quote on a certain index */
    void deleteQuoteIndex(int);

    /* Delete quotes in a certain index range */
    void deleteQuotesIndexRange(int, int);

    /* Function to check if object is properly initialized (it is usually if you constructed it before using any functions). */
    bool properlyInitialized();

private:

    /* All quotes are saved inside a vector, some of my own are always in there at the start. */
    vector<string> quotes;

    vector<string> initialQuotes = {"Yanfei says you got this, because it is the law!", "Keep up the good work fam!",
                                    "You are doing great right now, continue a bit more and then take a well-deserved break!",
                                    "It is fine to take a rest from time to time, do whatever is necessary for you and your health.",
                                    "You rock!", "Whether it is your job, a paper or an exam you are working for, you will prevail!",
                                    "Axel says: you will conquer!", "Yelan believes in you!", "Raiden knows your talents are eternal!"};

    bool initialQuotesRemoved;

    motivation* _initCheck;

};


#endif //GOODTIMES_MOTIVATION_H
