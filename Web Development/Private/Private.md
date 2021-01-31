# Private
"private" is a special directory that contains files that do not need to be submitted to source control, but are necessary for the project. This includes configuration files for services, passwords and credentials, and other working files that are of a private or sensitive nature.

The common structure looks like this:

.
└── private
    ├── config.json
    └── SampleData
        ├── filename.ext
        ├── filename.csv
        └── filename.json

Also, it should be noted that "private" is only used on server-side operations. Currently, I do not use an equivalent directory for client-side operations. 

A sample "private" directory has been placed in this directory to show an example of this in practice.