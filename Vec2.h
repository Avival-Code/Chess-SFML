#pragma once
#include <iostream>

template<typename T>
class Vec2
{
public:
    Vec2() = default;
    Vec2( T x_in, T y_in )
        :
        x( x_in ),
        y( y_in )
    {
    }
    Vec2( const Vec2<T>& rhs )
        :
        Vec2( rhs.x, rhs.y )
    {
    }
    Vec2& operator=( const Vec2<T>& rhs )
    {
        x = rhs.x;
        y = rhs.y;
        return *this;
    }
    Vec2& operator+( const Vec2<T>& rhs )
    {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    Vec2 operator+=( const Vec2<T>& rhs )
    {
        return *this + rhs;
    }
    Vec2& operator-( const Vec2<T>& rhs )
    {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    Vec2 operator-=( const Vec2<T>& rhs )
    {
        return *this - rhs;
    }
    Vec2& operator*( const Vec2<T>& rhs )
    {
        x *= rhs.x;
        y *= rhs.y;
        return *this;
    }
    Vec2 operator*=( const Vec2<T>& rhs )
    {
        return *this * rhs;
    }
    bool operator==( const Vec2<T>& rhs)
    {
        if( x == rhs.x && y == rhs.y)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void print() //Just testing vector functionality. Delete when unnecessary.
    {
        std::cout << x << std::endl;
        std::cout << y << std::endl;
    }
    Vec2<int> getVei2()
    {
        return Vec2<int>( int(x), int(y) );
    }

public:
    T x;
    T y;
};

typedef Vec2<float> Vef2;
typedef Vec2<int> Vei2;
