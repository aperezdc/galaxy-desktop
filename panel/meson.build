galaxy_panel_exe = executable('galaxy-panel',
    config_file,
    'gxy-panel-main.c',
    'gxy-panel-application.c',

    gui_app: true,
    dependencies: nebulae_dep,
    include_directories: config_file_include_dirs,

    install_dir: get_option('bindir'),
    install: false,  # TODO: Change when panel is useable.
)
