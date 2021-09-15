#include <iostream>

using namespace std;

int getSumEven(string card)
{
    int sumEven = 0;
    for(int i=card.size()-2; i>=0; i-=2){
        int dblNr = (card[i] - '0') * 2;
        if(dblNr > 9) sumEven += dblNr/10 + dblNr%10; 
        else sumEven += dblNr;
    }
    return sumEven;
}

int getSumOdd(string card)
{
     int sumOdd = 0;
       for(int i=card.size()-1; i>=0; i-=2){
        sumOdd += card[i] - '0';
    }
    return sumOdd;
}

bool isCardValid(string card)
{
    // Luhn's algorithm
    // Get the sum of numbers on odd places
    int sumOdd = getSumOdd(card);
    // Get the sum of numbers on even places
    // Each nr on even index is doubled and if it's greater than 10, the nr becomes the sum of its 2 digits
    // Then all those numbers add up to sumEven
    int sumEven = getSumEven(card);
    // if sum of sums is divisible by 10 the card number is valid
    return (sumEven+sumOdd) %10 == 0;
}

string getMerchant(string card)
{
    if(card[0] == '3') return "American Express Card";
    else if(card[0] == '4') return "Visa Card";
    else if(card[0] == '5') return "MasterCard";
    else if(card[0] == '6') return "Discover Credit Card";
    else return "Card";
}

int main()
{   
    // Examples of valid cards numbers: 
    // American Express: 371449635398431
    // Visa:             4012888888881881
    // MasterCard:       5196081888500645
    // Discover:         6011601160116611
    
    while(true){
        string answer;
        cout << "Type card number to see if it's valid, Q to exit" << endl;
        cin >> answer;
        if(answer == "q" || answer == "Q") break;
        string output = (isCardValid(answer) ? "Valid " + getMerchant(answer) : "INVALID");
        cout << output << endl << endl;
    }

    return 0;
}
