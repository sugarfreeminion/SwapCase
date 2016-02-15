#include <iostream>
#include <fstream>

using namespace std;

const int A = 65;
const int Z = 90;
const int a = 97;
const int z = 122;

bool IsAlpha(char val)
{
    bool isAlpha = false;

    if((val >= A && val <= Z) ||
       (val >= a && val <= z))
    {
        isAlpha = true;
    }
    else
    {
        isAlpha = false;
    }

    return isAlpha;
}

bool IsLower(char val)
{
    bool isLower = false;

    if(val >= a && val <= z)
    {
        isLower = true;
    }
    else
    {
        isLower = false;
    }

    return isLower;
}

void CaseChange(string &data)
{
    unsigned int index = 0;

    while(index < data.size())
    {
        if(IsAlpha(data[index]) == true)
        {
            if(IsLower(data[index]) == true)
            {
                data[index] = data[index] - 32;
            }
            else
            {
                data[index] = data[index] + 32;
            }
        }
        ++index;
    }
}

int main(int argc, char *argv[])
{
    ifstream inputFile;

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        string data;

        while(getline(inputFile,data))
        {
            //cout << data << endl;

            CaseChange(data);

            cout << data << endl;
        }

        inputFile.close();
    }

    return 0;
}
