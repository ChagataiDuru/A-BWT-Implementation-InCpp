//
// Created by duruc on 1/10/2023.
//

#include "bwt.h"

void bwt::sortBubble(vector<pair<string, int>>& a, int l, int r) {
    for (int i = l; i < r; i++) {
        for (int j = l; j < r - i - 1; j++) {
            if (a[j].first > a[j + 1].first) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

void bwt::sortBubble(vector<pair<char, int>>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j].first > a[j + 1].first) {
                swap(a[j], a[j + 1]);
            }
        }
    }
}


void bwt::encodeBwt(string input_file, string output_file) {

    ifstream input(input_file, ios::in);
    ofstream output(output_file, ios::out);
    stringstream buffer;
    if (input.is_open())
    {
        buffer << input.rdbuf();
        string t = buffer.str();
        int n = t.size();
        t += "$";
        vector<pair<string, int>> a(n + 1);
        for (int i = 0; i <= n; i++) {
            a[i] = {t.substr(i) + t.substr(0, i), i};
        }
        sortBubble(a, 0, n+1);
        string res;
        for (int i = 0; i <= n; i++) {
            res += a[i].first[n];
        }
        output << res;
    }
    else
    {
        cout << "Unable to open file" << '\n';
        ::exit(-1);
    }
    input.close();
    output.close();
}


void bwt::decodeBwt(string input_file, string output_file) {
    ifstream input(input_file, ios::in);
    ofstream output(output_file, ios::out);
    stringstream buffer;
    if (input.is_open())
    {
        string line;
        while (getline(input, line)) {
            buffer << line << '\n';
        }
        string t = buffer.str();
        int n = t.size();
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {t[i], i};
        }
        sortBubble(a);
        string res;
        for (int i = 0, j = a[0].second; i < n; i++, j = a[j].second) {
            if (t[j] == '$') {
                break;
            }
            res += t[j];
        }
        output << res;
    }
    else
    {
        cout << "Unable to open file" << '\n';
        ::exit(-1);
    }
    input.close();
    output.close();
}

bwt::~bwt() = default;

bwt::bwt() = default;

int mainx() {
    bwt *algorithm = new bwt();
    string file_name;
    cin >> file_name;
    ifstream file(file_name);
    if (!file.is_open()) {
        cout << "File not found" << endl;
        return 1;
    }
    string s((istreambuf_iterator<char>(file)),
             istreambuf_iterator<char>());
    //string encoded = algorithm->encodeBwt(s);
    //cout << "Encoded String: " << encoded << endl;

    //string decoded = algorithm->decodeBwt(encoded);
    //cout << "Decoded String: " << decoded << endl;
    return 0;
}