## Lesson 2 - The evolution of graphics

### Overview 

Graphics in games have come a long way, from simple graphical overlays to the advanced shader techniques used today. Hardware in the desktop PC and the console has evolved over the last 40 years and even tablets and smartphones have improved dramatically over the last decade and now run some pretty advanced games. The graphics card industry has fought many wars over the years and today _Nvidia_ and _AMD_ (and maybe _Intel_?) battle it out head-to-head to be the best. With the  addition of VR and AR in games, the graphics industry is certainly spanning out in new directions. 

<p align="left"> <img width="220" height="220" src="https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/blob/main/Images/overlays.jpg"> 
  <img width="220" height="220" src="https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/blob/main/Images/forza-horizon-4.jpg"> 
  <img width="220" height="220" src="https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/blob/main/Images/modern_7.jpg"> 
  <img width="220" height="220" src="https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/blob/main/Images/tomb_raider.jpg"> 
  <img width="220" height="220" src="https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/blob/main/Images/modern_4.jpg"> 
  <img width="220" height="220" src="https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/blob/main/Images/aitd.png"> 
  <img width="220" height="220" src="https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/blob/main/Images/modern_3.jpg"> 
  <img width="220" height="220" src="https://github.com/karsten-vermeulen-dev/Fifty-shades-of-RGBA/blob/main/Images/doom.jpg"> </p>

Before we begin, let’s take a look at some early video display standards. 

### Video display standards

These entail _aspect ratio_, _resolution_, _color depth_, _color palette_ and _refresh rate_, amongst other things and used to be a closed standard set by _IBM_, who set the standards for all IBM PCs and PC clones. The company also defined the main graphics standards and released graphics cards to go with their computers. The _Video Electronics Standards Association_, or _VESA_ for short later formed an open standard. _VESA_ is a non-profit organization consisting of over 200 companies that help set the standards to this day. Modern display standards now also include _power management_ and _device identification_. In the past, there have been many different video display standards and the following material will only highlight a few of them.

### MDA (not the drug)

Stands for _Monochrome Display Adapter_ and was introduced by _IBM_ and released in 1981. It was capable of displaying only pure text and no graphics because individual pixels could not be addressed. It was able to render 80x25 characters on screen, with each character being 9x14 pixels in dimension, giving it a resolution of 720x350. 
This standard supported a whopping total of 4KB of memory and games were generally made using ASCII art.

### Hercules (not the Greek hero)

This standard was created by _Hercules Computer Technology_ and released in 1982. It improved upon the _MDA_ standard by displaying text and graphics, as individual pixels could now be addressed. Boasting a resolution of 720x348, just like MDA, it did not display any color.

### CGA (it gets better!)

Also introduced by _IBM_ and released in 1981, this _Color Graphics Adapter_ could represent 16 colors using 4-bit color depth, with RGB components taking up 1 bit each and the 4th bit was for the color intensity. CGA was able to render monochrome graphics in a 640x200 resolution, 4-color graphics in a 320x200 resolution and 16-color graphics in a 160x100 resolution. The 4-color mode versions had different palettes to choose from and the cards supported a total of 16KB of memory. For 1-color modes, any color from the 16-color palette could be used.

### EGA (not the Spanish river)

With _IBM_ on a roll, they realeased this _Enhanced Graphics Adapter_ in 1984. EGA cards could represent 64 colors using a 6-bit color depth, with RGB taking up 2 bits each. EGA was able to render 16-color graphics in a 640x350 resolution, each color being chosen from the 64-color palette, and it had a compatible _CGA_ mode, whereby it was also able to render all 16 colors within the 640x200 or 320x200 resolutions. The cards supported a total of 256KB of memory.

### VGA (not the cable)

In 1987, _IBM_ gave us the _Video Graphics Array_, which could represent 262,144 colors using a 18-bit color depth, with RGB taking up 6 bits each. Amongst other _VGA_ modes, the most common ones were 16-color graphics in a 640x480 resolution, and 256-color graphics in a 320x200 resolution. The _VGA_ standard brought about the iconic 15-pin blue cable adapter and the 640x480 resolution, and today, this resolution is still the lowest common denominator for some systems and games. _VGA_ also began the era of creating graphics chips to process graphics instead of having a dedicated graphics board. Marking the end of an era, this was one of the last graphics standards that _IBM_ introduced before _VESA_ began to set the standards.

### Hey look there, it's _Super VGA_!

The _Super Video Graphics Array_ standard was introduced by _VESA_ and released in 1989 as an extension to _IBM_'s _VGA_ display standard. Originally defined to render 16 colors in a 800x600 resolution, it soon evolved to start rendering 256 (and more) colors in much higher resolutions. This standard marked the start of modern-day graphics standards that we see today.

### Modern-day graphics

Today, there are so many different resolutions, color palettes, aspect ratios and refresh rates and modern graphics cards and their powerful GPUs are capable of rendering high definition games and applications without a hitch. Current film and gaming resolution trends are _HD_ (1280x720), _Full HD_ (1920x1080) and _4K_ (3840×2160). In the world of graphics cards and chipsets, _Nvidia_, _AMD_ and now also _Intel_ are boasting power-hungry hardware, each year competing to be the best and provide gamers and crypo miners with impressive new hardware releases. Funnily enough, the company colors happen to be red (_AMD_), green (_Nvidia_) and blue (_Intel_), which, when abbreviated, becomes _RGB_. You think they did this on purpose? 

### Hold up, I hear early 3D games were faked

That's right, during the 1980s, two-dimensional sprite games were very popular and were played in abundance on PCs and consoles. At the start of the 90s, they began to fade and the era of 3D gaming evolved, however, full 3D games still took a while to evolve. Just like their fellow sprite games, early 3D games were still being processed and rendered in software with code running on the CPU. <br>
The third dimension was all an illusion really, with cheap hacks and neat tricks used to make things appear 3D, for example, _sprite scaling_, _parallax scrolling_ and advanced _texture mapping_ techniques. _Nintendo_'s _SNES_ came with a special _Mode 7_ chip that ran basic algorithms to transform 2D images in such a way that the worlds appeared to look 3D. <br>
_id Software_ also created some revolutionary methods to simulate 3D worlds in their games. _Wolfenstein_ used _ray casting_ and _Doom_ used _binary space partitioning_. <br>
Around the mid-1990s, graphics capabilities were improving dramatically and gamers began to see less software rendering on the CPU and more graphics cards with hardware acceleration. These cards came with a dedicated GPU and were capable of handling more advanced 3D rendering tasks. The _3dfx Voodoo_ card was an early pioneer in the world of full 3D gaming and _Quake III Arena_ was _id Software_'s first true 3D game. The _Nvidia GeForce 256_ was the first card to come with a proper, dedicated graphics processing unit and was marketed as '_The world’s first GPU_'. <br>

💡 _If you're interested, why not check out [this interesting video about how fake the old Doom really was](https://www.youtube.com/watch?v=zb6Eo1D6VW8). And once you've watched that, check out this [article about the modern methods of rendering in the 2016 Doom game](http://www.adriancourreges.com/blog/2016/09/09/doom-2016-graphics-study)_

### Modern-day techniques

The GPU has come to be more powerful than the CPU because of its parallel processing architecture and even though CPUs today have multiple cores and are able to perform multi-threading, they are still considered to be less adequate than GPUs. As 3D technology advances, games and applications today can make use of many different shader and rendering techniques such as:

- _**High Dynamic Range Rendering (HDR)**_
- _**Physically-Based Rendering (PBR)**_
- _**Ray tracing**_ 

### HDR

_More info on this later_

### PBR

_More info on this later_

### Ray tracing

A hot topic in the world of graphics programming and possibly the future of realistic looking games. It has been used in the film industry for decades but only recently has it been implemented in games. The reason for this is that films and animations are _static_, so to speak, which means we merely watch the movie in front of us without much interaction. This allows film and animation studios to apply complex graphics techniques such as ray tracing into their films and process these on what is called _render farms_. The end product is then presented to the consumer to watch. <br>
Games are more _dynamic_ because we interact with them more. That means, the game needs to update accordingly every frame, and with complex ray tracing algorithms, this can prove to be very slow if your GPU is not up to the task. Therefore, until recently, we haven't seen much (or any) ray tracing in games. <br>
The theory behind ray tracing has been around since the 60s and is still being actively researched today. It's extremely computationally expensive and requires dedicated cores to render high resolution games at a decent frame rate. 
So, how does it work? Well, it calculates lighting in a scene using rays that are cast from the viewer to the objects in the world to determine intersections and subsequent pixel color. The current form of real-time rendering has always been _rasterization_ which can look very good but never as photo-realistic as ray tracing. 

💡 _If you're interested, check out this [interesting article on how Control implements ray-tracing](https://www.pcgamer.com/uk/control-is-the-best-most-complex-implementation-of-ray-tracing-in-a-game-so-far)_

<hr>

_More material coming soon..._
