#ifndef SQRL_CLIENT_H
#define SQRL_CLIENT_H

#include <libsqrl_global.h>
#include <types.h>
#include <string>

namespace libsqrl {

class sqrl_client
{
public:
    sqrl_client();
    ~sqrl_client();

    authentication_data* generate_sqrl_request(char* master_identity_key, std::string password, std::string url);

private:
    std::string get_domain(std::string url);
    char* get_master_key(char* master_identity_key, std::string password);
};

}

#endif // SQRL_CLIENT_H