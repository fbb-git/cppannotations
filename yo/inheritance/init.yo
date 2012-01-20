Consider classes derived from tt(std::istream) or tt(std::ostream). Such a
class could be designed as follows:
        verb(
    class XIstream: public std::istream
    {
        public:
            ...
    };
        )
    Assuming that the tt(streambuf) to which tt(XIstream) interfaces is not
yet available construction time, tt(XIstream) only offers default
constructors. The class could, however, offer a member tt(void
switchStream(std::streambuf *sb)) to provide tt(XIstream) objects with a
tt(streambuf) to interface to. How to implement tt(switchStream)?

    The classes tt(std::istream) and tt(std::ostream) offer a protected member
tt(void) hi(init) tt(init(std::streambuf *sb)) to realize this. The tt(init)
member expects a pointer to a streambuf which is associated with the
tt(istream) or tt(ostream) object. The tt(init) member properly ends any
existing association before switching to the tt(streambuf) whose address is
provided to tt(init).

Assuming that the tt(streambuf) to which tt(switchStream)'s tt(sb) points
persists, then tt(switchStream) could simply be implemented like this:
        verb(
    void switchStream(streambuf *sb)
    {
        init(sb);
    }
        )
