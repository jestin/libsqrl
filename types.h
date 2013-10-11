#ifndef TYPES_H
#define TYPES_H

#include<string>

namespace libsqrl {

struct authentication_data
{
    std::string url;
    char signature[64];
    char identity[32];
};

}

#endif // TYPES_H
