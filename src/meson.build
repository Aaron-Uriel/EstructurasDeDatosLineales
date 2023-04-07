subdir('head_based')
subdir('node')

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_LIBDSTRUCT']

libdstruct = shared_library(
  'libdstruct',
  source_files,
  install : true,
  c_args : lib_args,
  gnu_symbol_visibility : 'hidden',
  include_directories : includes
)

