#include <iostream>
#include <string>
using namespace std;

void solution(string digits, string map[], int i, string ans){
    if(i == digits.length()){
        cout << ans<< endl;
        return;
    }
    
    int digit = digits[i] - '0';
    string letters = map[digit];

    for(int j=0;j<letters.size(); j++){
        solution(digits, map, i+1, ans+letters[j]);
    }
}

int main()
{
    string map[] = {"","", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    solution("23", map, 0, "");
}