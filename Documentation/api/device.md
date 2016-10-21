Device API
==========

Device API allows you to manipulate the device.

Restarting
----------

### reset ###
```api:c++
NORETURN void Device::reset();
NORETURN void Device::reset(const char *errmsg);
```

Restarts the app. It never returns.

If `errmsg` is set, it does `Logging.errorln(errmsg)` before
restarting.

__Example:__ Restart the app if an environment variable is not set.
```example:c++
int id;
if (ENV.get("id" &id)) {
    Device.reset("environment variable 'id' is not set");
    /* NOTREACHED */
}
```
