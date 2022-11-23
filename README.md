# Fifty shades of RGBA
This course covers the introductory topics of _OpenGL_ and _GLSL_ and will teach students how to create a 3D scene with a camera, 3D objects, lighting, texturing, and text rendering. Each lesson covers a different topic and is broken down into theory and code samples.

### [Lesson 0 - Prologue](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%200%20-%20Prologue)

_A very brief introduction to the course, who the target audience is, and what makes this course so special_.

### [Lesson 1 - Getting to know your environment](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2001%20-%20Getting%20to%20know%20your%20environment)

_You will be introduced to the OpenGL API, including where and why it is being used. You will also learn all about Visual Studio, where to download it and how to manage the IDE. Some tips and tricks will be covered to help you write code faster. Finally, knowing how and where all your folders and files are structured and stored is essential before we begin developing the project_.

### [Lesson 2 - A comprehensive introduction to graphics](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2002%20-%20A%20comprehensive%20introduction%20to%20graphics)

_This will be a solid introduction to graphics and shaders, where you will learn all about the evolution of graphics, especially in games, and how far we have come in terms of hardware and software. You will gain a deeper understanding of the graphics pipeline, graphics cards and their drivers, and graphics APIs, especially OpenGL_.

### [Lesson 3 - Window to the 3D world](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2003%20-%20Window%20to%20the%203D%20world)

_In this lesson, you will learn how to download and link the SDL library, which will aid you in creating and managing your application window. You will also add specific SDL code to your projects to create the main window as well as create the OpenGL rendering context. Finally, a main application loop will be added, wherein you will add some primitive OpenGL functions just to get a basic quad to render on screen_.

### [Lesson 4 - Gimme some input](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2004%20-%20Gimme%20some%20input)

_Here, you are going to learn how the input polling process works and how different input events are triggered and dealt with. You will gain insight into reading keyboard and mouse input_.

### [Lesson 5 - Start your graphics engines!](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2005%20-%20Start%20your%20graphics%20engines!)

_This is where you will learn all about game engines with the intention to create your own graphics engine from scratch. The Singleton Design Pattern will be taught and used from this point forth to create manager objects for your engine. You will begin creating managers to encapsulate all of your screen and input functionality_.

### [Lesson 6 - _OpenGL_...opened up](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2006%20-%20OpenGL...opened%20up)

_Continuing building upon your small graphics engine, you are going to learn all about extension functionality in OpenGL, particularly the difficult method of manually loading extension functions from the graphics driver, as well as the simpler method of using the GLAD 2.0 library. Finally, you are going to learn about some debugging techniques that can be effectively utilized in OpenGL_. 

### [Lesson 7 - The graphics pipeline](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2007%20-%20The%20graphics%20pipeline)

_In this lesson, you will be delving into the graphics pipeline and gain a deeper understanding of vertex and fragment shaders, ending off with a good knowledge of GLSL_.

### [Lesson 8 - Sending data down the pipeline I](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2008%20-%20Sending%20data%20down%20the%20pipeline%20I)

_Here, you will learn how to pass data to your shaders, in the form of uniforms, vertex attributes and Vertex Buffer Objects. You will start by creating a single VBO to store and pass to the shader all of your position and color data for a simple shape_. 

### [Lesson 9 - Sending data down the pipeline II](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2009%20-%20Sending%20data%20down%20the%20pipeline%20II)

_Now, you will progress to creating multiple VBOs for your data, before learning all about Vertex Array Objects and Index Buffer Objects. Finally, you will add code to your newly created Shader class to further control data transfer between the OpenGL application and the shaders_.

<hr>

### [Lesson 10 - Some dreaded math revision](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2010%20-%20Some%20dreaded%20math%20revision)

_To prove that math need not be too intimidating, you will do a quick refresher on the mathematical topics that are essential for a graphics course. These topics include trigonometry and linear algebra, where you will further delve the rabbit hole to (re)discover things like vectors and matrices and recap on the three main transformations, namely translation, rotation and scale. Ending the lesson will be  an introduction to GLM, the math helper library designed to work alongside OpenGL._

### [Lesson 11 - Lost in transformation I](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2011%20-%20Lost%20in%20transformation%20I)

_For the first part of this double feature, you will be introduced to the three main OpenGL and GLSL types of transformations, namely the modelling, viewing and projection transformations. You will focus predominantly on the first two and build classes to encapsulate their functionality._

### [Lesson 12 - Lost in transformation II](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2012%20-%20Lost%20in%20transformation%20II)

_For part deux, you continue down the exciting road that is transformations by learning about perspective division, the depth buffer, and viewports, and end off finding out about the two main projections, namely orthographic and perspective views, and how they will come into play in your 3D application._ 

### [Lesson 13 - Creating a 3D world](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2013%20-%20Creating%20a%203D%20world)

_In this lesson, you will begin to create your own 3D game world and build a grid and coordinate system, so that you can better orientate yourself. Together with a working camera, some objects in the scene and the ability to switch between 2D and 3D, you should be well on your way to producing an exciting graphics tech demo._

<hr>

### [Lesson 14 - Adding some textures to the dish](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2014%20-%20Adding%20some%20textures%20to%20the%20dish)

_With the time now ripe for textures to be added to your objects, in this lesson you will build a Texture class to handle the loading, unloading, storing and filtering of textures. You will learn all about UV coordinates and how you can pass this data, using VBOs, to the shader, as well as demonstrate how to use the textures in the shaders. 
And because one texture simply isn’t enough, you will also learn about multi-texturing._  

### [Lesson 15 - It's too dimensional](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2015%20-%20It's%20too%20dimensional)

_Stepping away from 3D for a short while, you will now delve a little into the world of 2D and learn how to map your UV coordinates to a simple quad to turn it into a sprite. From there, you will create some basic 2D animations and blend them with your 3D world to create a more aesthetically pleasing environment._

### [Lesson 16 - The writing's on the screen](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2016%20-%20The%20writing's%20on%20the%20screen)

_Text rendering is equally important to know about, so today, you will cover how to create text on screen, by using bitmapped fonts before delving into the FreeType library. You will end off the lesson building a Text class to encapsulate all text rendering functionality._

<hr>

### [Lesson 17 - Let there be lights I](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2017%20-%20Let%20there%20be%20lights%20I)

_It's time to add some color and light to your scene and the next four lessons will be dedicated to just that. Starting you off, you will begin with a brief overview of colors and learn about different color models, color mixing and how they are used in real life as well as digitally._

### [Lesson 18 - Let there be lights II](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2018%20-%20Let%20there%20be%20lights%20II)

_In this lesson, you will learn how lighting can be broken down into the ambient, diffuse and specular lighting model. You will further discover the concept of a light source, the object being lit, and the viewer, and build lighting algorithms in your vertex shader. Thereafter, you will continue learning about lights and delve into per-fragment lighting, which will make your objects and scene look a whole lot better._

### [Lesson 19 - Let there be lights III](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2019%20-%20Let%20there%20be%20lights%20III)

_With a plethora of lighting knowledge under your belt and a robust lighting system built into your engine, you will now cover everything there is to know about normals and how a normal matrix can make a difference with rotated objects being lit._

### [Lesson 20 - Let there be more lights](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2020%20-%20Let%20there%20be%20more%20lights)

_Here, you conclude your lessons of lighting by learning how to create multiple lights, as well as different types of lighting such as spot, point and directional lights._

### [Lesson 21 - Setting the scene](https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/tree/main/Lesson%2021%20-%20Setting%20the%20scene)

_In this lesson, you are going to learn all about the OBJ file format, from head to toe, before going on to build your own 3D model loader. Once that's done and dusted, you will use this new tool to load some 3D models and begin setting up your 3D scene._

