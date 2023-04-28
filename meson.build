project('libdstruct', 'c',
  version : '0.0.1',
  default_options : ['warning_level=3'])

includes = include_directories('include')

subdir('include')
subdir('src')
subdir('tests')

# Make this library usable as a Meson subproject.
libdstruct_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with : libdstruct
)

pkg_mod = import('pkgconfig')
pkg_mod.generate(
  name : 'libdstruct',
  filebase : 'libdstruct',
  description : 'Meson sample project.',
  subdirs : 'libdstruct',
  libraries : libdstruct,
  version : '0.0.1',
)

