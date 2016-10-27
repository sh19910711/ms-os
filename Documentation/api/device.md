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


### update ###
```api:c++
NORETURN void Device::update(unsigned long deployment_id);
```

Downloads and launches app to the speicified `deployment_id`. The
current running app will be killed.


### get_device_secret ###
```api:c++
const char *Device::get_device_secret();
```

Returns the device's device_secret.


### get_server_url ###
```api:c++
const char *Device::get_server_url();
```

Returns the codestand server URL.


### get_deployment_id_on_boot ###
```api:c++
unsigned long Device::get_deployment_id_on_boot();
```

Returns the deployment id on boot.
