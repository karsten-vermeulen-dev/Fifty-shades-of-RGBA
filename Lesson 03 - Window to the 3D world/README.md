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

Next, we will need to declare two variables required to create our _SDL_ application window and a handy _OpenGL_ context:

```cpp
SDL_Window* window;
SDL_GLContext context;
```

_OpenGL_ and _SDL_ work really well together in that individual attributes can be set using the _SDL_GL_SetAttribute()_ routine. This function will read in the attribute that needs setting and the value to set for that attribute:

```cpp
SDL_GL_SetAttribute(attribute, value);
```

The first attributes that need setting are the RGBA buffer sizes and the total frame buffer size, so that we can have at least **32-bit** color:

```cpp
SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
```

Another attribute that needs to be set is the option to add _double buffering_, which will ensure that when rendering to the screen, two frame buffers are used, one that displays the actual image, and another that is rendered to behind the scenes. Setting this attribute can be done with a value of either **0** or **1**, to _disable_ or _enable_ double buffering, respectively: 

```cpp
SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
```

The next attribute that needs setting is the _OpenGL_ context we wish to use. This can be set to either a _core_ or _compatibility_ context. Set your context to a _core_ context if you don't want to allow any _legacy OpenGL_ code to run. Otherwise, set it to _compatibility_ mode, which we will also do so that we can initially run some older code to get things started up.

```cpp
//Set a core OpenGL context
SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

//Set a compatibility OpenGL context
SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_COMPATIBILITY);  
```

Next, we will set the _OpenGL_ version we wish to use within this context. Now this all depends on what kind of graphics card and drivers your system has. Let's set it to the latest version of **4.6**, but if this fails later on, come back here and try an earlier version. 

```cpp
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
```
 
### Creating the application window and _OpenGL_ context

We are now ready to go ahead and create the application window using the _SDL_CreateWindow()_ function, which takes in arguments that relate to the _window title_, its _x_ and _y_ _position_, the _width_ and _height_, or _resolution_ of the window, and a special _flag_ stating what _type of window_ to create. The function returns a pointer to the newly created window or _NULL_ if it failed to create one. We can use this return value to decide whether to continue with initialization or display an error and call it quits.

```cpp
window = SDL_CreateWindow("Graphics Engine", 
                          SDL_WINDOWPOS_UNDEFINED, 
                          SDL_WINDOWPOS_UNDEFINED, 
                          1280, 720, 
                          SDL_WINDOW_OPENGL);

if (!window)
{
    //Oh well, that's it then, game window could not be created
}
```

The window's _x_ and _y_ position can be set manually or with the use of the flags _SDL_WINDOWPOS_UNDEFINED_ or _SDL_WINDOWPOS_CENTERED_. Choose the ideal resolution that you want (we will go with 1280x720, or HD resolution), and state the type of window you want (we are going for a simple _OpenGL_ window). Check the _SDL_ wiki for more information about the window flags and if you want to combine other flag values, you will need to OR the flags together, like so:

```cpp
window = SDL_CreateWindow("Graphics Engine", 
                          SDL_WINDOWPOS_UNDEFINED, 
                          SDL_WINDOWPOS_UNDEFINED, 
                          1280, 720, 
                          SDL_WINDOW_OPENGL | SDL_WINDOW_FULLSCREEN);
```

We can use the newly created window handle to create the _OpenGL_ context, using the function _SDL_GL_CreateContext_, which takes in the window pointer as an argument and returns a pointer to a valid context or _NULL_ if it failed to create one. This context will now provide us with an _OpenGL_ environment to work within. Think of it like this - in a painter's world, the application window would be their easel and the context the paper they draw on.   

```cpp
context = SDL_GL_CreateContext(window);

if (!context)
{
    //Oh no! No OpenGL context could not be created 
}
```

### Round and round we go

After initializing _SDL_ and _OpenGL_, we are going to require some kind of loop that runs until the application ends, after which we will perform some clean-up tasks. Every application or game has some kind of a loop under the hood, and at its core, it will do three things, namely _clear the screen_, _render great things_, and _swap the frame buffers_. To begin, we will require a flag variable, sensibly named _isAppRunning_, that will determine when the loop should end. 

```cpp
bool isAppRunning { true };

while (isAppRunning)
{
    //Do some wonderful things here...
}
```

_More material coming soon!_

### Destroying the window and _OpenGL_ context when we're done with it

It is always good coding practice to close down all systems that were initialized before, and in our case, we can use the three routines _SDL_GL_DeleteContext()_, _SDL_DestroyWindow()_ and _SDL_Quit()_ to free the _OpenGL_ context from memory, destroy the _SDL_ application window and close down all _SDL_ subsystems, respectively.

```cpp
SDL_GL_DeleteContext(context);
SDL_DestroyWindow(window);
SDL_Quit();
```


