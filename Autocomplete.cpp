#include <iostream>
#include <vector>
#include <bits/stdc++.h>


using namespace std;

class TrieNode{
public:
    TrieNode(){
        isEnd = false;
        for(int i = 0; i < 26; i++)
            children[i] = nullptr;

    }
    TrieNode* children[26];
    vector<pair<string , int>> wordsRep;
    bool isEnd;
};

bool comp(pair<string, int> a, pair<string, int> b){
    return a.second > b.second;
}

void insert(TrieNode* root, string word, int repeats){
    TrieNode* currNode = root;
    for(int ch = 0; ch < word.length(); ch++){
        if(currNode->children[word[ch] - 'a'] == nullptr){
            TrieNode* newNode = new TrieNode;
            currNode->children[word[ch] - 'a'] = newNode;
        }

        currNode = currNode->children[word[ch] - 'a'];

        if(currNode->wordsRep.empty())
            currNode->wordsRep.push_back({word, repeats});
        else{
            int size = currNode->wordsRep.size();
            bool isPut = false;
            if(size < 5){
                for(int i = 0; i < size; i++){
                    if(currNode->wordsRep[i].first == word){
                        currNode->wordsRep[i].second += repeats;
                        isPut = true;
                        break;
                    }
                }
                if(!isPut)
                    currNode->wordsRep.push_back({word, repeats});
            }
            else if(currNode->wordsRep.size() == 5 && currNode->wordsRep[4].second < repeats){
                currNode->wordsRep.pop_back();
                currNode->wordsRep.push_back({word, repeats});
            }
        }

        for(int i = 0; i < currNode->wordsRep.size(); i++){
            for(int j = i + 1; j < currNode->wordsRep.size(); j++){
                if(currNode->wordsRep[i].second < currNode->wordsRep[j].second){
                    pair<string, int> temp = {currNode->wordsRep[i].first, currNode->wordsRep[i].second};

                    currNode->wordsRep[i].first = currNode->wordsRep[j].first;
                    currNode->wordsRep[i].second = currNode->wordsRep[j].second;

                    currNode->wordsRep[j].first = temp.first;
                    currNode->wordsRep[j].second = temp.second;
                }
                else if(currNode->wordsRep[i].second == currNode->wordsRep[j].second){
                    int k = 0;
                    while(true){
                        if(currNode->wordsRep[i].first[k] > currNode->wordsRep[j].first[k]){
                            pair<string, int> temp = {currNode->wordsRep[i].first, currNode->wordsRep[i].second};

                            currNode->wordsRep[i].first = currNode->wordsRep[j].first;
                            currNode->wordsRep[i].second = currNode->wordsRep[j].second;

                            currNode->wordsRep[j].first = temp.first;
                            currNode->wordsRep[j].second = temp.second;
                            break;
                        }
                        else if(currNode->wordsRep[i].first[k] == currNode->wordsRep[j].first[k])
                            k++;
                        else
                            break;
                    }
                }
            }
        }

    }

    currNode->isEnd = true;
}

void printSuggestions(TrieNode* root, string prefix){
    TrieNode* currNode = root;
    bool isPref = true;
    for(int ch = 0; ch < prefix.length(); ch++){
        if(currNode->children[prefix[ch] - 'a'] != nullptr)
            currNode = currNode->children[prefix[ch] - 'a'];
        else{
            cout << "PREFIX NOT FOUND\n";
            isPref = false;
            break;
        }
    }
    if(isPref){
        for(int i = 0; i < currNode->wordsRep.size(); i++)
            cout << currNode->wordsRep[i].first << endl;
    }

}


int main(){
    int n;
    cin >> n;
    TrieNode* root = new TrieNode;
    for(int i = 0; i < n; i++){
        string query, word;
        int wordCount;
        cin >> query >> word;
        if(query == "insert"){
            cin >> wordCount;
            insert(root, word, wordCount);
        }
        else{
            printSuggestions(root, word);
        }
    }
}