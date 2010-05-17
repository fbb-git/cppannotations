#include <memory>
#include <iostream>

using namespace std;

#if 0
    struct X                          
    {       
        ~X()
        {   
            cout << "destr\n";
        }
    };
      
    template<typename T>
    struct ArrayDeleter 
    {                  
       void operator()(T* p)
       {                    
          delete [] p;
       }
    };
      
    int main()
    {         
        shared_ptr<X> sp(new X[3], ArrayDeleter<X>());
        shared_ptr<float> sp(new float[16], ArrayDeleter<float>());
    }
#else
//SHAREDARRAY
    struct X    
    {       
        ~X()
        {   
            cout << "destr\n";  // show the object's destruction
        }
    };
    template <typename Type>
    class shared_array: public shared_ptr<Type>
    {                                       
        struct Deleter          // Deleter receives the pointer
        {                       // and calls delete[] 
           void operator()(Type* ptr)
           {
              delete[] ptr;
           }
        };
        public:
            shared_array(Type *p)           // other constructors 
            :                               // not shown here
                shared_ptr<Type>(p, Deleter())
            {}
            Type &operator[](size_t idx)    // index operators
            {
                return shared_ptr<Type>::get()[idx];
            }
            Type const &operator[](size_t idx) const
            {
                return shared_ptr<Type>::get()[idx];
            }
            Type &operator*() = delete;     // delete pointless members
            Type const &operator*() const = delete;
            Type *operator->() = delete;
            Type const *operator->() const = delete;
    };
    int main()
    {
        shared_array<X> sp(new X[3]);
        sp[0] = sp[1];
    }
//=
#endif



