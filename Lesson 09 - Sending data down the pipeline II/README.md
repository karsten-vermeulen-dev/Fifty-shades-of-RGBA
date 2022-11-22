## Lesson 9 - Sending data down the pipeline II

## The buffer objects

In the last lesson, we put all of our vertex and color data into one single VBO, but ideally, we will want to create separate _Vertex Buffer Objects_ for our data, one for all of our vertices, and one for our colors. We might even create different VBOs for texture coordinate and normal data later on as well. Furthermore, we will want to create and use _Element Buffer Objects_ to enable us to share vertex and color data. The above can then be grouped into _Vertex Array Objects_ that are used in modern _OpenGL_ rendering.

_More material coming soon..._
