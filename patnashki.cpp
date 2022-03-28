#include "patnashki.h"
#include <QRandomGenerator>

Patnashki::Patnashki()
{
    startGame();
}

void Patnashki::startGame()
{
    movCount=0;

    int r=1;
    for(int i = 0;i<4;i++)
    {
        for(int j = 0;j<4;j++)
        {
             winTable[i][j]=r;
             r++;
        }
    }
    winTable[3][3] = 0;
    for (auto i = 0;i<4;i++)
        for(auto j=0;j<4;j++)
            table[i][j]=-1;
    QRandomGenerator *rnd = QRandomGenerator::global();
    do{
        for(int k=0; k<16;)
        {
            bool alreadyThere = 0;
            int newRandom = rnd->bounded(0,16);
            for(int l = 0;l<4;l++)
            {
                for(int p =0;p<4;p++)
                {
                    if(table[l][p]==newRandom)
                    {
                        alreadyThere=1;
                        break;
                    }
                }
            }
            if(!alreadyThere)
            {
                table[k/4][k%4]=newRandom;
                cpyTable[k/4][k%4]=table[k/4][k%4];
                k++;
            }
        }
    }while(isFinished());
}

bool Patnashki::isFinished()
{
    bool n = 1;
    for (auto i = 0;i<4;i++)
    {
        for(auto j = 0;j<4;j++)
        {
            if(table[i][j]!=winTable[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void Patnashki::reCalc(int z,int x)
{
    if(table[z][x-1]==0&&x>0)
    {
        table[z][x-1]=table[z][x];
        table[z][x]=0;
        movCount++;
    }
    else if(table[z][x+1]==0&&x<3)
    {
        table[z][x+1]=table[z][x];
        table[z][x]=0;
        movCount++;
    }
    else if(table[z+1][x]==0&&z<3)
    {
        table[z+1][x]=table[z][x];
        table[z][x]=0;
        movCount++;
    }
    else if(table[z-1][x]==0&&z>0)
    {
        table[z-1][x]=table[z][x];
        table[z][x]=0;
        movCount++;
    }
}

int Patnashki::getMovCount()
{
    return movCount;
}

void Patnashki::restartGame()
{
    movCount=0;
    for (auto i = 0;i<4;i++)
        for(auto j=0;j<4;j++){
            table[i][j] = cpyTable[i][j];
        }
}

bool Patnashki::isUnCreate()
{
    int a = 0;
    int k = 0;
    int arr[15];
    for(int x = 0;x<4;x++)
    {
        for(int z = 0;z<4;z++)
        {
            if(table[z][x]!=0)
            {
                arr[k]=table[z][x];
                k++;
            }
            else
            {
                a+=x;
            }
        }
    }
    for(int i=0;i<15;i++)
    {

            for(int l = i;l<15;l++)
            {
                if(arr[i]>arr[l])
                {
                    a++;
                }
             }

     }
    if(a%2 == 1)
        return true;
    else
        return false;

}

int Patnashki:: getItem(int i, int j) const
{
    return table[i][j];
}
