//
// Created by axeld on 9/06/2022.
//

#include "motivation.h"

motivation::motivation(bool b) {

    if(b) {
        initialQuotesRemoved = true;
    }

    else{
        quotes = initialQuotes;
        initialQuotesRemoved = false;
    }

    _initCheck = this;

    assert((this->properlyInitialized(), "Constructor must end in properlyInitialized state"));

}

motivation::motivation(const vector<string>& ownQuotes, bool b) {

    if(b){
        quotes = ownQuotes;
        vector<string> sizeCheck;
        set_union(ownQuotes.begin(), ownQuotes.end(), initialQuotes.begin(), initialQuotes.end(), sizeCheck.begin());
        if(sizeCheck.size() == ownQuotes.size()+initialQuotes.size()) {
            initialQuotesRemoved = true;
        }
        else{
            initialQuotesRemoved = false;
        }
    }

    else{
        initialQuotesRemoved = false;
        quotes = initialQuotes;
        for(auto &quote: ownQuotes){
            assert(("One of my original quotes detected in your list, please remove it or exclude my own list.",
                    find(quotes.begin(), quotes.end(), quote) == quotes.end()));
            quotes.push_back(quote);
        }
    }

    _initCheck = this;

    assert((this->properlyInitialized(), "Constructor must end in properlyInitialized state"));
    for(auto &check: ownQuotes){
        // Why not, we'll check if everything was properly added.
        // Can't ever be certain enough, right?
        assert((find(quotes.begin(), quotes.end(), check) != quotes.end()));
    }

}

motivation::motivation(const string &filename, bool b) {

    assert(("Invalid file given: please provide a .txt file", filename.find(".txt") == filename.size()-4));

    if(!b){
        quotes = initialQuotes;
        initialQuotesRemoved = false;
    }

    else{
        initialQuotesRemoved = true;
    }

    ifstream input(filename);
    string newLine;
    while(getline(input, newLine)){
        quotes.push_back(newLine);
    }

    _initCheck = this;

    assert((this->properlyInitialized(), "Constructor must end in properlyInitialized state"));

}

bool motivation::properlyInitialized() {

    if(_initCheck == this){
        return true;
    }

    return false;

}

void motivation::giveMotivations(int amount, double frequency) {

    assert(("Object \"motivation\" was not properly initialized when calling giveMotivations()", this->properlyInitialized()));
    assert(("Your list of quotes is currently empty! Add some and then try again.", !this->quotes.empty()));

    vector<string> alreadyPrinted;
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    default_random_engine generator(seed);
    std::this_thread::sleep_for(chrono::duration<double>(frequency));
    uniform_int_distribution<int> distribution(0, int(quotes.size()-1));
    for(int i = 0; i < amount; i++){

        int random = distribution(generator);
        while(find(alreadyPrinted.begin(), alreadyPrinted.end(), quotes[random]) != alreadyPrinted.end()){
            random = distribution(generator);
        }
        cout << quotes[random] << endl;
        alreadyPrinted.push_back(quotes[random]);
        if(i != amount-1){
            std::this_thread::sleep_for(chrono::duration<double>(frequency));
        }

    }

}

void motivation::addOwnQuote(const string &quote) {

    assert(("Object \"motivation\" was not properly initialized when calling addOwnQuote()", this->properlyInitialized()));
    assert(("Your given quote was already added", find(quotes.begin(), quotes.end(), quote)) == quotes.end());

    quotes.push_back(quote);
    if(find(initialQuotes.begin(), initialQuotes.end(), quote) != initialQuotes.end() && initialQuotesRemoved){
        initialQuotesRemoved = false;
    }
    cout << "Quote: \"" + quote + "\" successfully added to your list of quotes!" << endl;

}

void motivation::deleteInitialQuotes() {

    assert(("Object \"motivation\" was not properly initialized when calling deleteInitialQuotes()", this->properlyInitialized()));
    assert(("All initial quotes were already removed", !initialQuotesRemoved));

    for(auto &quote: initialQuotes){
        if(find(quotes.begin(), quotes.end(), quote) != quotes.end()){
            quotes.erase(find(quotes.begin(), quotes.end(), quote));
        }
    }

    initialQuotesRemoved = true;

}
