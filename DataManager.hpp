#ifndef DATAMANAGER_HPP__
#define DATAMANAGER_HPP__

#include "Field.hpp"
#include "BlockPosition.hpp"
#include <string>
#include <vector>

Field generateBlock(const std::string& str);
bool isHitted(const BlockPosition&, const Field&, const std::vector<Field>&);
bool isOut(const BlockPosition&, int, int);

class Manager
{
public:
    Manager(int r = 20, int c = 10);
    int getRandomId() const;
    bool update();
    void switchToNextBlock();
    void checkClearable();
    const Field& getField() const { return field; }
private:
    Field field;
    void readBlockFromStrs();
    vector<Field> blockDatas;
    BlockPosition currentBlock;
    int nextBlock;
    std::vector<std::string> blockStrs;
};

#endif
