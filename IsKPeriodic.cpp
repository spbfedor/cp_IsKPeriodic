#include <iostream>
#include <string>

bool IsKPeriodic(std::string str, int k) {
    if(str.size() < 2) {
        return false;
    }

    int j = 0;
    int* lps = new int[str.size()];
    lps[0] = 0;
    int i = 1;

    while(i < str.size()) {
        if(str[i] == str[j]) {
            ++j;
            lps[i] = j;
            if(lps[i] == k) {
                return true;
            }
            ++i;
        } else {
            if(j != 0) {
                j = lps[j - 1];
            } else {
                lps[i] = 0;
                ++i;
            }
        }
    }
    return false;
}
