nebulae_api_version = '0.0'

nebulae_headers = [
    'nb-application.h',
    'nb-attention-dialog.h',
    'nb-panel.h',
]

nebulae_lib = library('nebulae',

    'nb-application.c',
    'nb-attention-dialog.c',
    'nb-panel.c',
    gnome.mkenums_simple('nb-enums', sources: nebulae_headers),
    gnome.compile_resources('nebulae', 'nebulae.gresource.xml'),

    c_args: [
        '-DAPPID="' + appid_base + '.nebulae"',
        '-DRSRC="' + rsrc_base + '/nebulae/"',
    ],
    version: nebulae_api_version,
    dependencies: dazzle_dep,
)

nebulae_dep = declare_dependency(
    link_with: nebulae_lib,
    include_directories: include_directories('.'),
    dependencies: dazzle_dep,
)

subdir('test')
