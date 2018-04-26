
class Knight: public Player
{
    bool canUse(Item* item) const
    {
        return (this->level > item->getLevel()) * (this->strength > item->getWeight()) * !(item->isMagical());
    }

    bool canCast() const
    {
        return 0;
    }
};

class Wizard: public Player
{
    bool canUse(Item* item) const
    {
        return (this->level > item->getLevel()) * (this->strength > item->getWeight());
    }

    bool canCast() const
    {
        return 1;
    }
};
