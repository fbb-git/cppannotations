    #include <string>

    class PointerData
    {
        public:
            PointerData()
            {
                infoPtr = &PointerData::allInfo;
            }
            std::string show()
            {
                return (this->*infoPtr)(4);
            }
        private:
            std::string allInfo(int i)
            {
                return "hello";
            }

            std::string (PointerData::*infoPtr)(int);
    };

    int main()
    {
        PointerData
            pd;

        pd.show();
    }
