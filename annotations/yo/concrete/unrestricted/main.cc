#include "main.ih"

int main(int argc, char **argv)
{
    Parser parser;

    parser.setDebug(argc == 1);

    parser.parse();

    return 0;
}
