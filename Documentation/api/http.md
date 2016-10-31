HTTP API
=======

HTTP/HTTPS API allows you to perform a HTTP requests.

Sending Requests
----------------

### request ###
```api:c++
int HTTP::request(const char *method, String url, const void *payload, size_t payload_size, String headers,
                  void *resp, size_t resp_size);
```

Performs a HTTP request. It returns HTTP status code or 0 on unexpected errors.
If `resp` is set, the response body is stored in `resp`. Other arguments are:

- `method`: The capitalized method name.
- `url`: The URL.
- `payload`: The request body or `nullptr`.
- headers is a request headers like `"Foo: bar\r\nBaz: 123"`.

__Example:__ Create a new folder in a WebDAV.
```example:c++
int status;
char resp[128];

status = HTTP.request("MKCOL",
                      "https://example.com/webdav/chandler/NewFolder",
                      nullptr, 0,
                      "", resp, &resp);

if (status != 201)
    Logging.printlnf("server returned %d", status);
```


### get ###
```api:c++
int HTTP::get(String url, String headers, void *resp, size_t resp_size);
```

Performs a GET request. It returns HTTP status code or 0 on unexpected errors.
If `resp` is set, the response body is stored in `resp`. Other arguments are:

- `url`: The URL.
- `headers`: The request headers like `"Foo: bar\r\nBaz: 123"`.



### post ###
```api:c++
int HTTP::post(String url, const void *payload, size_t payload_size, size_t payload_size, String headers,
               void *resp, size_t resp_size);
```

Performs a POST request. It returns HTTP status code or 0 on unexpected errors.
If `resp` is set, the response body is stored in `resp`. Other arguments are:

- `url`: The URL.
- `payload`: The request body or `nullptr`.
- `headers`: The request headers like `"Foo: bar\r\nBaz: 123"`.

__Example:__ Post "Hello!" to Slack using [Incoming Webhook](https://api.slack.com/incoming-webhooks).
```example:c++
int status;
auto resp = new char[512];

status = HTTP.post("https://hooks.slack.com/services/XXX/YYY/ZZZ",
                   "payload={\"text\": \"Hello!\"}", 26,
                   "Content-Type: application/x-www-form-urlencoded",
                   &resp, 512);

if (String(resp) != "ok")
    Logging.errorlnf("Slack says: %s", status, resp);
```


### put ###
```api:c++
int HTTP::put(String url, const void *payload, size_t payload_size, String headers,
              void *resp, size_t resp_size);
```

Performs a PUT request. It returns HTTP status code or 0 on unexpected errors.
If `resp` is set, the response body is stored in `resp`. Other arguments are:

- `url`: The URL.
- `payload`: The request body or `nullptr`.
- `headers`: The request headers like `"Foo: bar\r\nBaz: 123"`.


### DELETE ###
```api:c++
int HTTP::DELETE(String url, String headers, void *resp, size_t resp_size);
```

Performs a DELETE request. It returns HTTP status code or 0 on unexpected errors.
If `resp` is set, the response body is stored in `resp`. Other arguments are:

- `url`: The URL.
- `headers`: The request headers like `"Foo: bar\r\nBaz: 123"`.
