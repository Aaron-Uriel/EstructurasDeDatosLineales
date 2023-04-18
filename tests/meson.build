menu = executable('menu', 'menu/menu_layout.c',
  link_with : libdstruct,
  include_directories : includes,
)

sstack_test = executable('sstack_test', 'stack.c',
  link_with : libdstruct,
  include_directories : includes,
)
test('sstack_test', sstack_test)

slist_test = executable('slist_test', 'slist.c',
  link_with : libdstruct,
  include_directories : includes,
)
test('slist_test', slist_test)

squeue_test = executable('squeue_test', 'squeue.c',
  link_with : libdstruct,
  include_directories : includes,
)
test('squeue_test', squeue_test)

nodes_test = executable('nodes_test', 'nodes.c',
  link_with : libdstruct,
  include_directories : includes,
)
test('nodes_test', nodes_test)

dqueue_test = executable('dqueue_test', 'dqueue.c',
  link_with : libdstruct,
  include_directories : includes,
)
test('dqueue_test', dqueue_test)