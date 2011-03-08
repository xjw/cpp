#include <iostream>
#include <set>
#include <string>

using namespace std;

const int M=2;
const int N=2;

bool visited[M][N];
set<string> s;

void print_boggle_words(char a[M][N], int x, int y, string word) {
    if (x>=M || y>=N || visited[x][y]) return;

    if (s.find(word) != s.end()) cout<< word << endl;

    visited[x][y] = true;

    string new_word = word + a[x][y];
    print_boggle_words(a, x, y+1, new_word);
    print_boggle_words(a, x, y-1, new_word);
    print_boggle_words(a, x+1, y, new_word);
    print_boggle_words(a, x+1, y+1, new_word);
    print_boggle_words(a, x+1, y-1, new_word);
    print_boggle_words(a, x-1, y, new_word);
    print_boggle_words(a, x-1, y+1, new_word);
    print_boggle_words(a, x-1, y-1, new_word);

    visited[x][y] = false;
}

int main() {
    char a[M][N] = {
        't', 's',
        'e', 'd',
    };
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            visited[i][j] = false;
        }
    }
    s.insert("sed");
    s.insert("ted");
    s.insert("test");

    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            print_boggle_words(a, i, j, "");
        }
    }
    return 1;
}
