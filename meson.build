project('galaxy-desktop', 'c',
    version: '0.1.0',
    default_options: [
        'buildtype=debugoptimized',
        'ndebug=if-release',
        'b_lto=true',
        'c_std=gnu11',
    ],
)

gtk3_version_req   = '>=3.22'
dazzle_version_req = '>=3.28'
polkit_version_req = '>=0.105'

rsrc_base = '/org/perezdecastro/galaxy'
appid_base = 'org.perezdecastro.galaxy'

gtk3_dep   = dependency('gtk+-3.0', version: gtk3_version_req)
dazzle_dep = dependency('libdazzle-1.0', version: dazzle_version_req)

gnome = import('gnome')

gnome_session_path = find_program('gnome-session').path()
gnome_session_sessions_path = run_command('meson/calc-sessions-path', gnome_session_path).stdout().strip()
if gnome_session_sessions_path == ''
    gnome_session_sessions_path = join_paths(get_option('datadir', 'gnome-session', 'sessions'))
endif
message('Installing session file to: ' + gnome_session_sessions_path)

config = configuration_data()
config.set('PROJECT', meson.project_name())
config.set('VERSION', meson.project_version())
config.set('PREFIX', get_option('prefix'))
config.set('GNOME_SESSION_PATH', gnome_session_path)

config.set_quoted('VERSION_STRING', meson.project_version())
config.set_quoted('PROJECT_STRING', meson.project_name())
config.set_quoted('PREFIX_STRING', get_option('prefix'))

config_file = configure_file(output: 'gxy-config.h', configuration: config)
config_file_include_dirs = include_directories('.')

add_project_arguments('-Wall', '-Wextra', language: 'c')

subdir('nebulae')
subdir('panel')
subdir('pkagent')
subdir('session-launcher')
