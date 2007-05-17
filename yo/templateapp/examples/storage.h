#ifndef _INCLUDED_STORAGE_H_
#define _INCLUDED_STORAGE_H_

#include <vector>

template <typename Data, 
          template <typename> class Policy,
          template <typename> class Container = std::vector
        >
class Storage: public Container< Policy<Data> >
{
};


#endif
