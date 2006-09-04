    #include <iostream>
    #include <string>

    class caseString
    {
        friend ostream &operator<<(ostream &ostr, caseString const &str)
        {
            return ostr << str.operator string();
        }

        public:
            enum Mode
            {
                ORIGINAL,
                LOWER,
                UPPER,
            };

            caseString(char const *text)
            :
                mode(ORIGINAL),
                original(text),
                stringPtr(&caseString::original)
            {
                for (unsigned idx = 0; idx < original.length(); ++idx)
                {
                    upper += toupper(text[idx]);
                    lower += tolower(text[idx]);
                }
            }

            void setMode(int mode)
            {
                stringPtr = stringMember[mode];
            }

            operator string() const
            {
                return this->*stringPtr;
            }

        private:
            Mode
                mode;
            string
                caseString::*stringPtr,
                original,
                lower,
                upper;
            static
                string caseString::*stringMember[];
    };
