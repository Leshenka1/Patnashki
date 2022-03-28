#ifndef PATNASHKI_H
#define PATNASHKI_H


class Patnashki
{
public:
    Patnashki();
    void startGame();
    void restartGame();
    bool isFinished();
    int getItem(int i, int j) const;
    void reCalc(int z,int x);
    bool isUnCreate();
    int getMovCount();

private:
    int movCount;
    int table[4][4];
    int cpyTable[4][4];
    int winTable[4][4];
    int randomNum();
};

#endif // PATNASHKI_H
