{
  'variables': {
    'app_name':    'Plexability',
    'app_version': '0.1.0',
    # Other targets
    'main_lib_name':   'libplexability',
    'mac_helper_name': '<(app_name) Helper',

    'cef_build': 'Debug',

    # Pathing
    # =======
    'app_sources_path':      'app',
    'core_sources_path':     'core',
    'chromium_sources_path': 'chromium',

    'mac_app_sources_path': 'mac/app',
    'mac_resources_path':   'mac/resources',

    'mac_helper_app_sources_path': 'mac/chromium_helper/app',
    'mac_helper_resources_path':   'mac/chromium_helper/resources',

    'cef_path': 'extern/cef',
  },

  # Global Defaults
  # ===============
  'target_defaults': {
    'include_dirs': [
      '<(cef_path)', # Bleh, CEF forces an include/ prefix.
    ],

    'defines': [
      'USING_CEF_SHARED',
    ],

    'xcode_settings': {
      'SDKROOT':                      'macosx',
      'MACOSX_DEPLOYMENT_TARGET':     '10.7',
      'GCC_C_LANGUAGE_STANDARD':      'c99',
      'CLANG_CXX_LANGUAGE_STANDARD':  'c++0x',
      'CLANG_CXX_LIBRARY':            'libc++',
      'GCC_PREFIX_HEADER':            '<(core_sources_path)/prefix.pch',
      'GCC_PRECOMPILE_PREFIX_HEADER': 'YES',
    },
  },

  'targets': [
    # Shared Core
    # ===========
    {
      'target_name': '<(main_lib_name)',
      'type':        'shared_library',

      'dependencies': [
        'libcef_wrapper',
      ],

      'sources': [
        '<!@(git ls-files <(app_sources_path))',
        '<!@(git ls-files <(core_sources_path))',
        '<!@(git ls-files <(chromium_sources_path))',
      ],

      'link_settings': {
        'libraries': [
          'extern/cef/<(cef_build)/libcef.dylib',
        ],
      },

      'conditions': [
        # Mac Specific
        # ------------
        ['OS=="mac"', {
          'xcode_settings': {
            'INSTALL_PATH': '@executable_path',
          },

          'dependencies': [
            'Chromium Embedded Framework.framework',
          ],

          'postbuilds': [
            {
              'postbuild_name': 'Fix CEF.framework link',
              'action': [
                'install_name_tool',
                '-change',
                '@executable_path/libcef.dylib',
                '@loader_path/Chromium Embedded Framework.framework/Libraries/libcef.dylib',
                '${BUILT_PRODUCTS_DIR}/${EXECUTABLE_PATH}',
              ],
            },
          ],
        }],
      ],
    },


    # Main Application
    # ================
    {
      'target_name': '<(app_name)',
      'type':        'executable',

      'dependencies': [
        '<(main_lib_name)',
      ],

      'conditions': [
        # Mac Specific
        # ------------
        ['OS=="mac"', {
          'mac_bundle': 1,
          'xcode_settings': {
            'PRODUCT_VERSION':      '<(app_version)',
            'INFOPLIST_FILE':       '<(mac_resources_path)/Info.plist',
            'INFOPLIST_PREPROCESS': 'YES',
            'COMBINE_HIDPI_IMAGES': 'YES',
            'OTHER_LDFLAGS':        '-headerpad_max_install_names', # *grumble*
          },

          'dependencies': [
            '<(mac_helper_name)',
          ],

          'sources': [
            '<!@(git ls-files <(mac_app_sources_path))',
          ],

          'link_settings': {
            'libraries': [
              '$(SDKROOT)/System/Library/Frameworks/Cocoa.framework',
            ],
          },

          # ### CEF.framework
          'copies': [
            {
              'destination': '<(PRODUCT_DIR)/<(app_name).app/Contents/Frameworks/',
              'files': [
                '<(PRODUCT_DIR)/<(main_lib_name).dylib',
                '<(PRODUCT_DIR)/<(mac_helper_name).app',
                '<(PRODUCT_DIR)/Chromium Embedded Framework.framework',
              ],
            },
          ],
          'postbuilds': [
            {
              'postbuild_name': 'Fix <(main_lib_name).dylib link',
              'action': [
                'install_name_tool',
                '-change',
                '@executable_path/<(main_lib_name).dylib',
                '@executable_path/../Frameworks/<(main_lib_name).dylib',
                '${BUILT_PRODUCTS_DIR}/${EXECUTABLE_PATH}',
              ],
            },
            {
              'postbuild_name': 'Fix CEF.framework link',
              'action': [
                'install_name_tool',
                '-change',
                '@executable_path/libcef.dylib',
                '@executable_path/../Frameworks/Chromium Embedded Framework.framework/Libraries/libcef.dylib',
                '${BUILT_PRODUCTS_DIR}/${EXECUTABLE_PATH}',
              ],
            },
          ],
        }],
      ],
    },


    # CEF C++ Interface
    # =================
    {
      'target_name': 'libcef_wrapper',
      'type':        'static_library',

      # cef_paths.gypi doesn't follow gyp conventions and define paths with a
      # _paths suffix, so we lose all the relative pathing behavior.  Instead,
      # we'll just glom in everything and let the linker take care of cruft.
      'sources': [
        '<!@(git ls-files <(cef_path)/libcef_dll)',
      ],
    },
  ],

  'conditions': [
    # Mac Specific
    # ============
    ['OS=="mac"', {
      'targets': [
        # TODO: Submit a patch to CEF so that it generates a proper framework
        {
          'target_name': 'Chromium Embedded Framework.framework',
          'type':        'none',

          'copies': [
            {
              'destination': '<(PRODUCT_DIR)/Chromium Embedded Framework.framework/',
              'files': [
                '<(cef_path)/Resources/',
              ],
            },
            {
              'destination': '<(PRODUCT_DIR)/Chromium Embedded Framework.framework/Libraries',
              'files': [
                '<(cef_path)/<(cef_build)/libcef.dylib',
                '<(cef_path)/<(cef_build)/ffmpegsumo.so',
              ],
            },
          ],
        },

        {
          'target_name': '<(mac_helper_name)',
          'type':        'executable',

          'dependencies': [
            '<(main_lib_name)',
          ],

          'mac_bundle': 1,
          'xcode_settings': {
            'INFOPLIST_FILE':       '<(mac_helper_resources_path)/Info.plist',
            'INFOPLIST_PREPROCESS': 'YES',
            'COMBINE_HIDPI_IMAGES': 'YES',
            'OTHER_LDFLAGS':        '-headerpad_max_install_names', # *grumble*
          },

          'sources': [
            '<!@(git ls-files <(mac_helper_app_sources_path))',
          ],

          'postbuilds': [
            {
              'postbuild_name': 'Fix <(main_lib_name).dylib link',
              'action': [
                'install_name_tool',
                '-change',
                '@executable_path/<(main_lib_name).dylib',
                '@executable_path/../../../<(main_lib_name).dylib',
                '${BUILT_PRODUCTS_DIR}/${EXECUTABLE_PATH}',
              ],
            },
            {
              'postbuild_name': 'Fix CEF.framework link',
              'action': [
                'install_name_tool',
                '-change',
                '@executable_path/libcef.dylib',
                '@executable_path/../../../Chromium Embedded Framework.framework/Libraries/libcef.dylib',
                '${BUILT_PRODUCTS_DIR}/${EXECUTABLE_PATH}',
              ],
            },
          ],
        }
      ]
    }],
  ],
}
