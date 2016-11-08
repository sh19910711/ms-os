#include <app.h>

// XXX
#ifdef ARCH_ESP8266
#include "arch/esp8266/finfo.h"
#endif


int _HTTP::request(const char *method, string url,
                   const void *payload, size_t payload_size, string headers,
                   void *resp, size_t resp_size) {

#ifdef ARCH_ESP8266
    // TODO: support TLS
    int port;
    bool tls;
    const char *rest;
    if (url.startswith("http://")) {
        port = 80;
        tls = false;
        rest = url.c_str() + 7;
    } else if (url.startswith("https://")) {
        port = 443;
        tls  = true;
        rest = url.c_str() + 8;
    } else {
        Logging.errorln("HTTP: unsupported scheme");
        return 0;
    }

    string host;
    while (*rest && *rest != ':' && *rest != '/') {
        host += *rest;
        rest++;
    }

    if (*rest == ':') {
        string s;
        rest++; // skip ':'
        while (*rest && *rest != '/') {
            s += *rest;
            rest++;
        }

        port = s.to_int();
    }

    string path;
    while (*rest) {
        path += *rest;
        rest++;
    }

    finfo->http_request(host.c_str(), port, method, path.c_str(),
                        headers.c_str(), payload, payload_size,
                        resp, resp_size, tls);

    // TODO: get response headers
    // TODO: return http status code
    return 200; // XXX
#endif
}


int _HTTP::GET(string url, string headers, void *resp, size_t resp_size) {

    return request("GET", url, nullptr, 0, headers, resp, resp_size);
}


int _HTTP::POST(string url, const void *payload, size_t payload_size,
                string headers, void *resp, size_t resp_size) {

    return request("POST", url, payload, payload_size, headers, resp, resp_size);
}


int _HTTP::PUT(string url, const void *payload, size_t payload_size,
               string headers, void *resp, size_t resp_size) {

    return request("PUT", url, payload, payload_size, headers, resp, resp_size);
}


int _HTTP::DELETE(string url, string headers, void *resp, size_t resp_size) {

    return request("DELETE", url, nullptr, 0, headers, resp, resp_size);
}
