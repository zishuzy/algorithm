#include <string>
#include <vector>
#include <iostream>

using namespace std;

void buildPMT(const string &pattern, vector<int> &pmt)
{
    pmt[0] = 0;
    int len = 0;
    for (size_t i = 1; i < pattern.size(); i++) {
        while (len > 0 && pattern[i] != pattern[len]) {
            len = pmt[len - 1];
        }
        if (pattern[i] == pattern[len]) {
            len++;
        }
        pmt[i] = len;
    }
}

int strStr(string text, string pattern)
{
    int m = text.size();
    int n = pattern.size();
    vector<int> pmt(n, 0);

    buildPMT(pattern, pmt);

    for (size_t i = 0, j = 0; i < m; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pmt[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == n) {
            return i - n + 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    string text = "ababcabcabababd";
    string pattern = "ababd";

    int pos = strStr(text, pattern);

    cout << "text: " << text << endl;
    cout << "pattern: " << pattern << endl;
    cout << "pos: " << pos << endl;

    return 0;
}
