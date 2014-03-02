#include <string>
#include <iterator>

class Data
{
    std::string *d_data;
    size_t d_n;

    public:
        class iterator;
        class const_iterator;

        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
};

class Data::iterator: public std::iterator<std::input_iterator_tag,
                                           std::string>
{
    public:
        iterator() = default;

        iterator &operator++();
        std::string &operator*();

    private:
        friend class Data;
        iterator(std::string *data, size_t idx);

        friend class std::reverse_iterator<iterator>;
        iterator &operator--();
};

bool operator==(Data::iterator const &lhs, Data::iterator const &rhs);



class Data::const_iterator: public std::iterator<std::input_iterator_tag,
                                                 std::string const>
{
    public:
        const_iterator() = default;

        const_iterator &operator++();
        std::string const &operator*() const;

    private:
        friend class Data;
        const_iterator(std::string const *data, size_t idx);

        friend class std::reverse_iterator<const_iterator>;
        const_iterator &operator--();
};

bool operator==(Data::const_iterator const &lhs,
                Data::const_iterator const &rhs);


int main()
{
    Data::iterator iter;
    Data::reverse_iterator riter(iter);

    *riter;

    Data::const_iterator citer;
    Data::const_reverse_iterator criter(citer);

    *criter;

};
