    #include <iostream>

    class Lvalue
    {
        int d_value;

        public:
            operator int&();
    };

	inline Lvalue::operator int&()
	{
	    return d_value;
	}
	
    int main()
    {
        Lvalue lvalue;

        lvalue = 5;     // won't compile: no lvalue::operator=(int)
    };
