#include "Client.h"

using namespace std;

int main()
{
    netWars::Configuration::init();
    netWars::Client *client = new netWars::Client();
    client->start();
    return 0;
}
