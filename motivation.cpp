//
// Created by axeld on 9/06/2022.
//

#include "motivation.h"

motivation::motivation() {

    initialQuotes = quotes;

}

motivation::motivation(const vector<string>& ownQuotes, bool b) {

    if(b){
        quotes = ownQuotes;
    }

    else{
        for(auto &quote: ownQuotes){
            if(find(quotes.begin(), quotes.end(), quote) != quotes.end()){
                cout << "Warning: One of my initial quotes detected in your list, the quote was not added a second time.";
            }
            else{
                quotes.push_back(quote);
            }
        }
    }

}

void motivation::giveMotivations(int amount, double frequency) {

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

void motivation::addOwnQuote(string &quote) {

    if (find(quotes.begin(), quotes.end(), quote) == quotes.end()) {
        quotes.push_back(quote);
        cout << "Quote: \"" + quote + "\" successfully added to your list of quotes!" << endl;
        return;
    }
    else {
        cout << "Your given quote is already inside the quote-list. "
                "To keep things equiprobable it was not added a second time." << endl;
        return;
    }

}

void motivation::deleteInitialQuotes() {

    for(auto &quote: initialQuotes){
        if(find(quotes.begin(), quotes.end(), quote) != quotes.end()){
            quotes.erase(find(quotes.begin(), quotes.end(), quote));
        }
    }

    initialQuotesRemoved = true;

}
