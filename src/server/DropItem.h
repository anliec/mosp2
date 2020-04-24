/**
 * \file DropItem.h
 */

#ifndef DropItem_h
#define DropItem_h


class DropItem {
private:
protected:
public:
    double dropProbability;
    int itemType;
    int maxDropCount;

public:
    DropItem(const int& itemTypeconst, const double& prob, const int& count=1):
        dropProbability(prob), itemType(itemTypeconst), maxDropCount(count)
    {
        // @todo
    }
    // Public methods

    /**
     *  @param perception TBD
     *  @return int
     */
    int getDropCount(const int& perception=100) {
        // @todo
        return 0;
    }


    // Protected methods
protected:

    // Private methods
private:
};

#endif // DropItem_h
