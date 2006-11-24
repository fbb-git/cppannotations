    #include <map>
    #include <algorithm>
    #include <functional>
    #include <iterator>

/*
//FUNCTION
    template <typename Key, typename Value>
    class Dictionary;

    template <typename Key, typename Value>
    Dictionary<Key, Value>
               subset(Key const &key, Dictionary<Key, Value> const &dict);

    template <typename Key, typename Value>
    class Dictionary
    {
        friend Dictionary<Key, Value> subset<Key, Value>
                   (Key const &key, Dictionary<Key, Value> const &dict);
        std::map<Key, Value> d_dict;
        public:
            Dictionary();
    };

    template <typename Key, typename Value>
    Dictionary<Key, Value>
               subset(Key const &key, Dictionary<Key, Value> const &dict)
    {
        Dictionary<Key, Value> ret;

        std::remove_copy_if(dict.d_dict.begin(), dict.d_dict.end(),
                            std::inserter(ret.d_dict, ret.d_dict.begin()),
                            std::bind2nd(std::equal_to<Key>(), key));
        return ret;
    }
//=
*/
//CLASS1
    template <typename Key, typename Value>
    class Iterator;

    template <typename Key, typename Value>
    class Dictionary
    {
        friend class Iterator<Key, Value>;
//=
        std::map<Key, Value> d_dict;

        public:
            Dictionary();

                                    // uses the friend's constructor
        template <typename Key2, typename Value2>
        Iterator<Key2, Value2> begin();


        template <typename Key2, typename Value2>
        Iterator<Key2, Value2>        // uses a member function
                    subset(Key const &key);
    };

//CLASS2
    template <typename Key, typename Value>
    template <typename Key2, typename Value2>
    Iterator<Key2, Value2> Dictionary<Key, Value>::begin()
    {
        return Iterator<Key, Value>(*this);
    }
    template <typename Key, typename Value>
    template <typename Key2, typename Value2>
    Iterator<Key2, Value2> Dictionary<Key, Value>::subset(Key const &key)
    {
        return Iterator<Key, Value>(*this).subset(key);
    }
//=

/*
//CLASS3
    template <typename Key, typename Value>
    class Iterator
    {
        std::map<Key, Value> &d_dict;

        public:
            Iterator(Dictionary<Key, Value> &dict)
            :
                d_dict(dict.d_dict)
            {}
//=
*/
//CLASS3a
    template <typename Key, typename Value>
    class Iterator
    {
        friend Dictionary<Key, Value>::Dictionary();

        std::map<Key, Value> &d_dict;

        Iterator(Dictionary<Key, Value> &dict);

        public:
//=
        typename std::map<Key, Value>::iterator begin();
        typename std::map<Key, Value>::iterator subset(Key const &key);
    };

//CLASS4
    template <typename Key, typename Value>
    typename std::map<Key, Value>::iterator Iterator<Key, Value>::begin()
    {
        return d_dict.begin();
    }
//=

    template <typename Key, typename Value>
    Iterator<Key, Value>::Iterator(Dictionary<Key, Value> &dict)
    :
        d_dict(dict.d_dict)
    {}

    template <typename Key, typename Value>
    typename std::map<Key, Value>::iterator
    Iterator<Key, Value>::subset(Key const &key)
    {
        return d_dict.begin();
    }
