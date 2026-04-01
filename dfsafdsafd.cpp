#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

















string phenoFromGeno(string g) {
    sort(g.begin(), g.end());
    if (g == "AA" || g == "AO") return "A";
    if (g == "BB" || g == "BO") return "B";
    if (g == "AB") return "AB";
    if (g == "OO") return "O";
    return "";
}

vector<string> genoFromPheno(string p) {
    if (p == "A") return {"AA", "AO"};
    if (p == "B") return {"BB", "BO"};
    if (p == "AB") return {"AB"};
    if (p == "O") return {"OO"};
    return {};
}

vector<vector<string>> solve(string p1, string p2, string c) {
    auto g1s = genoFromPheno(p1);
    auto g2s = genoFromPheno(p2);
    vector<vector<string>> ans;

    for (auto &g1 : g1s) {
        for (auto &g2 : g2s) {
            bool ok = false;
            for (char a : g1) {
                for (char b : g2) {
                    string t;
                    t += a;
                    t += b;
                    if (phenoFromGeno(t) == c) {
                        ok = true;
                        break;
                    }
                }
                if (ok) break;
            }
            if (ok) ans.push_back({g1, g2});
        }
    }

    if (ans.empty()) return {{"--", "--"}};

    sort(ans.begin(), ans.end());
    return ans;
}


















int main() {
    auto r1 = solve("AB", "A", "A");
    for (auto &p : r1) cout << "[" << p[0] << ", " << p[1] << "] ";
    cout << endl;

    auto r2 = solve("O", "AB", "O");
    for (auto &p : r2) cout << "[" << p[0] << ", " << p[1] << "] ";
    cout << endl;

    return 0;
}
