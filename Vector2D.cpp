#include <iostream>

using namespace std;

class Vector2D
{
public:
    Vector2D()
    {
	this->x = 0;
        this->y = 0;
    }

    // Конструктор, сразу указываем x и y
    Vector2D(int x, int y)
    {
	this->x = x;
	this->y = y;
    }
    // Деструктор (если нужен)
    ~Vector2D() { }

    // Получение x и y (самих полей в публичной части быть не должно)
    int getX() const
    {
        return x;
    }
    int getY() const
    {
        return y;
    }

    void setX(const int x)
    {
	this->x = x;
    }
    void setY(const int y)
    {
	this->y = y;
    }

    // Перегруженный оператор - сравнение двух векторов на равенство
    bool operator== (const Vector2D& v2)
    {
        return ((x == v2.x)*(y == v2.y));
    }

    bool operator!= (const Vector2D& v2)
    {
	return !((x == v2.x)*(y == v2.y));
	//return ! this* == v2;
    }

    Vector2D operator+ (const Vector2D& v2)
    {
	return  Vector2D(x + v2.getX(), y + v2.getY());
    }

    Vector2D operator* (const int a)
    {
	return  Vector2D(x*a, y*a);
    }
protected:
int x;
int y;

};


// Перегруженный оператор, вывод вектора в формате (1; 1)
//std::ostream& operator<<(std::ostream& os, Vector2D& v)
//{
//    os << "(" << v.getX() << "; " << v.getY() << ")";
//    return os;
//}

std::ostream& operator<<(std::ostream& os, Vector2D v)
{
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
}

std::istream& operator>>(std::istream &is, Vector2D &v)
{
    is >> v.x >> v.y;
    return is;
}

Vector2D operator* (int a, const Vector2D& v)
{
	Vector2D v3 = v;
	return v3*a;
}


int main()
{
    Vector2D v1();
    Vector2D v2();
    Vector2D v3();

    v1.setX(1);
    v1.setY(1);

    cout << "Enter v2" << endl;
    cin >> v2;

    cout << "Enter v3" << endl;
    cin >> v3;

    cout <<"v1 = " << v1 << endl;
    cout <<"v2 = " << v2 << endl;
    cout <<"v1 == v2  " << (v1 == v2) << endl;
    cout <<"v1 == v3  " << (v1 == v3) << endl;
    cout <<"v1 != v2  " << (v1 != v2) << endl;
    cout <<"v1 != v3  " << (v1 != v3) << endl;
    Vector2D v4 = v1 + v2;
    cout <<"v1 + v2   " << (v1 + v2) << endl;
    cout <<"v1 * 2    " << (v1*2) << endl;
    cout <<"2 * v1    " << (2*v1) << endl;
}


