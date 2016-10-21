Logging API
===========

Logging API allows you to Prints messages to serial port and mgmt server.

```note
Log messages to mgmt server are and sent to the server with a heartbeat. On
the other hand, messages to serial port is unbuffered.
```


Normal messages
---------------

### Prints ###

```api:c++
void Logging::print(const char *s);
```

Prints a string.


### printf ###

```api:c++
void Logging::printf(const char *fmt, ...);
```

Prints a formatted string.


### println ###

```api:c++
void Logging::println(const char *s);
```

Prints a string and a new line character.


### printlnf ###

```api:c++
void Logging::printlnf(const char *fmt, ...);
```

Prints a formatted string and a new line character.


Error messages
---------------

Error string is a string starts with `'!'`. Namely, `Logging.errorln("oh my")` and `Logging.println("!oh my")` are equivalent.


### error ###

```api:c++
void Logging::error(const char *s);
```

Prints a error string.


### errorf ###

```api:c++
void Logging::errorf(const char *fmt, ...);
```

Prints a error formatted string.


### errorln ###

```api:c++
void Logging::errorln(const char *s);
```

Prints a error string and a new line character.


### errorlnf ###

```api:c++
void Logging::errorlnf(const char *fmt, ...);
```

Prints a error formatted string and a new line character.
