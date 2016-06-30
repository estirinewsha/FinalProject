#ifndef BUILDING_H
#define BUILDING_H


class Building
{
    public:
        int num;
        int x;
        int y;
        int type;
        void add(int t);
        void getCoor(int x,int y);
        void gettype(int t);
    protected:
    private:
};

class Castel:public Building{
	bool life;
	 void add(int t);
};

class Barracks:public Building{
public:
	 void add(int t);
};

class Treasury:public Building{
public:
	 void add(int t);

};

#endif // BUILDING_H
