    #ifndef _INCLUDED_STRINGPTR_H_
    #define _INCLUDED_STRINGPTR_H_

    #include <vector>
    #include <string>
    #include "iterator.h"

    class StringPtr: public std::vector<std::string *>
    {
        public:
            typedef RandomPtrIterator
                    <
                        StringPtr,
                        std::vector<std::string *>::iterator,
                        std::string
                    >
                        iterator;

            typedef std::reverse_iterator<iterator> reverse_iterator;

            iterator begin();
            iterator end();
            reverse_iterator rbegin();
            reverse_iterator rend();
    };

    inline StringPtr::iterator StringPtr::begin()
    {
        return iterator(this->std::vector<std::string *>::begin() );
    }
    inline StringPtr::iterator StringPtr::end()
    {
        return iterator(this->std::vector<std::string *>::end());
    }
    inline StringPtr::reverse_iterator StringPtr::rbegin()
    {
        return reverse_iterator(end());
    }
    inline StringPtr::reverse_iterator StringPtr::rend()
    {
        return reverse_iterator(begin());
    }
    #endif
