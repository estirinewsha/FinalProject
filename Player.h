#ifndef PLAYER_H
#define PLAYER_H
#include"vector"
#include"Building.h"
//using namespace std;
class Player
{
    public:
        int soldiernum;
        int coinnum;
        std::vector <Building> bld;
        //std::vector <Soldier> sld;
        Player();
        virtual ~Player();
        void getType(int i);
        bool addnew(int x,int y,int type);
        //void addnewsoldier(int x,int y);
	void addCoor(int x,int y,int i);
    protected:
    private:
};

#endif // PLAYER_H
