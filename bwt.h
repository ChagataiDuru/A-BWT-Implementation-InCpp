//
// Created by chagataikhan on 1/12/23.
//

#ifndef HW6_BWT_H
#define HW6_BWT_H
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>


using namespace std;
class bwt{
public:
    bwt();
    ~bwt();
    void decodeBwt(string input_file, string output_file);
    void encodeBwt(string input_file, string output_file);

private:
    void sortBubble(vector<pair<char, int>>& a);
    void sortBubble(vector<pair<string, int>>& a, int l, int r);

};


#endif //HW6_BWT_H
