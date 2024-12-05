#include "Config.hpp"
#include "gomea.hpp"
#include "gomeaIMS.hpp"
#include "gomeaP3_MI.hpp"
#include <chrono> // Include chrono library for time-based seeding


int main(int argc, char **argv)
{
    Config *config = new Config();
    config->parseCommandLine(argc, argv);
    config->checkOptions();
    // config->printOverview();
    auto now = std::chrono::system_clock::now();
    auto seed_time = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count();
    int randomSeed = static_cast<long long>(seed_time);
    config->rng.seed(randomSeed);

    GOMEA *gomeaInstance;
    if (config->populationScheme == 0 || config->populationScheme == 1)
        gomeaInstance = new gomeaIMS(config);
    else
        gomeaInstance = new gomeaP3_MI(config);
    
    try
    {
        gomeaInstance->run();
    }
    catch (customException &ex)
    {}

    delete gomeaInstance;
    delete config;
    
    return 0;
}