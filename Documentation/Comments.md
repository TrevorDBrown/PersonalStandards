# Comments

Comments are always made in the context of what is being commented on (obviously). But, the format of those comments may vary based on availability of single-line and block comments in whatever language the file is following.

Comments referencing variables, calls to functions/methods, a method/function signature, and general comments use single line comments. If the comment exceeds the 80th column of your chosen editor, then break the line at or before the 80th column, and continue the comment within another single-line comment below. For example:

```javascript
// This is a test comment in JavaScript/TypeScript.

// This is a very long comment in JavaScript/TypeScript, which intentionally
// exceeds the 80th column limit. The line above stops at column 77.
```

If available, block comments are used at the top of each file (see FileHeaderCommentBlock.md), and where division may be needed between segments of code that are grouped logically within the file. Each line in the comment follows the 80th column rule of single line comments, but does not require a new single-line comment. Furthermore, each line should be tabbed at least once. 

If the file is a TypeScript or JavaScript file, JSDoc is used, which still relies on a block comment. Some examples of block comments include:

```javascript
/*
    This is a JavaScript/TypeScript block comment. As you can see, when we hit 
    the 80th column limit, the comment is continued onto the next line. Some 
    languages support comments in this style, both others do not.
*/

/*
    If this were a JavaScript/TypeScript function, this would be JSDoc syntax.
    @param {string} parameterString - a string parameter.
    @param {int} parameterInt - an int parameter.
*/
```

## Special Comments

There are some types of comments I place in a special category, usually to indicate something that needs to be done or something to check on later. These are:

- TODO: a comment indicating an action that needs to be completed within a segment of code (generally, implementation-related).
- BUG: a comment indicating where a bug is found to occur.
- FIX: a comment indicating a potential solution to an issue to be addressed later.
- TEST: a comment indicating a test that needs to be performed.