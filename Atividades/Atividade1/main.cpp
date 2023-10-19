// Atividade 1 (prática): Dado um conjunto de intervalos, determinar a quantidade de intervalos distintos. Supondo os intervalos: (1,3), (2,5) e (7,9) o output esperado seria 2, uma vez que existem 2 conjuntos que são (1,5) e (7,9)
// Input exemplo: (1,3),(4,7),(2,5),(6,8)
//(1,3),(7,9),(2,5)
// Output exemplo: 1
// 2

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define pf push_front
#define x first
#define y second
#define endl "\n"
#define all(a) (a).begin(), (a).end()
const int INF = 0x3f3f3f3f;

void processIntervals() {
    ifstream input("input.txt");
    ofstream output("output.txt");
    string line;
    while (getline(input, line)) {
        int i = 0;
        vector<pair<int, int>> intervals;
        while (i < line.size()) {
            int a = 0, b = 0;
            while (line[i] != '(') i++;
            i++;
            while (line[i] != ',') {
                a = a * 10 + (line[i] - '0');
                i++;
            }
            i++;
            while (line[i] != ')') {
                b = b * 10 + (line[i] - '0');
                i++;
            }
            intervals.pb({a, b});
            i++;
        }
        sort(all(intervals));
        int ans = 1;
        int last = intervals[0].y;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].x > last) {
                ans++;
                last = intervals[i].y;
            } else {
                last = max(last, intervals[i].y);
            }
        }
        output << ans << endl;
    }
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    processIntervals();

    return 0;
}
