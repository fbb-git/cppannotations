#include "bidirectional.h"

#include <algorithm>

int main()
{
    inplace_merge(BidirectionalIterator{ 0 }, BidirectionalIterator{ 100 },
                            BidirectionalIterator{ 200 });
    next_permutation(BidirectionalIterator{ 0 },
                     BidirectionalIterator{ 100 });
}
