#include <iostream>
#include <fstream>

using namespace std;

class Fraction
{
private:
    int m_numerator = 0;
    int m_denominator = 1;

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator)
    {
    }

    friend ostream& operator<<(ostream& out, const Fraction& f1)
    {
        out << f1.m_numerator << "/" << f1.m_denominator;
        return out;
    }

    friend istream& operator>>(istream& in, Fraction& f1)
    {
        in >> f1.m_numerator;
        in.ignore(1);
        in >> f1.m_denominator;
        return in;
    }

    void writeFile(ofstream& out)
    {
        out.write((char*)&m_numerator, sizeof(m_numerator));
        out.write((char*)&m_denominator, sizeof(m_denominator));
    }

    void readFile(ifstream& in)
    {
        in.read((char*)&m_numerator, sizeof(m_numerator));
        in.read((char*)&m_denominator, sizeof(m_denominator));
    }
};

int main()
{
    //Task 1
    /*Fraction fractions[4] = {
        Fraction(1, 2),
        Fraction(3, 4),
        Fraction(5, 6),
        Fraction(7, 8)
    };

    ofstream outFile("fraction.bin", ios::binary);
    for (int i = 0; i < 4; ++i)
    {
        fractions[i].writeFile(outFile);
    }
    outFile.close();

    Fraction readFractions[4];

    ifstream inFile("fraction.bin", ios::binary);
    for (int i = 0; i < 4; ++i)
    {
        readFractions[i].readFile(inFile);
    }
    inFile.close();

    for (const auto& fraction : readFractions)
    {
        cout << fraction << endl;
    }*/


    //task 2
    Fraction fractions[4] = {
        Fraction(1, 2),
        Fraction(3, 4),
        Fraction(5, 6),
        Fraction(7, 8)
    };

    ofstream outFile("fraction.bin", ios::binary);
    for (int i = 0; i < 4; ++i)
    {
        fractions[i].writeFile(outFile);
    }
    outFile.close();

    Fraction readFractions[4];

    ifstream inFile("fraction.bin", ios::binary);
    for (int i = 0; i < 4; ++i)
    {
        readFractions[i].readFile(inFile);
    }
    inFile.close();

    for (const auto& fraction : readFractions)
    {
        cout << fraction << endl;
    }
}
