#ifndef FIELD_H__
#define FIELD_H__

#include <vector>
using namespace std;

class Field //Field[r][c]
{
public:
    typedef vector<int> DataRow;
    typedef vector<DataRow> DataType;

    Field(int r = 0, int c = 0);
    const DataRow& operator[](const int& index) const;
    DataRow& operator[](const int& index);
    int getR() const { return r; }
    int getC() const { return c; }
private:
    DataType data;
    int r;
    int c;
};

#endif
