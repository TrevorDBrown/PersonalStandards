# Repositories
When it comes to repository creation, I prefer to create a repository for a specific implementation of a project, versus the same repository containing various implementations (i.e. project x, where x is written in C#, but is then written in C++ for reasons). Exceptions to this rule are: 
- Project reimplementation where the existing project will go away (i.e. project x is written in one language, then is rewritten in another language entirely)
- Multi-language projects (i.e. project y, where components of the project are written in one language, and other components are written in other languages.)

## Naming
When naming new repositories, I choose to follow this format: 

*ProductName[-Language]*
- Non-academic projects, with possibly multiple implementations. Exception is "Thesis", which is my Master's thesis repository.

*ClassName-(Project/Assignment/Homework)(Number of Assignment)* 
- Academic projects for classes I'm taking for school (undergraduate and graduate)

## Branching
Each project I create contains two branches:
- master (or main) - the primary branch of the project, which is a realease-ready, stable version of the project.
- development - the branch of the project where I develop new features and changes to the project. I try not to update master without first making such changes in the development branch first, in order to prevent merge conflicts later on.

## .gitignore
A template of the .gitignore file I use for many repositories can be found in this directory. Basically, I ignore all system files for Windows, macOS, and Windows. From there, common editor-specific files (i.e. .vscode, etc.) are added. For languages such as Node which use a dedicated folder for dependencies (i.e. node_modules), those are also added. Finally, private/sensitive content directories and directories for builds (i.e. src/private, bin, etc.) are ignored.