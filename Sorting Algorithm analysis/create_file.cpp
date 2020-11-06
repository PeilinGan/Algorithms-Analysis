#include "project2.h"


void create_csv_file(string filename)
{
    ofstream f;
    f.open(filename, ios::trunc);
    f << "n,waste\n";
    f.close();
}

void add_waste_to_file(int size,double waste, string filename)
{
    ofstream f;
    f.open(filename, ios::app);
    f << size << "," << waste << "\n";
    f.close();
}