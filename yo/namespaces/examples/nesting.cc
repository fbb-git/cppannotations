namespace CppAnnotations
{
    int value;

    namespace Virtual
    {
        void *pointer;
    }
}

//                                                // 0

//using namespace CppAnnotations;                 // 1

//using namespace CppAnnotations::Virtual;        // 2

//using namespace CppAnnotations;                 // 3
//using namespace Virtual;                        

//using CppAnnotations::value;                    // 4
//using CppAnnotations::Virtual::pointer;

//using namespace CppAnnotations::Virtual;        // 5
//using CppAnnotations::value;

int main()
{
//    CppAnnotations::Virtual::pointer = 0;       // 0
//    CppAnnotations::value = 0;

//    value = 0;                                  // 1
//    Virtual::pointer = 0;

//    CppAnnotations::value = 0;                  // 2
//    pointer = 0;                               

//    value = 0;                                  // 3, 4, 5
//    pointer = 0;                               
}
