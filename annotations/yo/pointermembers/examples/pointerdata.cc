    #include <string>

    class PointerData
    {
        std::string (PointerData::*infoPtr)(int);
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
    };

    int main()
    {
        PointerData pd;

        pd.show();
    }
