# Lesson 3 - Window to the 3D world

## The first little graphics app

### Downloading _SDL_

We are going to be needing the assistance of _SDL_ to set up our _OpenGL_ context and applpication window. Head over [HERE](https://github.com/libsdl-org/SDL/releases) to find the latest release of the API. Make sure you select the _SDL2-devel-...-VC.zip_ and download that. Unzip the development files and place them in a folder called _Libraries_, under a sub-folder called _SDL_. <br> 
Because sometimes the files seem to be all over the place, it's a good suggestion to organise them in a _bin_, _include_ and _lib_ folder. The _bin_ folder should contain all the _runtime files_ (**.dll**), the _include_ folder all the _header files_ (**.h**) and the _lib_ folder the _static library files_ (**.lib**).

### Setting up _OpenGL_

Remember, _OpenGL_ is a graphics standard and not and SDK, so not much downloading and setup is needed for the API. The very basic, and extremely old, development files already ship with the _Windows_ operating system as well as _Visual Studio_ when it's installed. The **gl.h** and **opengl32.lib** files are located in _Visual Studio_'s SDK folders. The **opengl32.dll** runtime library file is located in the _Windows_ system folders. For modern _OpenGL_ usage and extended features, we are going to make use of our graphics card drivers, which is where all of the latest _OpenGL_ functionality lives. So, remember to always keep your graphics drivers up to date. But, more on this later. For now, the basic development files will suffice.

### Initializing _SDL_

Okay, so back in our _Visual Studio_ project, let's return to our _main.cpp_ source file. In order to use _SDL_ and _OpenGL_, we need to include the relevant header files, like so:

```cpp
#include <Windows.h>
#include <gl/GL.h>
#include <SDL.h>
```

💡 _**Windows.h** needs to be included before **gl.h** as there are many dependencies lurking_

Now, we can initialize _SDL_ by calling its _SDL_Init()_ function, which is required to start up the API. This function can be passed various arguments based on what _SDL_ components you want to setup. It will return an _int_ value based on if it succeeded or failed. A return value of **0** means it succeeded and a **-1** means it failed. _SDL_ pretty much runs on anything, including a toaster, so the chances of the initialize function failing are slim. <br>

An effective way to use this function would be to call it within a handy _if-statement_, like so:

```cpp
if (SDL_Init(SDL_INIT_EVERYTHING) == -1)
{
    //SDL did not initialize properly, so print a friendly error message and run for the hills
}
```

💡 _You don't have to initialize the entire SDL system, you could also initialize individual components. Be sure to check out the SDL wiki for more info_.
