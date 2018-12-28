# C++ Reference

This is a repo with some examples of C++. There are a few different Hello World examples, and some kata/sandbox code from me. Also, a Dockerfile for a C++ image. Mostly made this for myself as a quick reference as I knock the rust off my C++.

Directories, listed in approximate order of complexity:

* `basics/dumb-hello` - simplest example, just uses g++.
* `basics/make-hello` - same hello world example, but with a makefile
* `basics/cmake-hello` - same hello world example, but with CMake
* `basics/cmake-docker-hello` - CMake hello world with scripts for running in Docker
* `basics/cppHello` - copy of RJ's basic C++ repo, see README
* `cmake-and-boost` - example of using boost
* `evercraft-kata` - Evercraft Kata, a more in depth example.
* `graphics/ppm-hello` - from Ray Tracing In One Weekend, writes out a PPM file
* `graphics/raytracing` - code from Ray Tracing In One Weekend.

# Dockerfiles

There are two Dockerfiles here:
`Dockerfile` - basic C++ dev environment. I usually use this by mounting the current dir as described below. Can be `docker pull`d from epiccoleman/cpp.
`Dockerfile-Boost` - same, but with Boost installed. This image takes a century to build, can be `docker pull`d from epiccoleman/cpp-boost. Use this approach unless you _really_ have to build an inner layer.

These images are pretty large and the boost one should probably inherit from cpp, but pulling from Docker Hub will still take less time than building Boost. Building cpp may be faster than pulling based on your download speed.

## Using Docker
See build scripts in graphics/raytracing for one approach. Not a perfect approach, but it's there. 

Lately, I've been using this approach more than automating the docker stuff:

Use this command to get a shell in a C++ Docker with $PWD mounted (assuming you built the docker as `cpp:latest`)

`docker run -v "${PWD}:/code" -it cpp:latest bash`

Use this version if you want to debug with gdb.
`docker run -v "${PWD}:/code" --security-opt seccomp=unconfined -it cpp:latest bash`

This has some flaws but it works fine for small things like Advent of Code.
