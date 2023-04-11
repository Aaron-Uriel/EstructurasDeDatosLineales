menu = executable('menu', 'menu/menu_layout.c',
  link_with : libdstruct,
  include_directories : includes,
)

sstack_test = executable('sstack_test', 'stack.c',
  link_with : libdstruct,
  include_directories : includes,
)

test('libdstruct', sstack_test)
