// Atividade 2 (prática): Será fornecido sequências de dois números, referente a quantidade de ocorrência de um determinado caractere numa palavra. Os caracteres serão respectivamente 'a' e 'b'. O candidato deve retornar se possível um sequência de caracteres que use todos os caracteres e que não não tenha mais que dois caracteres repetidos juntos
// Input exemplo: 
// 36
// 57
// Output exemplo:
// bbabbabba
// bbababababab

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

void charSequence() {

    ifstream input("input.txt");
    ofstream output("output.txt");
    string line;
    while (getline(input, line)) {
        int a, b;
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == ' ') {
                a = stoi(line.substr(0, i));
                b = stoi(line.substr(i + 1, line.size() - i));
                break;
            }
        }
        int total = a + b;
        if (a > b) {
            if (a > 2 * b + 2) {
                output << "Not possible" << endl;
                continue;
            }
        } else {
            if (b > 2 * a + 2) {
                output << "Not possible" << endl;
                continue;
            }
        }
        string ans = "";
        while(total > 0){
            if(a > b){
                if(a > 1){
                    ans += "aa";
                    a -= 2;
                    total -= 2;
                } else {
                    ans += "a";
                    a -= 1;
                    total -= 1;
                }
                if(b > 0){
                    ans += "b";
                    b -= 1;
                    total -= 1;
                }
            } else if(b > a) {
                if(b > 1){
                    ans += "bb";
                    b -= 2;
                    total -= 2;
                } else {
                    ans += "b";
                    b -= 1;
                    total -= 1;
                }
                if(a > 0){
                    ans += "a";
                    a -= 1;
                    total -= 1;
                }
            } else if(a == b){
                if(a > 0){
                    ans += "ab";
                    a -= 1;
                    b -= 1;
                    total -= 2;
                }
            } else if(a == 0){
                ans += "b";
                b -= 1;
                total -= 1;
            } else if(b == 0){
                ans += "a";
                a -= 1;
                total -= 1;
            }
        }
        output << ans << endl;
    }

}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    charSequence();

    return 0;
}
