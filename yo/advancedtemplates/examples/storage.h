#ifndef INCLUDED_STORAGE_H_
#define INCLUDED_STORAGE_H_

#include <vector>

template <typename Data,
          template <typename> class Policy,
          template <typename, typename> class Container = std::vector
        >
class Storage: public Container<Data, Policy<Data>>
{};


#endif
