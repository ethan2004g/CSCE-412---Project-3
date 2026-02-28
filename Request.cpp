/**
 * @file Request.cpp
 * @brief Implementation of the Request helper functions.
 */

#include "Request.h"

#include <random>
#include <sstream>

namespace
{
    std::mt19937 &rng()
    {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        return gen;
    }

    std::string g_blockedIpPrefix = "10.";
}

void setBlockedIpPrefix(const std::string &prefix)
{
    g_blockedIpPrefix = prefix;
}

std::string generateRandomIp()
{
    std::uniform_int_distribution<int> dist(0, 255);
    std::ostringstream oss;
    oss << dist(rng()) << '.'
        << dist(rng()) << '.'
        << dist(rng()) << '.'
        << dist(rng());
    return oss.str();
}

bool isBlockedIp(const std::string &ip)
{
    if (g_blockedIpPrefix.empty())
    {
        return false;
    }
    return ip.rfind(g_blockedIpPrefix, 0) == 0;
}

Request generateRandomRequest(int minTime, int maxTime)
{
    if (minTime < 1)
    {
        minTime = 1;
    }
    if (maxTime < minTime)
    {
        maxTime = minTime;
    }

    std::uniform_int_distribution<int> timeDist(minTime, maxTime);
    std::uniform_int_distribution<int> typeDist(0, 1);

    Request r;
    r.ipIn = generateRandomIp();
    r.ipOut = generateRandomIp();
    r.timeRemaining = timeDist(rng());
    r.jobType = (typeDist(rng()) == 0) ? 'P' : 'S';
    return r;
}

