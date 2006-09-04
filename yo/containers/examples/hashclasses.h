#ifndef _INCLUDED_HASHCLASSES_H_
#define _INCLUDED_HASHCLASSES_H_

#include <string>
#include <cctype>

/*
    Note that with the Gnu g++ compiler 3.2 (and beyond?) the ext/ header
    uses the __gnu_cxx namespace for symbols defined in these header files.

    When using compilers before version 3.2, do:
        #define __gnu_cxx   std
    before including this file to circumvent problems that may occur
    because of these namespace conventions which were not yet used in versions
    before 3.2.

*/

#include <ext/hash_map>
#include <algorithm>

/*
    This file is copyright (c) GPL, 2001-2004
    ==========================================
    august 2004: redundant include guards removed

    october 2002:   provisions for using the hashclasses with the g++ 3.2
                compiler were incorporated.

    april 2002: namespace FBB introduced
                abbreviated class templates defined,
                see the END of this comment section for examples of how
                to use these abbreviations.

    jan 2002:   redundant include guards added,
                required header files adapted,
                for_each() rather than transform() used

    With hash_maps using char const * for the keys:
                         ============

    * Use `HashCharPtr' as 3rd template argument for case-sensitive keys
    * Use `HashCaseCharPtr' as 3rd template argument for case-insensitive
      keys

    * Use `EqualCharPtr' as 4th template argument for case-sensitive keys
    * Use `EqualCaseCharPtr' as 4th template argument for case-insensitive
      keys


    With hash_maps using std::string for the keys:
                         ===========

    * Use `HashString' as 3rd template argument for case-sensitive keys
    * Use `HashCaseString' as 3rd template argument for case-insensitive keys

    * OMIT the 4th template argument for case-sensitive keys
    * Use `EqualCaseString' as 4th template argument for case-insensitive
        keys


    Examples, using int as the value type. Any other type can be used instead
              for the value type:

                                    // key is char const *, case sensitive
        __gnu_cxx::hash_map<char const *, int, FBB::HashCharPtr,
                            FBB::EqualCharPtr >
            hashtab;

                                    // key is char const *, case insensitive
        __gnu_cxx::hash_map<char const *, int, FBB::HashCaseCharPtr,
                                         FBB::EqualCaseCharPtr >
            hashtab;

                                    // key is std::string, case sensitive
        __gnu_cxx::hash_map<std::string, int, FBB::HashString>
            hashtab;

                                    // key is std::string, case insensitive
        __gnu_cxx::hash_map<std::string, int, FBB::HashCaseString,
                                        FBB::EqualCaseString>
            hashtab;

    Instead of the above full typedeclarations, the following shortcuts should
    work as well:

        FBB::CharPtrHash<int>       // key is char const *, case sensitive
            hashtab;

        FBB::CharCasePtrHash<int>   // key is char const *, case insensitive
            hashtab;

        FBB::StringHash<int>        // key is std::string, case sensitive
            hashtab;

        FBB::StringCaseHash<int>    // key is std::string, case insensitive
            hashtab;

    With these template types iterators and other map-members are also
    available. E.g.,

    --------------------------------------------------------------------------
    extern FBB::StringHash<int> dh;

    for (FBB::StringHash<int>::iterator it = dh.begin(); it != dh.end(); it++)
        std::cout << it->first << " - " << it->second << std::endl;
    --------------------------------------------------------------------------

    Feb. 2001 - April 2002
    Frank B. Brokken (f.b.brokken@rc.rug.nl)
*/

namespace FBB
{

    class HashCharPtr
    {
        public:
            size_t operator()(char const *str) const
            {
                return __gnu_cxx::hash<char const *>()(str);
            }
    };

    class EqualCharPtr
    {
        public:
            bool operator()(char const *x, char const *y) const
            {
                return !strcmp(x, y);
            }
    };

    class HashCaseCharPtr
    {
        public:
            size_t operator()(char const *str) const
            {
                std::string s = str;
                for_each(s.begin(), s.end(), *this);
                return __gnu_cxx::hash<char const *>()(s.c_str());
            }
            void operator()(char &c) const
            {
                c = tolower(c);
            }
    };

    class EqualCaseCharPtr
    {
        public:
            bool operator()(char const *x, char const *y) const
            {
                return !strcasecmp(x, y);
            }
    };

    class HashString
    {
        public:
            size_t operator()(std::string const &str) const
            {
                return __gnu_cxx::hash<char const *>()(str.c_str());
            }
    };

    class HashCaseString: public HashCaseCharPtr
    {
        public:
            size_t operator()(std::string const &str) const
            {
                return HashCaseCharPtr::operator()(str.c_str());
            }
    };

    class EqualCaseString
    {
        public:
            bool operator()(std::string const &s1, std::string const &s2) const
            {
                return !strcasecmp(s1.c_str(), s2.c_str());
            }
    };


    template<typename Value>
    class CharPtrHash: public
        __gnu_cxx::hash_map<char const *, Value, HashCharPtr, EqualCharPtr >
    {
        public:
            CharPtrHash()
            {}
            template <typename InputIterator>
            CharPtrHash(InputIterator first, InputIterator beyond)
            :
                __gnu_cxx::hash_map<char const *, Value, HashCharPtr,
                                    EqualCharPtr>(first, beyond)
            {}
    };

    template<typename Value>
    class CharCasePtrHash: public
        __gnu_cxx::hash_map<char const *, Value, HashCaseCharPtr,
                                                 EqualCaseCharPtr >
    {
        public:
            CharCasePtrHash()
            {}
            template <typename InputIterator>
            CharCasePtrHash(InputIterator first, InputIterator beyond)
            :
                __gnu_cxx::hash_map<char const *, Value,
                            HashCaseCharPtr, EqualCaseCharPtr>
                            (first, beyond)
            {}
    };

    template<typename Value>
    class StringHash: public __gnu_cxx::hash_map<std::string, Value,
                                                 HashString>
    {
        public:
            StringHash()
            {}
            template <typename InputIterator>
            StringHash(InputIterator first, InputIterator beyond)
            :
                __gnu_cxx::hash_map<std::string, Value, HashString>
                             (first, beyond)
            {}
    };


    template<typename Value>
    class StringCaseHash: public
            __gnu_cxx::hash_map<std::string, int, HashCaseString,
                                EqualCaseString>
    {
        public:
            StringCaseHash()
            {}
            template <typename InputIterator>
            StringCaseHash(InputIterator first, InputIterator beyond)
            :
                __gnu_cxx::hash_map<std::string,
                            int, HashCaseString,
                            EqualCaseString>(first, beyond)
            {}
    };

    template<typename Key, typename Value>
    class Hash: public
            __gnu_cxx::hash_map<Key, Value,
                        __gnu_cxx::hash<Key>(),
                        equal<Key>())
    {};

}
#endif
