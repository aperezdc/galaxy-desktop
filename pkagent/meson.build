galaxy_pkagent_res = gnome.compile_resources(
    'gxy-pkagent-resources',
    'gxy-pkagent.gresource.xml',
)

galaxy_pkagent_exe = executable('galaxy-pkagent',
    config_file,
    galaxy_pkagent_res,
    'gxy-auth-panel.c',
    'gxy-pkagent-main.c',

    gui_app: true,
    c_args: [
        '-DAPPID="' + appid_base + '.pkagent"',
        '-DRSRC="' + rsrc_base + '/pkagent/"',
    ],
    dependencies: [
        nebulae_dep,
        dependency('polkit-agent-1', version: polkit_version_req),
        dependency('polkit-gobject-1', version: polkit_version_req),
    ],

    install_dir: get_option('bindir'),
    install: true,
)
