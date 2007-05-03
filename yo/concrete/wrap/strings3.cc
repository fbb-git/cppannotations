    class Strings
    {
        private:
            static bool xform(std::string &str, Context &context);
    };

    void Strings::uppercase(std::ostream &out, char const *letters)
    {
        Context context = {out, letters};

        find_if(d_vs.begin(), d_vs.end(),
            FnWrap1c<std::string &, Context &, bool>(xform, context));
    }

    bool Strings::xform(std::string &str, Context &context)
    {
        if (str.empty())
            return true;
    
        // previous implementation (not modified)

        return false;
    }
