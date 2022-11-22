## Lesson 7 - The graphics pipeline

## The magic of shaders

Rendering in _OpenGL_ has drastically transformed and evolved over the years! As new technology emerges, the API constantly needs to keep up with latest demands and work in a more efficient manner. The newer programmable pipeline introduced shaders, which allows programmers more control over the graphics pipeline.
This pipeline is essentially a sequence of steps executed to transform a 3D model in its raw form into a 2D object displayed on the player's game screen
Previously, during the fixed-function era, all a programmer had was a set of pre-defined routines that manipulated the graphics pipeline automatically. This was less than ideal, and things needed to change. 

## Building the pipeline

Before the _GLSL_ coded shaders can be used and executed, they need to be created and compiled within _OpenGL_, and thus, we have to write extra code in our application that will handle the process of managing the shaders. For this, we will create our own shader class, which will control everything between the _OpenGL_ application and the shaders. 

_More material coming soon..._
