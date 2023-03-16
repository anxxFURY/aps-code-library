//
// Created by Ani Hadagali on 16/03/23.
//
#include <iostream>
#include "algorithm"
#include "vector"
#include "list"
#include "utility"
#include "unordered_map"
#include "queue"
#include "set"

using namespace std;

int solve(string start,string end, list<string> &wordList) {
    queue<pair<string,int>> q;
    set<string> s(wordList.begin(),wordList.end()); // To add all the elements in the set to keep the track of count of the word
    q.push({start,1});
    s.erase(start);

    while(!q.empty()) {
        string word =q.front().first;
        int steps = q.front().second;
        q.pop();
        if(word == end) {
            return steps;
        }
        for(int i = 0; i < word.size(); i++) {
            char original = word[i];

            for(char c = 'a'; c <= 'z'; c++) {
                word[i] = c;
                // Finding the element in a set...
                if(s.find(word) != s.end()) {
                    q.push({word,steps+1});
                    s.erase(word);
                }
            }
            word[i] = original;
        }
    }
    return 0;
}

int main() {
    string start = "hot";
    string end = "dog";
    list<string> dic = {"cat","cod","cog","dot","dog"};
    // Minimum conversion required to convert the start string to end word
    int steps = solve(start,end,dic);
    return 0;
}