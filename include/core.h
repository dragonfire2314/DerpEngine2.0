#ifndef CORE_H
#define CORE_H

#if defined(_MSC_VER)
    //  Microsoft 
    #define DERP_API __declspec(dllexport)
#elif defined(__GNUC__)
    //  GCC
    #define DERP_API __attribute__((visibility("default")))
    #define IMPORT
#else
    //  do nothing and hope for the best?
    #define DERP_API
    #pragma warning Unknown dynamic link import/export semantics.
#endif

#endif //CORE_H