    #include "sumvectorsize.h"

    int main()
    {
        int
            iArray[] = {1, 2, 3},
            *iPtr = iArray;

        sumVector(iArray);  // succeeds: size of iArray is known
        sumVector(iPtr);    // fails: size of array pointed to by
                            // iPtr is unknown
    }
