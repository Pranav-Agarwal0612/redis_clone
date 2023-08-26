#include <iostream>
#include <vector>
#include <string>

class Some
{
public:
    long long x;
    char y;
    std::pair<char, std::string> z;
    char* a;

    Some(int _x, char _y, std::pair<char, std::string> _z, char* _a) : x(_x), y(_y), z(_z), a(_a)
    {
    }

    void print()
    {
        std::cout << x << " " << y << " " << z.first << " " << z.second << " " << *a << " " << this << std::endl;
    }
};

int main()
{
    char bb = 'p';
    Some x = Some(10, 'a', {'z', "fuck"}, &bb);

    std::vector<Some> y;
    y.push_back(x);

    *x.a = 'u';

    // std::cout << &x << std::endl;

    x.x = 12;
    x.y = 'q';
    x.z.second = "yokdjshfkjsfhlkjafhlkajdsflaksfjlakfj;lkasfjl;aksfj;lkasfj;laksdfj;laskdfjl;sakdfjasldkfu";

    // std::cout << &x << " " << sizeof(x) << std::endl;
    // std::cout << &(y[1]) << std::endl;

    x.print();

    for (auto &z : y)
    {
        z.print();
    }

    return 0;
}
