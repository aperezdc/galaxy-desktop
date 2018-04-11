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
