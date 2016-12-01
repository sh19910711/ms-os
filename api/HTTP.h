#ifndef __HTTP_H__
#define __HTTP_H__

#include <resea.h>

class _HTTP {
    channel_t http_server;
    int request(int options, string url,
                const void *payload, size_t payload_size, string headers,
                void **resp, size_t *resp_size);
  public:
    _HTTP();
    int GET(string url, string headers, void **resp = nullptr, size_t *resp_size = 0);
    int POST(string url, const void *payload, size_t payload_size, string headers,
             void **resp = nullptr, size_t *resp_size = 0);
    int PUT(string url, const void *payload, size_t payload_size, string headers,
            void **resp = nullptr, size_t *resp_size = 0);
    int DELETE(string url, string headers, void **resp = nullptr, size_t *resp_size = 0);
};

#endif
