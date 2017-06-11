# MazeGenC++

A rewrite of [MazeGen][], this time using Allegro and C++. As before, this was
inspired by [Daniel Shiffman's Codging Challenges][code_challenge] on the same
topic.

[MazeGen]: https://github.com/DonRyuDragoni/MazeGen

[code_challenge]: https://www.youtube.com/watch?v=HyK_Q5rrcr4

## Build

First, you need to install [Allegro5][] on your system. Just follow the
instructions on the website.

[Allegro5]: http://liballeg.org/

I'm also using the [CMake][] build system to make my life easier, so you'll also
need that to follow these steps (though you can use other systems if you wish).

[CMake]: https://cmake.org/

Long story short, in a Linux system, this is all you need to do:

```shell
# pacman -S allegro # or whatever you need do to install allegro on your
                    # system
$ mkdir build && cd build
$ cmake .. && make
```
