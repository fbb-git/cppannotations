    #include <string>

    class PointerData
    {
        public:
            PointerData()
            {
                infoPtr = &PointerData::allInfo;
            }
            string show()
            {
                return (this->*infoPtr)(4);
            }
        private:
            string allInfo(int i)
            {
                return "hello";
            }

            string (PointerData::*infoPtr)(int);
    };

    int main()
    {
        PointerData
            pd;

        pd.show();
    }
