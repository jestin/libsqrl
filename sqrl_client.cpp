#include <sqrl_client.h>
#include <key_generator.h>
#include <scrypt.h>
#include <sodium/sodium.h>

namespace libsqrl {

sqrl_client::sqrl_client()
{
}

sqrl_client::~sqrl_client()
{
}

authentication_data* sqrl_client::get_sqrl_authentication_data(char* master_identity_key, std::string password, std::string url)
{
    key_generator keygen;
    std::string domain = get_domain(url);

    if(domain == "")
    {
        return NULL;
    }

    char* master_key = get_master_key(master_identity_key, password);

    char* private_key = keygen.generate_key(master_key, domain);

    authentication_data* data = (authentication_data*)malloc(sizeof(authentication_data));

    data->url = url;
    data->signature = sign(private_key, url);
    data->identity = create_public_key(private_key);

    return data;
}

std::string sqrl_client::get_domain(std::string url)
{
    std::size_t start = url.find("://") + 3;

    if(start == std::string::npos)
    {
        return "";
    }

    std::size_t end = url.find('/', start);

    if(end == std::string::npos)
    {
        return "";
    }

    return url.substr(start, end - start);
}

char* sqrl_client::get_master_key(char* master_identity_key, std::string password)
{
    char scrypt_output[32];
    char* output = (char*) malloc(32);

    scrypt_1024_1_1_256(password.c_str(), scrypt_output);

    for(int i = 0; i < 32; i++)
    {
        output[i] = scrypt_output[i] ^ master_identity_key[i];
    }

    return output;
}

char* sqrl_client::sign(char* key, std::string url)
{
    char* output = (char*) malloc(64);
    unsigned long long signed_length = 0;
    crypto_sign_ed25519((unsigned char*) output, &signed_length, (unsigned char*) url.c_str(), url.length(), (unsigned char*) key);

    return output;
}

char* sqrl_client::create_public_key(char* key)
{
    return NULL;
}

} // namespace libsqrl
