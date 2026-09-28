# Directories

Directories are the primary structure for storing data (behind the file itself). As such, I like to keep consistency in my file structures, depending on the project.

As such, I try to follow this common structure:

```text
Repository
├── Build
│   └── *Add a .gitkeep file. Compiled outputs are to be excluded from commits.*
├── Source
│   ├── private
│   │   └── config.json
│   ├── support
│   └── modules
└── .gitignore
```

Of course, based on the language(s) the project uses, other directories and files may be included (i.e. node_modules, app.js for Node.js projects, tsconfig.json for TypeScript, etc.)
