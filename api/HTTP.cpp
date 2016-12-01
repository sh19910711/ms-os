#include <resea/channel.h>
#include <resea/http.h>
#include <app.h>


_HTTP::_HTTP() {

    http_server = open();
    // TODO: check return values

    result_t r;
    call_channel_connect(channel_server, http_server, HTTP_INTERFACE, &r);
}


int _HTTP::request(int options, string url,
                   const void *payload, size_t payload_size, string headers,
                   void **resp, size_t *resp_size) {

    if (!resp)
        options |= HTTP_OPTION_DISCARD_RESPONSE_PAYLOAD;

    int status_code;
    result_t r;
    call_http_request(http_server, options, (void *) url.c_str(), url.length(),
                      (void *) headers.c_str(), headers.length(),
                      (void *) payload, payload_size,
                      &r, &status_code, resp, resp_size);

    return status_code;
}


int _HTTP::GET(string url, string headers, void **resp, size_t *resp_size) {

    return request(HTTP_METHOD_GET, url, nullptr, 0, headers, resp, resp_size);
}


int _HTTP::POST(string url, const void *payload, size_t payload_size,
                string headers, void **resp, size_t *resp_size) {

    return request(HTTP_METHOD_POST, url, payload, payload_size, headers, resp, resp_size);
}


int _HTTP::PUT(string url, const void *payload, size_t payload_size,
               string headers, void **resp, size_t *resp_size) {

    return request(HTTP_METHOD_PUT, url, payload, payload_size, headers, resp, resp_size);
}


int _HTTP::DELETE(string url, string headers, void **resp, size_t *resp_size) {

    return request(HTTP_METHOD_DELETE, url, nullptr, 0, headers, resp, resp_size);
}
