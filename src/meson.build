subdir('head_based')
subdir('singly_linked')
subdir('node')
subdir('report')
subdir('doubly_linked')
subdir('statics')


# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_LIBDSTRUCT']

libdstruct = shared_library(
  'dstruct',
  source_files,
  install : true,
  c_args : lib_args,
  gnu_symbol_visibility : 'hidden',
  include_directories : includes
)

