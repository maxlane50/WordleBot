#include <vector>
#include <string>
#include <iostream>
using namespace std;

int main(){
    vector<char> letters;
    letters.push_back('X');
    letters.push_back('Y');
    letters.push_back('G');
    for (int i = 0; i < 3; ++i){
        string curCombo = "";
        curCombo += letters[i];
        for (int j = 0; j < 3; ++j){
            curCombo = curCombo.substr(0, 1);
            curCombo += letters[j];
            for (int m = 0; m < 3; ++m){
                curCombo = curCombo.substr(0, 2);
                curCombo += letters[m];
                for (int q = 0; q < 3; ++q){
                    curCombo = curCombo.substr(0, 3);
                    curCombo += letters[q];
                    for (int r = 0; r < 3; ++r){
                        curCombo += letters[r];
                        cout << "\"" << curCombo << "\", ";
                        curCombo = curCombo.substr(0, 4);
                    }
                }
            }
        }
    }
}