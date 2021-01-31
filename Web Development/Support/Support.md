# Support
The "support" directory is a directory containing supporting files needed for other modules in the Node.js project.

The common structure looks like:
.
└── support
    ├── module
    │   └── module_support.json
    └── module
        └── filename.ext

If the file does not directly process or compute anything (with the exception of CSS files), it is considered a support file. Therefore, you should never see JavaScript/TypeScript/CSS/etc. in a "support" directory. 

Also, it should be noted that support is only used on server-side operations. Currently, I do not use an equivalent directory for client-side operations. 

A sample "support" directory has been placed in this directory to show an example of this in practice.