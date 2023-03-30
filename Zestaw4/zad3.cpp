#include <iostream>
#include <cstring>

using namespace std;

class TArr
{
private:
    struct InnerArray
    {
        size_t len{0};
        size_t ref{0};
        int *buf{nullptr};
    } * ptr{nullptr};
    

public:
    TArr()
    {
        ptr = new InnerArray;
        ptr->ref = 1;
        ptr->len = 0;
        ptr->buf = 0;
    }

    TArr(const TArr &src)
    {
        src.ptr->ref++;
        this->ptr = src.ptr;
    }

    TArr &operator=(const TArr &src)
    {
        if (this == &src)
            return *this;
        src.ptr->ref++;
        if (--ptr->ref == 0)
        {
            delete[] ptr->buf;
            delete ptr;
        }
        this->ptr = src.ptr;
        return *this;
    }

    TArr to_lower()
    {
        int *p;
        if (ptr->ref > 1)
        {

            unsigned lenght = ptr->len;
            p = new int[lenght + 1];
            ptr->ref--;
            ptr = new InnerArray;
            ptr->ref = 1;
            ptr->len = lenght;
            ptr->buf = p;
        }
        return *this;
    }

    ~TArr()
    {
        if (--ptr->ref == 0)
        {
            delete[] ptr->buf;
            delete ptr;
        }
    }
};
