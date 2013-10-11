#include <key_generator.h>
#include <sodium/sodium.h>

namespace libsqrl {

key_generator::key_generator()
{
}

key_generator::~key_generator()
{
}

char* key_generator::generate_key(char* master_key, std::string domain)
{
    char* output = NULL;
    crypto_auth_hmacsha256((unsigned char*) output, (unsigned char*) domain.c_str(), domain.size(), (unsigned char*) master_key);
    return output;
}

} // namespace libsqrl
