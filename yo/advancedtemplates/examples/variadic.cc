    // variadic function template
    template<typename ... Params> 
    void fun(Params ... parameters)
    {}

    // instantiation declaration
    template
    void fun<int>(int v);

    // pointers to functions that are instantiated from a variadic function
    // template
    void (*fp)(int) = fun;
    void (*fp2)(int, double) = fun;

    // template class having variadic function template member
    template <typename T>
    struct Demo
    {
        template<typename ... Params> 
        void mem(Params ... parameters)
        {}
    };

    // instantiation declaration:
    template
    void Demo<char>::mem<int>(int v);

    // pointers to functions that are instantiated from a variadic function
    // template
    void (Demo<char>::*mp)(int) = &Demo<char>::mem;
    void (Demo<char>::*mp2)(int, double) = &Demo<char>::mem;

    
    // explicitly obtain the address of the Demo::mem member expecting an int:
    void (Demo<char>::*mp1)(int) = 
                    //&Demo<char>::mem(int);
        // error meesage: expected primary-expression before 'int'
                    &Demo<char>::mem<int>;
        // OK
    

    // a template class using perfect forwarding:
    template<typename T>
    struct Demo2
    {
        template<typename ... Args>
        void mem(Args&& ... args)
        {}
    };

    // instantiation declaration:
    template
        // void Demo2<char>::mem<int>(int v);
        // error: template-id 'mem<int>' for 'void Demo2<char>::mem(int)' does 
        //        not match any template declaration 
        // void Demo2<char>::mem<typename ... Args>(Args && ... args);
        // error: using 'typename' outside of template
        //        expected parameter pack before '...'
        //        parse error in template argument list
        //        template-id 'mem<<expression error> >' used as a declarator
        //        variable or field 'mem' declared void
        //        expected `;' before '(' token
    void Demo2<char>::mem<int &&>(int &&);
        // or:  void Demo2<char>::mem(int &&);
        
    // pointers to Demo2::mem:
    void (Demo2<char>::*mpd2)(int &&) = &Demo2<char>::mem;
