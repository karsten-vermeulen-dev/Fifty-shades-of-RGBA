## Lesson 1 - Getting to know your environment

## The _Open Graphics Library_

### What is _OpenGL_?

_OpenGL_ stands for _Open Graphics Library_ and is a low level API that allows graphics programmers a way of 'talking' to the graphics card. It was released in 1992 by _Silicon Graphics_ and used to fall under the _OpenGL Architecture Review Board_, or _ARB_, but now belongs to the _Khronos Group_. Being a cross platform API, it can run on _Windows_, _Linux_ and, until recently, _macOS_ and is used for making games, simulations and 3D visualization applications. _OpenGL_ is not a software package, or SDK, but rather a graphics standard or implementation limited only by your graphics card and operating system. 

💡 _The Open in OpenGL refers to it being an open standard instead of open-source_

All graphics functionality lies inside _**graphics drivers**_, which are written and supplied by the hardware vendor. Programs made with _OpenGL_ will communicate with these drivers accordingly. In the past, when 3D graphics were less sophisticated, _OpenGL_ offered programmers a _**fixed function pipeline**_, which was merely a specific set of pre-defined graphics routines. Today, the _**programmable pipeline**_ is used, where developers have more control on how their objects are rendered and used within an _OpenGL_ environment. <br>
The _OpenGL_ specification, as well as other graphics-related information, can be found [HERE](https://www.opengl.org)


<hr>

## An introduction to _Visual Studio_

### What is this _Visual Studio_ exactly?

This is an integrated development environment, or IDE, developed by _Microsoft_, used for writing, compiling, and linking your _C++_ code. Of course, you can use it to code in other languages as well, and the IDE comes packed with many tools to make the chore of software development so much easier. The built-in _intellisense_ will assist developers with syntax highlighting, code prediction and many different debugging tools to help find and fix issues in the code. We are only going to be using a small portion of _Visual Studio_'s capabilities, which is why the _Community 2022_ edition is more than enough for our purposes

### Where can I find _Visual Studio_?

_Visual Studio_ comes in three flavors, namely _Professional_, _Enterprise_ and _Community_, the latter being free, and can be downloaded [HERE](
https://www.visualstudio.com). Click on _Download Visual Studio_ and select the _Community 2022_ edition, which will download a setup EXE file for you to run in order to install the IDE.

### Managing the installation

After installing _Visual Studio_, you can use the _Visual Studio Installer_ to modify or update your installation. Simply search for this on your machine and run it. You can have multiple versions of _Visual Studio_ installed side-by-side, which can be managed separately. <br>
Inside the _Visual Studio Installer_, in the _Community 2022_ box, click on **Modify** to make changes to your installation. Under the _Workloads_ tab, make sure to select the **Desktop development with C++** box, which should provide you with all the bog-standard _C++_ tools you will need. Click on **Modify** in the bottom right corner of the screen to apply these changes. <br>
If there are specific components you wish to install, then simply click on the _Individual components_ tab at the top of the installer. Here, you can install specific compilers, language extras, debugging tools, plugins, and much more. It is also here that _Windows_ developers can choose to install specific _Windows Software Development Kits_, or _SDKs_. You should have default SDKs selected for installation, but if you’re after something specific, select it, as well as any other components and click on **Modify** to install them.

### Tips, tricks & shortcuts

| Shortcut  | What it does |
| ------------- | ------------- |
| CTRL-D | Duplicates a line of code |
| CTRL-KC | After selecting a block of code, use this to comment out the entire segment |
| CTRL-KU | You can also uncomment an entire segment of code using this shortcut |
| CTRL-KD | Based on the formatting options set, this will format your code, such that it is indented, aligned and spaced out accordingly |
| ALT-UP/DOWN arrows | Place the mouse cursor next to line of code and use this shortcut to move the entire line up/down the page |
| TAB | Useful for auto-filling code segments such as loops, branches, switch statements, etc. |
| ALT-mouse drag | This will allow you to select rectangular blocks of code |

_More tips, tricks & shortcuts coming soon..._

## A good folder structure

_Material coming soon..._

