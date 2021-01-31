# Variable Naming
Variable naming is always a challenge in software development. When it comes to naming, I'm in preference of using camelCase, with names that offer clear indication of what the variable is used for.

Considering we're no longer in a world where the smallest file size is the most important factor in writing code, I choose to be more liberal in respect to my variable naming. However, I still believe in conciseness, but clarity. 

Here are some examples of variable names I've used:

##Cross-language
i - index variable for single loops.
x, y, z - indices variables for nested loops, ordered by priority.
variableAsType - a variable that is converted/casted to another type (i.e. JSON to string -> jsonVariableAsString)

##Hungarian Notation 
Occasionally, I apply Hungarian Notation naming, especially with Java, C#, and Visual Basic projects. Some examples include:

intVariable - reference to a variable with an "int" or "integer" data type.
strVariable - reference to a variable with a "string" data type.
dblVariable - reference to a variable with a "double" data type.

##Web Development-specific
entry - reference to an entry in an iterable, if the iterable is a JSON or array.
element - reference to an entry in an iterable, if the iterable is related to actual DOM elements.

someElement - reference to a specific existing DOM element.
someElementDiv - reference to a new DOM element, of the "div" element type.
someElementRow - reference to a new DOM element, of the "div" element type with a "row" class (Bootstrap).
someElementCol - reference to a new DOM element, of the "div" element type with a "col-" class (Bootstrap).
someElementText - reference to the text node of a new DOM element. 
