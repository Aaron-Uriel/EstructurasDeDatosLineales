#ifndef ERROR_H
#define ERROR_H

#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_LIBDSTRUCT
    #define LIBDSTRUCT_PUBLIC __declspec(dllexport)
  #else
    #define LIBDSTRUCT_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_LIBDSTRUCT
      #define PUBLIC __attribute__((visibility ("default")))
  #else
      #define PUBLIC
  #endif
#endif

enum ErrorKind {
    ERR_OUT_OF_BOUNDS,
    ERR_NULL_NODE,
    ERR_NULL_DATA_STRUCT
};

enum InfoKind {
    INFO_DATA_STRUCT_WILL_BE_EMPTY,
};


PUBLIC void error(const char *const function_name, enum ErrorKind errkind);
PUBLIC void info(const char *const function_name, enum InfoKind infokind);
PUBLIC int xd(void);

#endif
