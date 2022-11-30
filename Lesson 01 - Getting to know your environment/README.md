## Lesson 1 - Getting to know your environment

## The _Open Graphics Library_

### What is _OpenGL_?

_OpenGL_ stands for _Open Graphics Library_ and is a low level API that allows graphics programmers a way of 'talking' to the graphics card. It was released in 1992 by _Silicon Graphics_ and used to fall under the _OpenGL Architecture Review Board_, or _ARB_, but now belongs to the _Khronos Group_. Being a cross platform API, it can run on _Windows_, _Linux_ and, until recently, _macOS_ and is used for making games, simulations and 3D visualization applications. _OpenGL_ is not a software package, or SDK, but rather a graphics standard or implementation limited only by your graphics card and operating system. 

💡 _The Open in OpenGL refers to it being an open standard instead of open-source_

All graphics functionality lies inside _**graphics drivers**_, which are written and supplied by the hardware vendor. Programs made with _OpenGL_ will communicate with these drivers accordingly. In the past, when 3D graphics were less sophisticated, _OpenGL_ offered programmers a _**fixed function pipeline**_, which was merely a specific set of pre-defined graphics routines. Today, the _**programmable pipeline**_ is used, where developers have more control on how their objects are rendered and used within an _OpenGL_ environment. <br>
The _OpenGL_ specification, as well as other graphics-related information, can be found [HERE](https://www.opengl.org)

### Who are these _Khronos_ people?

The _Khronos Group_ is a non-profit consortium that oversees the development of _OpenGL_ and its other APIs. It consists of over 100 companies that help set the graphical standard for _OpenGL_ as well as APIs such as _OpenGL ES_, _WebGL_, _OpenCL_, and the newly formed _OpenXR_ APIs. Their latest API, _Vulkan_, is believed to eventually replace _OpenGL_, but not for a very long time and so, for now, it is being designed to work alongside it.

### The graphics drivers

These are special files stored on the hard drive that communicate with the graphics hardware to perform certain graphical tasks. They essentially _drive_ the graphics card to render game worlds for your game or 3D scenes for your visualization applications. Drivers come in many different forms and file types, more commonly they exist as _.dll_ files on _Windows_ systems. <br>
Back in the days of early game development, games would ship with their own dedicated graphics driver software along with the game. Each driver file was specific to the game, operating system and graphics hardware. If hardware or operating systems updated, a large amount of game code would need to be changed as well. This was a lot of work! <br>
During the early 90s a _hardware abstraction layer_ was formed, which took over the graphics responsibilities from the game code such that games could be developed in a less hard-coded format and had direct access to the graphics hardware. These abstraction layers came in the form of _Application Programming Interfaces_ (APIs) such as _OpenGL_, _Direct3D_, _Glide_, _SDL_, etc.

💡 _Each graphics card manufacturer will label their drivers differently_.

### Who's driving the games today?

Today, all graphics card manufacturers ship their products with all the relevant drivers. When a game runs, it will access the drivers through the operating system and then communicate directly with the graphics hardware via those drivers. Current technology, such as the newer _Vulkan_ API, are allowing games to skip past the drivers and access the hardware directly. Most graphics cards today have support for _OpenGL_ and _DirectX_. _OpenGL_ drivers ship with the card and _DirectX_ drivers come packaged with the _Windows_ operating system. <br>
On _Windows_ systems, the _OpenGL_ application will generally load the _opengl32.dll_ file into memory, which in turn searches for the graphics card drivers that contain code that is invoked by the application, allowing the game to communicate with the graphics card.

💡 _The latest cards will have support for Vulkan_.

### Ye olde fixed function pipeline

This is a set of predefined functionality that was used in the early days of _OpenGL_ to create 3D applications and was used in older versions of _OpenGL_, up until version **3.0**, and is now known as _Legacy OpenGL_. _OpenGL_ had a set way of doing things via these statically pre-defined routines and developers had little freedom in terms of rendering. The CPU was predominantly used for all draw calls and calculations.

💡 _The fixed function pipeline can be good for learning OpenGL as a beginner, but it is recommended to stay away from this form of graphics programming as much as possible_.

| OpenGL version  | Release date | Notes |
| ------------- | ------------- | ------------- |
| _OpenGL 1.0_  | 1992 | The initial release of the API |
| _OpenGL 1.1_  | 1997 | The first update |
| _OpenGL 1.2_  | 1998 |  |
| _OpenGL 1.3_  | 2001 |  |
| _OpenGL 1.4_  | 2002 |  |
| _OpenGL 1.5_  | 2003 | Introduced the vertex buffer object |
| _OpenGL 2.0_  | 2004 | Introduced the GLSL shader language |
| _OpenGL 2.1_  | 2006 | The last release before the API was modernized |

### The shiny, new programmable pipeline

This is the modern and current method of creating 3D applications and games with _OpenGL_ and offers more control, flexibility and power than the fixed function alternative. From version **3.0** onwards, the use of _shaders_, particularly vertex and fragment shaders, became more predominant. Here, the GPU is predominantly used for all draw calls and calculations. _OpenGL 3.0_ saw the beginning of the _Deprecation Model_, where parts of the core API were removed, and the API could be set in either of two contexts, ie a _backward-compatible_ or _forward compatible_ context. 

| OpenGL version  | Release date | Notes |
| ------------- | ------------- | ------------- |
| _OpenGL 3.0_  | 2008 | The initial release of the modern API |
| _OpenGL 3.1_  | 2009 |  |
| _OpenGL 3.2_  | 2009 | Introduced core & compatibility contexts |
| _OpenGL 3.3_  | 2010 |  |
| _OpenGL 4.0_  | 2010 |  |
| _OpenGL 4.1_  | 2010 |  |
| _OpenGL 4.2_  | 2011 |  |
| _OpenGL 4.3_  | 2012 |  |
| _OpenGL 4.4_  | 2013 |  |
| _OpenGL 4.5_  | 2014 |  |
| _OpenGL 4.6_  | 2017 | Now with support for SPIR-V shaders |

### It has to be in context

Before making use of _OpenGL_, it has to be set to a certain state or context. 

- _**Core Profile**_ - This context only enables the modern core from **3.3** onwards up until the current version **4.6**. No _Legacy OpenGL_ functionality is supported
- _**Compatibility Profile**_ - This context supports the older fixed function pipeline, and gives developers access to the older and newer functionalities of the API

💡 _OpenGL cannot create its own context, nor can it create a window to render in, which is why applications such as SDL, SFML, GLFW, freeglut, etc. are used to perform such tasks_

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

<hr>

## The _Simple DirectMedia Layer_ library

The _Simple DirectMedia Layer_, or _SDL_, library is a cross-platform software development library that allows programmers to utilize its tools to render 2D images on screen. Beyond that, it is also capable of creating and managing game windows, input control, and has image, audio and networking capabilities as well. Our interest in the API is only for the window management and input, since _OpenGL_ cannot create or manage an application window, neither can it manage any input control. Moreover, we will need _SDL_ to work together with _OpenGL_ to create and manage what is known as an _OpenGL context_. <br>

Click [HERE](https://www.libsdl.org) for more information about _SDL_.

<hr>

## A good folder structure

_More info regarding good folder structures coming soon..._

### Using external libraries

Each external library you download for a _Windows_ environment generally comes with _header_ (**.h**), _static library_ (**.lib**) and _dynamic library_ (**.dll**) files.
The header files contain all the class and function declarations used during compilation, the static library files contain the functions used during the linking process of the application, and the dynamic library files contain all the functions used during the runtime of the application.

💡 _The DLL files should always be included when the application ships_.

