#include <fstream>
#include <string>
#include <vector>

//LINES
    class Lines
    {
        std::vector<std::string> d_line;
    
        public:
            class Proxy;
            Proxy operator[](size_t idx);
            class Proxy
            {
                friend Proxy Lines::operator[](size_t idx);
                std::string &d_str;
                Proxy(std::string &str);
                public:
                    std::string &operator=(std::string const &rhs);
                    operator std::string const &() const;
            };                
            Lines(std::istream &in);
    };
//=

//MEMBERS
    inline Lines::Proxy::Proxy(std::string &str)
    :
        d_str(str)
    {}
    inline std::string &Lines::Proxy::operator=(std::string const &rhs)
    {
        return d_str = rhs;
    }
    inline Lines::Proxy::operator std::string const &() const
    {
        return d_str;
    }
//=

inline std::ostream &operator<<(std::ostream &out, Lines::Proxy const &proxy)
{
    return out << static_cast<std::string const &>(proxy);
}

//OPIDX
    inline Lines::Proxy Lines::operator[](size_t idx)
    {
        Proxy ret(d_line[idx]);
        return ret;
    }
//=
