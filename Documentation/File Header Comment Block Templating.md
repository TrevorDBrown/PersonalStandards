# File Header Comment Block Templating

Each project I work on contains a file header comment - a comment at the top of the file which explains what the file is for, and a history of changes made to the file.

For consistency across projects and implementations, the following format is desired:

If the language the code file is for supports block comments, a block comment is initiated with the comment text. Otherwise, each line has the standard single line comment character(s).

The comments in the file header look as follows:

```text
-------------------------------------------------------------------------------
ProjectName
(c)YYYY[-YYYY] Trevor D. Brown. All rights reserved.
Distributed under the (License Name) license.

filename.ext - a description of the file and what it is used for.
Additional notes that may be useful.

History: 
[MM/DD/YYYY] - Trevor D. Brown
- Bulleted list (using dashes as bullets) explaining each update to the file.
-------------------------------------------------------------------------------
```
