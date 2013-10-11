#ifndef TYPES_H
#define TYPES_H

#include<string>

namespace libsqrl {

struct authentication_data
{
    std::string url;
    char* signature;
    char* identity;
};

}

#endif // TYPES_H
