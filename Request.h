/**
 * @file Request.h
 * @brief Definition of the Request struct and helper functions.
 */

#pragma once

#include <string>

/**
 * @brief Represents a single client request to the web servers.
 *
 * Each request contains an incoming IP address, an outgoing IP address,
 * the remaining processing time in clock cycles, and a job type
 * indicating processing or streaming.
 */
struct Request
{
    std::string ipIn;   ///< Source IP address of the request.
    std::string ipOut;  ///< Destination IP address of the response.
    int timeRemaining;  ///< Remaining processing time in clock cycles.
    char jobType;       ///< Job type: 'P' for processing, 'S' for streaming.
};

/**
 * @brief Generate a random IP address in dotted decimal format.
 *
 * @return A random IPv4 address string.
 */
std::string generateRandomIp();

/**
 * @brief Set the IP prefix used for firewall blocking (called after loading config).
 *
 * @param prefix IP prefix to block (e.g. "10.0.0." blocks 10.0.0.*).
 */
void setBlockedIpPrefix(const std::string &prefix);

/**
 * @brief Determines whether the given IP address is blocked by the firewall.
 *
 * This can be used to simulate an IP range blocker for DOS prevention.
 *
 * @param ip The IP address to check.
 * @return true if the IP is blocked; false otherwise.
 */
bool isBlockedIp(const std::string &ip);

/**
 * @brief Generate a random request with time and job type.
 *
 * @param minTime Minimum processing time in clock cycles.
 * @param maxTime Maximum processing time in clock cycles.
 * @return A randomly generated Request.
 */
Request generateRandomRequest(int minTime, int maxTime);

