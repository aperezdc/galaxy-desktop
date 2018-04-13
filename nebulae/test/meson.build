nebulae_tests = [
    'attention-dialog',
]

nebulae_tests_exe = []
foreach t : nebulae_tests
    nebulae_tests_exe += executable('test-' + t,
        'test-' + t + '.c',
        dependencies: nebulae_dep,
        install: false,
    )
endforeach
