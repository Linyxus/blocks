#ifndef BLOCK_POSITION_HPP__
#define BLOCK_POSITION_HPP__

/*
    BlockPosition
    A record of the position of the block.
    Tip: It is not related to Field to which it belongs.
*/

class BlockPosition
{
public:
    BlockPosition(int id = 0, int r = 0, int c = 0) : r(r), c(c) { }
    int getr() const { return r; }
    int getc() const { return c; }
    void setr(int nr) { r = nr; }
    void setc(int nc) { c = nc; }
    void setrc(int nr, int nc) { setr(nr); setc(nc); }
    void moveDown() { r--; }
    void moveLeft() { c--; }
    void moveRight() { c++; }
    int getIndex() const { return index; }
    void setIndex(int i) { index = i; }
private:
    int r;
    int c;
    int index;
};

#endif
