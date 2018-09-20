#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

bool stat[26];

inline char t(const string& original) {
    return original[0] - 'a';
}

inline bool isInt(const string& str) {
    return str[0] >= '0' && str[0] <= '9';
}

inline int getPV(const string& str) {
    if(isInt(str)) 
        return atoi(str.c_str());
    else
        return 1000000;
}

struct stackContent {
    int complexity;
    char var;
    bool parentEntryImpossible;
};

int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n; i++) {
        memset(stat, 0, sizeof(stat));

        int lineCnt, expectedComplexity;
        cin >> lineCnt;

        string complexity;
        cin >> complexity;

        if(complexity[2] == '1')
            expectedComplexity = 0;
        else
            sscanf(complexity.c_str(), "O(n^%d)", &expectedComplexity);

        string currentToken, last_t_A; 
        bool validFlag = true;

        int currentComplexity = 0, maxComplexity = 0;
        bool parentEntryImpossible = false;
        stack<stackContent> complexityStack;
        for(int j=1; j<=lineCnt; j++) {
            cin >> currentToken;
            if(currentToken == "F") {
                string t_A, t_B, t_C;
                cin >> t_A >> t_B >> t_C;
                if(!validFlag) continue;

                if(stat[t(t_A)]) {
                    validFlag = false;
                    continue;
                }

                complexityStack.push((stackContent){currentComplexity, t_A[0], parentEntryImpossible});

                if(parentEntryImpossible)
                    parentEntryImpossible = true;
                else if(getPV(t_B) > getPV(t_C))
                    parentEntryImpossible = true;
                else if(t_B != "n" && t_C == "n") {
                    currentComplexity++;
                    maxComplexity = max(maxComplexity, currentComplexity);
                }
                
                stat[t(t_A)] = true;
            } else if(currentToken == "E") {
                if(!validFlag) continue;

                if(complexityStack.size() == 0) {
                    validFlag = false;
                    continue;
                }

                currentComplexity = complexityStack.top().complexity;
                stat[complexityStack.top().var - 'a'] = false;
                parentEntryImpossible = complexityStack.top().parentEntryImpossible;
                complexityStack.pop();
            }
        }

        if(!validFlag || complexityStack.size() != 0)
            cout << "ERR" << endl;
        else {
            if(maxComplexity == expectedComplexity) 
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }

    return 0;
}