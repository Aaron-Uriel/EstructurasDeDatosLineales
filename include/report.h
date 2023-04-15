#ifndef LOG_H
#define LOG_H

#if defined _WIN32 || defined __CYGWIN__
  #ifdef BUILDING_LIBDSTRUCT
    #define LIBDSTRUCT_PUBLIC __declspec(dllexport)
  #else
    #define LIBDSTRUCT_PUBLIC __declspec(dllimport)
  #endif
#else
  #ifdef BUILDING_LIBDSTRUCT
      #define INTERNAL __attribute__((visibility ("internal")))
  #else
      #define INTERNAL
  #endif
#endif

enum ReportKind { DEBUG, INFO, WARN, ERROR };
enum ReportDesc {
    OUT_OF_BOUNDS,
    NULL_NODE,
    NULL_DATA_STRUCT,
    DATA_STRUCT_WILL_BE_EMPTY
};

INTERNAL void report(const char *const function_name,
                     enum ReportKind log_kind, 
                     enum ReportDesc log_desc);

#endif
