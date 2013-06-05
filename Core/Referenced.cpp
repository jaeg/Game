#include "Referenced.h"


Referenced::Referenced()
{
    referenceCount = 0;
}

void Referenced::Add()
{
    referenceCount++;
}

void Referenced::Drop()
{
    referenceCount--;
    if (referenceCount <= 0)
    {
        delete this;
    }
}