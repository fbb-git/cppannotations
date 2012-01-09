#include "semantic.ih"

void Semantic::swap(Semantic &other)
{
    char buffer[sizeof(Semantic)];

    memcpy(buffer, this, sizeof(Semantic));
    memcpy(this, &other, sizeof(Semantic));
    memcpy(&other, buffer, sizeof(Semantic));
}
