# caddon-nodejs

A toy example demonstrating NodeJS Addons for C++ interoperability using C++ V8 library. This project builds using NodeJS Generate-Your-Project(node-gyp) tool chain. Node executed `node fileName.js` JavaScript methods call exported modules bound to target C++ functionality. Addon interface can pass values between JavaScript and C++.


# Requirements
- GNU Compiler Collection (clang v14.0.0)
- NodeJS v17.4.0 (npm 8.3.1)
- Node-GYP v9.3.1
- JavaScript ES6
- Python 3.9.6 (Node-GYP binaries)
- TextEdit,  VisualStudio, or Vim


# About Node C++ Addons
Addons are dynamically-linked shared objects written in C++ and bound to NodeJS modules. The Node require() function loads addons as ordinary Node.js modules. Addons provide an interface between JavaScript and C/C++ libraries.
See [C++ Addons](https://nodejs.org/api/addons.html)


# Project Source
The non-generated source files for this project are:
- binding.gyp: Node-GYP configurations inlcuding C++ source to compile and export.
- calculate.cc: C++ module with namespace, properties, variables and export method.
- Main.js: JavaScript code that consumes the C++ addon module.
- package.json: the NodeJS build configs for NodeJS instances running the project.


# Configure & Build 
These steps assume the the project was cloned from this repo, and all prerequisites are filled.
1. Clone the project into a new directory called \"caddon\". This name can be changed but would require editing the original files project.json and binding.gyp to reflect the directory name. Or follow Project Setup steps (below) to create a new module.
`git clone https://github.com/rwhite35/caddon-nodejs caddon`

2. Confirm the folder/name fields in both package.json(name) and binding.gyp(target_name) both match the real projects folder name. Node compiler as well as the engine uses the directory for its pathing data. 

3. Clean the current build with the following
`node-gyp clean`

4. Configure the project with new generated files that are specific to your environment.
`node-gyp configure`

5. Build the project and run Main.js
`node-gyp build`
`node Main.js` // will output 212.09999999999997


# Setup a New Module
Each project is a module. And while one module can have lots for method, Node will only bind one namespace to a module. The following are the steps to create a new module.
1. from the home directory (or wherever Node is accessible), create a new module folder
`mkdir moduleName && cd ./moduleName`

2. initialize an new Node project using Node Package Manager (npm). Return through all the setup fields if using default values, or enter values as necessary. This will create a new package.json file and uses the folder name as the project name.
`npm init`

3. create a new JavaScript file that will consume the addon module. The file name can be anything but will need changed in package.json if different than the default value (index.js).
`touch main.js`

4. create a new C++ file that will define the module namespace, methods etc. This name can be anything but should reflect the objects purpose.
`touch modwork.cc`

5. install node-gyp utility. Optionally, use the global flag (-g) to install node-gyp.
`npm install node-gyp`

6. create a new Node-GYP configuration file called binding.gyp. See [GYP](https://gyp.gsrc.io/docs/UserDocumentation.md) for file structure and fields name/values.
`touch binding.gyp`

At this point the project folder should have a project.json, binding.gyp, main.js, and modwork.cc.  From here follow Configure and Build once done coding up the module.
Cheers 



