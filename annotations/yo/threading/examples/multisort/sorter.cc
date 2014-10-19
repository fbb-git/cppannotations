#include "main.ih"

void sorter(Pair const &range)
{
//    {
//        lock_guard<mutex> lk(g_cerrMutex);
//        cerr << "sorting " << at(range.first) << " to " << at(range.second) <<
//        '\n';
//    }

    if (range.second - range.first < 2)
        return;

    auto rhsBegin = partition(range.first + 1, range.second, 
                            bind2nd(less<int>(), *range.first));
    auto lhsEnd = rhsBegin - 1;

    swap(*range.first, *lhsEnd);

    pushQueue(range.first, lhsEnd);
    pushQueue(rhsBegin, range.second);    
}





