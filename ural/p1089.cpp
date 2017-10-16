#include <iostream>
#include <vector>
#include <string>
#define rep(i,j,k) for(i=j;i<k;++i)
using namespace std;

inline void nextAlphabet(const string &str, int &i) {
    while (i < str.length() && (str[i] < 'a' || str[i] > 'z'))
        ++i;
}

// returns the end index of current word, excluded.
inline int skimWord(const string &str, int from) {
    while (from < str.length() && str[from] >= 'a' && str[from] <= 'z')
        ++from;
    return from;
}

int main() {
    vector<string> vocabulary;

    // read vocabulary.
    string line;
    while (true) {
        getline(cin, line);
        if (line == "#") break;
        else vocabulary.push_back(line);
    }

    // read text, since lines can be merged.
    string text = "";
    int ans = 0, i = 0, j, k;
    while (getline(cin, line)) text += line + '\n';

    // for each words in the text, check the minimum distance to a word in vocabulary and correct them.
    while (true) {
        nextAlphabet(text, i);
        // no more words
        if (i >= text.length()) break;

        int to = skimWord(text, i);
        string word = text.substr(i, to - i);

        // search the vocabulary
        rep(j,0,vocabulary.size()) {
            string correct = vocabulary[j];
            if (correct.length() == word.length()) {
                int d = -1;
                rep(k,0,word.length())
                    if (vocabulary[j][k] != word[k]) {
                        if (d == -1)
                            d = k;
                        else {
                            d = -1;
                            break;
                        }
                    }
                if (d != -1) {
                    ++ans;
                    text[i + d] = correct[d];
                    break;
                }
            }
        }
        i = to;
    }
    cout << text << ans << endl;
    return 0;
}