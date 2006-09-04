    #ifndef _INCLUDED_STRINGPTR_H_
    #define _INCLUDED_STRINGPTR_H_

    #include <vector>
    #include <string>
    #include "iterator.h"

    class StringPtr: public std::vector<std::string *>
    {
        public:
//RANDOM
            typedef RandomPtrIterator
                    <
                        StringPtr,
                        std::vector<std::string *>::iterator,
                        std::string
                    >
                        iterator;
//=
            typedef std::reverse_iterator<iterator> reverse_iterator;

            iterator begin()
            {
                return iterator(this->std::vector<std::string *>::begin() );
            }
            iterator end()
            {
                return iterator(this->std::vector<std::string *>::end());
            }
            reverse_iterator rbegin()
            {
                return reverse_iterator(end());
            }
            reverse_iterator rend()
            {
                return reverse_iterator(begin());
            }
    };
    #endif
