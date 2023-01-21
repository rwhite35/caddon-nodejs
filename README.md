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
Addons are dynamically-linked shared objects written in C++ and bound to NodeJS Addon modules. Node method require() loads bound modules as ordinary JavaScript object. Addons provide an interface between JavaScript and C/C++ libraries. See [C++ Addons](https://nodejs.org/api/addons.html)


# Project Source
The following are non-generated source files for this project.
- binding.gyp: Node-GYP configurations inlcuding C++ source to compile and export.
- calculate.cc: C++ source with namespace, properties, variables and export method(s).
- Main.js: JavaScript code that consumes Node addon modules.
- package.json: the NodeJS build configs for Node instances running the project.
- Note: omits build/ or any generated files. see next section for building


# Configure & Build 
These steps assume the the project was cloned from this repo, and no original source files were changed.
1. Clone the project into a new directory called \"caddon\". The name can be changed but would require editing the `project.json` and `binding.gyp` with the new folder name. Or follow Project Setup steps (below) to create a new module.
```
git clone https://github.com/rwhite35/caddon-nodejs caddon
```

2. Change directories into the clone and confirm both package.json(name) and binding.gyp(target_name) project values match the folder name. The project won't compile if the pathing is off. Node compiler and runtime engine use the directory name for its pathing data. 

3. Clean the project.
```
node-gyp clean
```

4. Configure the project. Will generate new folders and files.
```
node-gyp configure
```

5. Build the project and run Main.js. The compiled module is located under /build/Release directory.
```
node-gyp build 
node Main.js // will output 212.09999999999997
```


# Setup a New Module
Each project is a module. And while one module can have lots for method, Node will only bind one namespace to a module. The following are the steps to create a new module.
1. from the home directory (or wherever Node is accessible), create a new module folder
```
mkdir moduleName && cd ./moduleName
```

2. initialize an new Node project using Node Package Manager (npm). Return through all the setup fields if using default values, or enter values as necessary. This will create a new package.json file and uses the folder name as the project name.
```
npm init
```

3. create a new JavaScript file that will consume the addon module. The file name can be anything but will need changed in package.json if different than the default value (index.js).
```
touch main.js
```

4. create a new C++ file that will define the module namespace, methods etc. This name can be anything but should reflect the objects purpose.
```
touch modwork.cc
```

5. install node-gyp utility. Optionally, use the global flag (-g) to install node-gyp.
```
npm install node-gyp
```

6. create a new Node-GYP configuration file called binding.gyp. See [GYP](https://gyp.gsrc.io/docs/UserDocumentation.md) for file structure and fields name/values.
```
touch binding.gyp
```

At this point the project folder should have a project.json, binding.gyp, main.js, and modwork.cc.  From here follow Configure and Build once done coding up the module.
Cheers 



