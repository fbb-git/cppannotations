    #include <fstream>
    #include <cstring>

    class Reference
    {
        std::ostream &d_out;

        public:
            Reference(std::ostream &out)
            :
                d_out(out)
            {}
            void swap(Reference &other)
            {
                char buffer[sizeof(Reference)];
                memcpy(buffer, this, sizeof(Reference));
                memcpy(this, &other,  sizeof(Reference));
                memcpy(&other, buffer, sizeof(Reference));
            }
            std::ostream &out()
            {
                return d_out;
            }
    };

    int main()
    {
        std::ofstream one("one");
        std::ofstream two("two");

        Reference ref1(one);        // ref1/ref2 hold references to
        Reference ref2(two);        // the streams

        ref1.out() << "hello to 1\n";   // generate some output
        ref2.out() << "hello to 2\n";

        ref1.swap(ref2);
                                                 
        ref2.out() << "hello to 1\n";   // more output
        ref1.out() << "hello to 2\n";
    }



