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

configure_file(
    input: 'galaxy-desktop.in',
    output: 'galaxy-desktop',
    configuration: config,
    install_dir: get_option('bindir'),
)

configure_file(
    input: 'galaxy-desktop.desktop.in',
    output: 'galaxy-desktop.desktop',
    configuration: config,
    install_dir: join_paths(get_option('datadir'), 'xsessions')
)

install_data('galaxy-desktop.session', install_dir: gnome_session_sessions_path)
