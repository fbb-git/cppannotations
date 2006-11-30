    #include <iostream>
    #include <iomanip>

    class Align
    {
        unsigned d_width;
        std::ios::fmtflags d_alignment;

        public:
            Align(unsigned width, std::ios::fmtflags alignment);
            std::ostream &operator()(std::ostream &ostr) const;
    };

        Align::Align(unsigned width, std::ios::fmtflags alignment)
        :
            d_width(width),
            d_alignment(alignment)
        {}

        std::ostream &Align::operator()(std::ostream &ostr) const
        {
            ostr.setf(d_alignment, std::ios::adjustfield);
            return ostr << std::setw(d_width);
        }

    std::ostream &operator<<(std::ostream &ostr, Align const &align)
    {
        return align(ostr);
    }

    using namespace std;

    int main()
    {
        cout
            << "`" << Align(5, ios::left) << "hi" << "'"
            << "`" << Align(10, ios::right) << "there" << "'" << endl;
    }

    /*
        Generated output:

        `hi   '`     there'
    */
