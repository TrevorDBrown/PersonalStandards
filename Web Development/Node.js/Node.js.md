# Node.js
For backend web development, I have a huge affinity for Node.js. Although potentially bulky at times, I like the the package system, npm, and the simplicity of including modules and other components into a project. 

## package.json
For every project, I tend to structure my package.json file as such:

```json
{
  "name": "project-name",
  "version": "0.1.0",
  "description": "Project description.",
  "main": "bin/app.js", // For TypeScript projects.
  //"main": "app.js", // For vanilla Node.js projects.
  "scripts": {
    "removeBin": "rm -rf ./bin/",
    "copyUI": "cp -r ./src/ui/* ./bin/ui/",
    "copyPrivate": "cp -r ./src/private/* ./bin/private/",
    "copySupport": "cp -r ./src/support/* ./bin/support/",
    "build": "tsc && npm run copyUI && npm run copyPrivate && npm run copySupport",
    "cleanAllRun": "npm run removeBin && npm run build && node .",
    "cleanUIRun": "npm run removeUI && npm run copyUI && node .",
    "test": "echo \"Error: no test specified\" && exit 1"
  },
  "repository": {
    "type": "git",
    "url": "git+https://github.com/TrevorDBrown/REPOSITORY_NAME"
  },
  "author": "Trevor D. Brown",
  "license": "MIT",
  "bugs": {
    "url": "https://github.com/TrevorDBrown/REPOSITORY_NAME/issues"
  },
  "homepage": "https://github.com/TrevorDBrown/REPOSITORY_NAME#readme",
  "dependencies": {
    "@fortawesome/fontawesome-free": "^5.15.1",
    "async": "^3.2.0",
    "bootstrap": "^4.5.3",
    "cheerio": "^1.0.0-rc.5",
    "express": "^4.17.1",
    "jquery": "^3.5.1",
    "mysql": "^2.18.1"
  },
  "devDependencies": {
    "@types/async": "^3.2.5",
    "@types/cheerio": "^0.22.23",
    "@types/express": "^4.17.8",
    "@types/jquery": "^3.5.5",
    "@types/mysql": "github:types/mysql",
    "jsdoc": "^3.6.6",
    "ts-node-dev": "^1.0.0-pre.63",
    "typescript": "^4.0.3"
  }
}
```
