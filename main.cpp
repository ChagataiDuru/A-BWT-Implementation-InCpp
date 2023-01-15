#include <cstring>
#include "bwt.h"

bool compareFileText(string &arg);
bool compareFileName(string &arg);
void infoText();
//DOĞRU ENCODELUYO ILK SATIRI YIYOR ANLAMADIM
int main(int argc, char **argv)
{
    if (argc < 3)
    {
        infoText();
        return 0;
    }
    bwt *algorithm = new bwt();
    string inputFile = argv[2];
    string outputFile = argv[3];

    bool compress = (strcmp(argv[1], "c") == 0);
    bool decompress = (strcmp(argv[1], "d") == 0);

    if (!compress && !decompress)
    {
        cout << "Please enter correct arguments" << '\n';
        infoText();
        return 0;
    }

    if (compress)
    {
        bool inputIsText = compareFileText(inputFile);
        bool outputIsLzw = compareFileName(outputFile);
        if (!inputIsText || !outputIsLzw)
        {
            infoText();
            return 0;
        }
        algorithm->encodeBwt(inputFile,outputFile);
        cout << "Successfully compressed"<< "\n";
    }
    else if (decompress)
    {
        bool inputIsLzw = compareFileName(inputFile);
        bool outputIsText = compareFileText(outputFile);
        if (!inputIsLzw || !outputIsText)
        {
            infoText();
            return 0;
        }
        algorithm->decodeBwt(inputFile,outputFile);
        cout << "Successfully decompressed" << "\n";
    }
}

bool compareFileText(string &arg)
{
    if (arg.find(".txt") != string::npos)
    {
        return true;
    }
    cout << "You need to enter .txt file for input or output file for more info:" << endl;
    return false;
}

bool compareFileName(string &arg)
{
    if (arg.find(".bwt") != string::npos)
    {
        return true;
    }
    cout << "You need to enter .bwt file for input or output file for more info:" << endl;
    return false;
}

void infoText()
{
    const string infoText(
        "Usage:\n"
        "    bwt c (<input_filename> <output_filename>)\n"
        "    bwt d (<input_filename> <output_filename>)\n"
        "    bwt \n"
        "    Options:"
        "                                                \n"
        "    without argument           \tShow this screen.\n"
        "    c                          \tCompress .txt file to .bwt format.\n"
        "    d                          \tdecompress the .bwt file to a .txt file.");
    cout << infoText << endl;
}
