    Binary operator+(Binary const &lhs, Binary const &rhs)
    {
        Binary tmp{ lhs };
        tmp.add(rhs);
        return tmp;
    }
