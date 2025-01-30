class median
{
    multiset<int>a,b;
    int s1 = 0 ;
    int s2 = 0 ;

    void balance()
    {
        if(a.size()==b.size())
            return ;
        if(a.size() < b.size())
        {
            auto f = *b.begin();
            b.erase(b.begin());
            a.insert(f);
            s1 += f ;
            s2 -= f ;
        }
        else if( a.size() > b.size() + 1 )
        {
            auto f = *a.rbegin();
            a.erase(a.find(f));
            b.insert(f);

            s2 += f ;
            s1 -= f ;
        }
    }

public:
    median(){};

    void add(int x )
    {

        if( a.size() == 0 || x <= (*a.rbegin()) ){
            s1 += x ;
            a.insert(x);
        }
        else{
            s2 += x ;
            b.insert(x);
        }
        balance();
    }

    void remove( int x )
    {
        if(a.find(x)!=a.end()){
            a.erase(a.find(x));
            s1 -= x ;
        }
        else if(b.find(x) != b.end()){
            b.erase(b.find(x));
            s2 -= x ;
        }

        balance();
    }

    int get()
    {
        int m = *a.rbegin();

        int A = (a.size()*m) - s1 ;
        int B = (s2) - (b.size()*m) ;

        return A + B ;
    }
};