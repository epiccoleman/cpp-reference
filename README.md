# C++ Reference

This is a repo with some examples of C++. There are a few different Hello World examples, and some kata/sandbox code from me. Also, a Dockerfile for a C++ image. Mostly made this for myself as a quick reference as I knock the rust off my C++.

Directories, listed in approximate order of complexity:

* `basics/dumb-hello` - simplest example, just uses g++.
* `basics/make-hello` - same hello world example, but with a makefile
* `basics/cmake-hello` - same hello world example, but with CMake
* `basics/cmake-docker-hello` - CMake hello world with scripts for running in Docker
* `basics/cppHello` - copy of RJ's basic C++ repo, see README

* `evercraft-kata` - Evercraft Kata, a more in depth example. 
* `graphics/ppm-hello` - from Ray Tracing In One Weekend, writes out a PPM file
* `graphics/raytracing` - code from Ray Tracing In One Weekend.

## Using Docker
See build scripts in graphics/raytracing for one approach. Not a perfect approach, but it's there.

Use this command to get a shell in a C++ Docker with $PWD mounted (assuming you built the docker as `cpp:latest`)

`docker run -v "${PWD}:/code" -it cpp:latest bash` 

Use this version if you want to debug with gdb.
`docker run -v "${PWD}:/code" --security-opt seccomp=unconfined -it cpp:latest bash` 
