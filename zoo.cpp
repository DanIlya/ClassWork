#include <map>

using namespace std;

class ZooKeeper
{
public:
    // Создаём смотрителя зоопарка
    ZooKeeper()
    {
        this->ND = 0;
    }

    // Смотрителя попросили обработать очередного зверя.
    // Если зверь был опасный, смотритель фиксирует у себя этот факт.
    void handleAnimal(Animal* a)
    {
        if (a->isDangerous() == true)
            this->ND++;

       // map<string, int>::iterator i = this->Animals.find(a->getType());
        //if (this->Animals.count(a->getType()))
            this->Animals[a->getType()]++;
    }

    // Возвращает, сколько опасных зверей было обработано на данный момент.
    int getDangerousCount()
    {
        return this->ND;
    }

    // Возвращает, сколько зверей такого типа было обработано.
    // Если таких не было, возвращает 0.
    int getAnimalCount(string type)
    {

       // map<string, int>::iterator i = this->Animals.find(type);

        if (this->Animals.count(type) == 0)
            return 0;
        else
            return this->Animals[type];
    }

protected:
    int ND;
    map<string,int> Animals;
};


