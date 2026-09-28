# File Header Comment Block Templating

Each project I work on contains a "file header comment": a comment at the top of the file which explains the purpose of the file.

For consistency across projects and implementations, the following format is desired:

If the language the code file is for supports block comments, a block comment is initiated with the comment text. Otherwise, each line has the standard single line comment character(s).

The comments in the file header look as follows:

```text
-------------------------------------------------------------------------------
Project Name
(c)YYYY[-YYYY] Trevor D. Brown. All rights reserved.
Distributed under the (License Name) license.

File:       filename.ext
Purpose:    A brief description of the file's purpose, along with additional notes that may be useful.
-------------------------------------------------------------------------------
```
