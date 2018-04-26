//#include <iostream>
//#incude <vector>
#include <map>

class Balancer
{
public:
    Balancer()
    {
        //this->Totsize = 0;
    }

    // Проанализировать текущие задачи
    void analyze(const vector<Task>& tasks)
    {
        for (vector<Task>::const_iterator it = tasks.begin(); it != tasks.end(); it++)
        {
            if (this->Totsize.count(it->getCPU()) == 0)
                this->Totsize[it->getCPU()] = it->getSize();
            else
                this->Totsize[it->getCPU()] = this->Totsize[it->getCPU()] + it->getSize();
        }
    }

    // Сообщить общую нагрузку на заданное ядро
    int getLoadForCPU(int cpuNum)
    {
        return Totsize[cpuNum];
    }
protected:
    map<int,int> Totsize;
};
