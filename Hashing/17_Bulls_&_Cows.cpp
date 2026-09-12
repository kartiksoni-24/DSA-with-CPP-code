#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

void bullsAndCows(string secret, string guess){
    int bulls = 0;
    int cows = 0;
    unordered_map<char, int> m;

    for (int i = 0; i < secret.size(); i++)
    {
        if(secret[i] == guess[i]){
            bulls++;
        } else{
            m[secret[i]]++;
        }
    }
    
    for (int i = 0; i < guess.size(); i++)
    {
        if(m.count(guess[i]) && m[guess[i]] > 0){
            cows++;
            m[guess[i]]--;
        }
    }
    
    cout << bulls << "A" << cows << "B";
}

int main(){
    string secret = "1123";
    string guess = "0111";

    bullsAndCows(secret, guess);
    return 0;
}