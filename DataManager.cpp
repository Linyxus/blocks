#include "DataManager.hpp"
#include <iostream>
#include <utility>
#include <cstdlib>
#include <ctime>

const int blockHeight = 2;
const int blockWidth = 3;

int Manager::getRandomId() const
{
    int max = this->blockStrs.size();
    int r = rand() % max;
    return r;
}

Field generateBlock(const std::string& str)
{
    Field f(blockHeight, blockWidth);
    for (int i = 0; i < blockHeight; i++) {
        for (int j = 0; j < blockWidth; j++) {
            int x = i * blockWidth + j;
            f[i][j] = str[x] - '0';
        }
    }
    return f;
}

bool isHitted(const BlockPosition& bp, const Field& f, const std::vector<Field>& blockDatas)
{
    Field bf = blockDatas[bp.getIndex()];
    for (int r = 0; r < bf.getR(); r++)
    for (int c = 0; c < bf.getC(); c++)
    if (bf[r][c]) {
        int r1 = r + bf.getR();
        int c1 = c + bf.getC();
        if (f[r1][c1])
            return true;
    }
    return false;
}

bool isOut(const BlockPosition& pos, int r, int c)
{
    int pr = pos.getr(), pc = pos.getc();
    if (pr < 0 || pr >= r) return true;
    else if (pc < 0 || pc >= c) return true;
    return false;
}

void Manager::readBlockFromStrs()
{
    for (std::vector<std::string>::size_type i = 0; i < blockStrs.size(); i++) {
        Field f = generateBlock(blockStrs[i]);
        blockDatas.push_back(f);
    }
}

Manager::Manager(int r, int c)
    : field(r, c)
{
    const std::string strData[] = {"100111", "110110", "000111", "100110", "000110"};
    for (int i = 0; i < 5; i++)
        blockStrs.push_back(strData[i]);
    readBlockFromStrs();
    srand(time(NULL));
    int id = getRandomId();
    currentBlock = BlockPosition(id, 0, c / 2);
    nextBlock = getRandomId();
}

void Manager::switchToNextBlock()
{
    Field f = blockDatas[currentBlock.getIndex()];
    for (int r = 0; r < f.getR(); r++)
    for (int c = 0; c < f.getC(); c++)
    if (f[r][c]) {
        int r1 = r + f.getR();
        int c1 = c + f.getC();
        field[r1][c1] = 1;
    }
    BlockPosition pos(nextBlock, 0, field.getR() / 2);
    currentBlock = pos;
    nextBlock = getRandomId();
}

void Manager::checkClearable()
{
    for (int r = 0; r < field.getR(); r++) {
        bool clearable = true;
        for (int c = 0; c < field.getC(); c++) {
            if (field[r][c] == 0)
                clearable = false;
        }
        if (clearable) {
            if (r == 0) {
                for (int c = 0; c < field.getC(); c++)
                    field[r][c] = 0;
            }
            for (int rr = r; rr >= 1; rr--) {
                for (int c = 0; c < field.getC(); c++)
                    field[rr][c] = field[rr - 1][c];
            }
        }
    }
}

bool Manager::update()
{
    BlockPosition newPos = this->currentBlock;
    newPos.moveDown();
    if (isOut(newPos, field.getR(), field.getC()) || isHitted(newPos, field, blockDatas)) { //on hit
        switchToNextBlock();
        checkClearable();
        if (isHitted(currentBlock, field, blockDatas))
            return false;
    }
    else { //on move
        currentBlock.moveDown();
    }
    return true;
}
