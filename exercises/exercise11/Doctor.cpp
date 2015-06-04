#include "Doctor.h"

Doctor* Doctor:: clone()const
{
    return new Doctor(*this);
}
