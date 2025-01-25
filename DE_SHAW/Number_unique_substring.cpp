// https://leetcode.com/playground/dSs2FRTP


#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/discuss/interview-question/4308681
int solve(string s) {
    if (s.length() == 1) return 1;
    int mod = 1000000007;
    unordered_map<char, int> map; 
    vector<int> pfix; 
    pfix.emplace_back(1);
    map[s[0]] = 0;
    if (s[1] != s[0]) {
        map[s[1]] = 0;
        pfix.emplace_back(2);
    } else pfix.emplace_back(1);
    for (int i = 2; i < s.length(); i++) {
        const char& c = s[i];
        int sum = 0;
        if (map.find(c) == map.end()) {
            sum = static_cast<int>((static_cast<long long>(pfix[i - 2]) + 1) % mod);
            map[c] = sum - 1;
        } else {
            sum = static_cast<int>((static_cast<long long>(pfix[i - 2]) - map[c]) % mod);
            map[c] = (sum + map[c]) % mod;
        }
        cout << "at " + to_string(i) + " sum: " + to_string(sum) << endl;
        pfix.emplace_back((sum + pfix[i - 1]) % mod) ;
    }
    return pfix.back();
}

int main() {
    // d, e, f, g, de, ed, ee, eg, dg, df, eg, fg, deed,
    cout << solve("ddefegd") << endl;
}



/*

const int M = 1000000007;

int add(int x, int y) {
    if ((x += y) >= M) {
        x -= M;
    }
    return x;
}

int sub(int x, int y) {
    if ((x -= y) < 0) {
        x += M;
    }
    return x;
}

int solution(const string &s) {
    if (s.empty()) return 0;
    const int n = s.length();
    // The number of valid subsequences ending with character s[i] (note the character is s[i]
    // bu the index may be different.
    vector<int> end(n);
    end[0] = 1;
    unordered_map<char, int> last;
    int sum = 1;
    for (int i = 1; i < n; ++i) {
        end[i] = sub(sum, end[i - 1]);
        if (last.count(s[i - 1])) {
            end[i] = add(end[i], end[last[s[i - 1]]]);
        }
        end[i] = add(end[i], 1);
        last[s[i - 1]] = i - 1;
        if (last.count(s[i])) {
            sum = sub(sum, end[last[s[i]]]);
        }
        sum = add(sum, end[i]);  
    }
    return sum;
}


*/