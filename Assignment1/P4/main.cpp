#include<iostream>
#include <string>
#include <set>

using namespace std;
set<string>newWord;
void RecPermute(string soFar, string rest)
{
    if (rest == "") // No more characters
        newWord.insert(soFar); // Insert the word in the set
    else // Still more chars
// For each remaining char
        for (int i = 0; i < rest.length(); i++) {
            string next = soFar + rest[i]; // Glue next char
            string remaining = rest.substr(0, i)+ rest.substr(i+1);
            RecPermute(next, remaining);
        }
}
// "wrapper" function


void ListPermutations(string s) {
    RecPermute("", s);
}




int main(){
    ListPermutations("Makka");
    for (auto s:newWord)
        cout<<s<<endl;



            }