//class Field
#include "Field.hpp"

Field::Field(int r, int c)
{
    for (int i = 0; i < r; i++) {
        data.push_back(Field::DataRow(c));
    }
    this->r = r;
    this->c = c;
}

const Field::DataRow& Field::operator[](const int& index) const
{
    return data[index];
}

Field::DataRow& Field::operator[](const int& index)
{
    return data[index];
}
