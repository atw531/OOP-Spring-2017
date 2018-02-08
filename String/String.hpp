#include <cstring>

#ifndef STRING_STRING_HPP
#define STRING_STRING_HPP


class String {
public:

    // Constructor
    String(const char* c)
        : strLength(std::strlen(c)), mString(new char[strLength]) {
        std::strcpy(mString, c);
    }

    // Copy Constructor
    String(const String& s)
        : mString(s.mString), strLength(std::strlen(mString)) {

    }

    // Destructor
    ~String() {
        delete[] mString;
    }

private:
    char* mString;
    int strLength;

};


#endif
