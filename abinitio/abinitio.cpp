#include <iostream>
#include <string>
#include <bitset>
#include <array>
#include <cmath>
#include <unordered_map>



using namespace std;

#define MATRIXSIZE 1000

int v, e, q;
auto adj_matrix = new array<bitset<MATRIXSIZE>, MATRIXSIZE>; // Make this a pointer if we have problems

void inline init_graph(int vertices) {
    return;
}

void inline add_edge(int a, int b) {
    (*adj_matrix)[a][b] = true;
}

void inline add_vertice() {
    for (int i = 0; i < v; i++) {
        (*adj_matrix)[i][v] = false; // Clean the spot in all arrays, as it might have been set already.
    }
    v++;
}

void inline remove_all_edges(int a) {
    (*adj_matrix)[a].reset();
    int i;
    for (i = 0; i < a; i++) {
        (*adj_matrix)[i][a] = false;
    }
    for (i = a + 1; i < v; i++) {
        (*adj_matrix)[i][a] = false;
    }
}

void inline remove_edge(int a, int b) {
    (*adj_matrix)[a][b] = false;
}

void inline transpose() {
    auto *adj_matrix_transpose = new array<bitset<MATRIXSIZE>, MATRIXSIZE>;
    for (int a = 0; a < v; a++) {
        for (int b = 0; b < v; b++) {
            (*adj_matrix_transpose)[a][b] = (*adj_matrix)[b][a];
        }
    }
    adj_matrix = adj_matrix_transpose;
}

void inline complement() {
    for (int i = 0; i < v; i++) {
        (*adj_matrix)[i].flip();
    }
    return;
}

#define MODULOANSWER 1000000007ULL

unsigned long long hash_values[MATRIXSIZE];

long inline hash_of(int a) {
    long long unsigned result = 0;
    long long unsigned count = 0;
    for (long i = 0; i < v; i++) {
        if ((*adj_matrix)[a][i]) {
            result += hash_values[count++] * i;
            result = result % MODULOANSWER;
        }
    }
    return result % MODULOANSWER;
}

void inline pre_compute_hash_values() {
    long long unsigned res = 1;
    for (int i = 0; i < v; i++) {
        hash_values[i] = res;
        res = res * 7;
        while (res > MODULOANSWER) res -= MODULOANSWER;
    }
}

void inline clean_matrix() {
    bitset<MATRIXSIZE> pattern(string(MATRIXSIZE - v, '0') + string(v, '1'));
    for (int i = 0; i < v; i++) {
        (*adj_matrix)[i] &= pattern;
        (*adj_matrix)[i][i] = false;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e >> q;
    init_graph(v);
    int a, b;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        add_edge(a, b);
    }
    int query;
    int x, y;
    for (int i = 0; i < q; i++) {
        cin >> query;
        switch (query) {
        case 1:
            add_vertice();
            break;
        case 2:
            cin >> x >> y;
            add_edge(x, y);
            break;
        case 3:
            cin >> x;
            remove_all_edges(x);
            break;
        case 4:
            cin >> x >> y;
            remove_edge(x, y);
            break;
        case 5:
            transpose();
            break;
        case 6:
            complement();
            //Remember to skip a == b
            break;
        }
    }
    clean_matrix();
    pre_compute_hash_values();
    cout << v << "\n";
    //hash_of(0);
    for (int i = 0; i < v; i++) {
        cout << (*adj_matrix)[i].count() << " " << hash_of(i) << "\n";
    }
}