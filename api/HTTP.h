#ifndef __HTTP_H__
#define __HTTP_H__

#include <resea.h>

class _HTTP {
  public:
    int request(const char *method, string url,
                const void *payload, size_t payload_size, string headers,
                void *resp, size_t resp_size);
    int GET(string url, string headers, void *resp, size_t resp_size);
    int POST(string url, const void *payload, size_t payload_size, string headers,
             void *resp, size_t resp_size);
    int PUT(string url, const void *payload, size_t payload_size, string headers,
            void *resp, size_t resp_size);
    int DELETE(string url, string headers, void *resp, size_t resp_size);
};

#endif
