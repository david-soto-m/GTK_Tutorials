project(
    'tutorial',
    'cpp',
    license: 'Unlicence'
)

sources_basic = ['basic.cpp']
hello_sources = ['Window.cpp','Hello_World.cpp']

gtkdep = dependency('gtkmm-3.0')

wind = include_directories('.')

exe1 = executable(
    'basic',
    sources_basic,
    dependencies: gtkdep,
)

exe2 = executable(
	'hello_world',
	hello_sources,
	dependencies: gtkdep,
	include_directories: wind,
)
