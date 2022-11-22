## Lesson 5 - Start your graphics engines!

## Big engines & managers

In this lesson, we will want to wrap all our previous code into a more manageable class and use a bit of _OOP_ straight away to tuck away the raw and core _OpenGL_ code. For this, we will look into what manager classes are and how we can use one for our screen setup code. 

## The _Singleton_ design pattern

Singletons are a commonly used, yet controversial design pattern. They ensure that only one instance of a class is instantiated, and that that instance is globally accessible by all components within a framework. Apart from them not being able to be created more than once, they also cannot be copied or assigned to other variables. Singletons are accessible only via a special pointer, and are used to represent manager or controller classes. 

Many documents warn of Singleton abuse, because they are essentially global variables and they create dependencies, so beware of overusing them.

_More material coming soon..._
