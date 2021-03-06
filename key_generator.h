#ifndef KEY_GENERATOR_H
#define KEY_GENERATOR_H

#include<libsqrl_global.h>
#include<string>

namespace libsqrl {

class key_generator
{
public:
    key_generator();
    ~key_generator();

    char* generate_key(char* master_key, std::string domain);
};

}

#endif // KEY_GENERATOR_H
