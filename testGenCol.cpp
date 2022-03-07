#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <map>

using namespace std;

string generateColors(string answer, string guess);
int checkDouble(string guess, char guessLetter, int idx);

int main(){
    cout << generateColors("floss", "soare") << endl;
}

string generateColors(string answer, string guess){
    map<int, int> mapAns, mapGuess;
    for (int j = 0; j < 5; ++j){
        mapAns[answer[j]] = 0;
    }
    for (int j = 0; j < 5; ++j){
        mapGuess[guess[j]] = 0;
    }
    for (int j = 0; j < 5; ++j){
        mapAns[answer[j]]++;
    }
    for (int j = 0; j < 5; ++j){
        mapGuess[guess[j]]++;
    }
    string result = "";
    for (int i = 0; i < 5; ++i){
        if (guess[i] != answer[i]){ //yellow or gray
            if (answer.find(guess[i]) == answer.npos){
                result += "X";
            }
            else{
                cout << "letter: " << guess[i] << endl;
                cout << "mapans: " << mapAns[guess[i]] << endl;
                cout << "mapguess: " << mapGuess[guess[i]] << endl;
                if (mapAns[guess[i]] >= mapGuess[guess[i]]){
                    result += "Y";
                }
                else{
                    mapGuess[guess[i]]--;
                    result += "X";
                }
            }
        }
        else{ //green
            result += "G";
        }
    }
    return result;
}


int checkDouble(string guess, char guessLetter, int idx){
    for (int i = 0; i < 5; ++i){
        if (guess[i] == guessLetter && i != idx){
            return i;
        }
    }
    return -1;
}