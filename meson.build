project('galaxy-session', version: '0.1.0')

gnome_session_path = find_program('gnome-session').path()
gnome_session_sessions_path = run_command('meson/calc-sessions-path', gnome_session_path).stdout().strip()
if gnome_session_sessions_path == ''
    gnome_session_sessions_path = join_paths(get_option('datadir', 'gnome-session', 'sessions'))
endif
message('Installing session file to: ' + gnome_session_sessions_path)

config = configuration_data()
config.set('project', meson.project_name())
config.set('version', meson.project_version())
config.set('prefix', get_option('prefix'))
config.set('gnome_session_path', gnome_session_path)

subdir('session-launcher')
