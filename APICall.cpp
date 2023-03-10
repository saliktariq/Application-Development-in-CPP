#include <iostream>
#include <string>
#include "curl/curl.h"

int main() {
    // Initialize the cURL library
    curl_global_init(CURL_GLOBAL_ALL);

    // Set the Amadeus API endpoint and API key
    std::string endpoint = "https://test.api.amadeus.com/v2/reference-data/locations?subType=AIRPORT&keyword=PAR";
    std::string api_key = "Nau7yJIHhp2voqNZE79vdWAu5NneZvlq";
    std::string api_secret = "wkoy0zGanVyX3JkH";

    // Set the cURL options
    CURL* curl = curl_easy_init();
    curl_easy_setopt(curl, CURLOPT_URL, endpoint.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // Set the request headers
    struct curl_slist* headers = nullptr;
    std::string auth_header = "Authorization: Bearer " + api_key + api_secret;
    std::string accept_header = "Accept: application/json";
    headers = curl_slist_append(headers, auth_header.c_str());
    headers = curl_slist_append(headers, accept_header.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

    // Perform the HTTP request and store the result
    std::string response;
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, [](void* data, size_t size, size_t nmemb, void* userdata) -> size_t {
        size_t realsize = size * nmemb;
        std::string* str = reinterpret_cast<std::string*>(userdata);
        str->append(static_cast<char*>(data), realsize);
        return realsize;
    });
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    CURLcode res = curl_easy_perform(curl);

    // Check for errors and output the result
    if (res != CURLE_OK) {
        std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
    } else {
        std::cout << response << std::endl;
    }

    // Cleanup the cURL library
    curl_easy_cleanup(curl);
    curl_slist_free_all(headers);
    curl_global_cleanup();

    return 0;
}

