#ifndef LANDOWNERV3_H
#define LANDOWNERV3_H


class LandOwnerV3
{
    public:
        LandOwnerV3();
        virtual ~LandOwnerV3();

        long Get_score() {return _score;}
        void Setscore(long val)
        {
             if(val < 0) _score = 0;
                         _score = val;
        }
        //string Getname() { return _name; }
        //void Setname(string val) { _name = val; }
        //int Getcard[20]() { return card[20]; }
        //void Setcard[20](int val) { card[20] = val; }

    protected:

    private:
        long _score;//һ���˽�б���ǰ���һ���»���
        //string _name;
        int card[20];
};

#endif // LANDOWNERV3_H
