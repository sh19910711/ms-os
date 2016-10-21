String
======

### Constructor ###

```api:c++
String::String(const char *);
```


### operator += ###

```api:c++
string& operator += (const string &str);
string& operator += (const char *s);
```


### operator + ###

```api:c++
string& operator + (const string &str);
string& operator + (const char *s);
```


### find ###

```api:c++
size_t String::find(String& str, size_t pos = 0);
size_t String::find(const char *s, size_t pos = 0);
size_t String::find(char c, size_t pos = 0);
```

Finds a content in string and returns the position of the first matched
string. If no matches were found, returns -1.


### substr ###

```api:c++
String String::substr(size_t pos = 0, size_t len = -1);
```

Returns a new string object of a substring of this object.
