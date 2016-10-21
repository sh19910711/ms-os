ENV API
=======

ENV API allows you to get environment variables.

```note
Environment variables are loaded on app startup. Namely,
changes in mgmt server are not applied until you restart
the app.
```

Retrieving Environment Variable
-------------------------------

### get ###
```api:c++
int ENV::get(const char *name, int *value);
int ENV::get(const char *name, char *value);
```

Fills the environment variable `name` to `value`.

__Example:__ Read `id` environment variable.
```example:c++
int id;
if (ENV.get("id" &id)) {
    Device.reset("environment variable 'id' is not set");
    /* NOTREACHED */
}

Logging.printlnf("id is %d", id);
```
