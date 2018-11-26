#!/bin/bash -e

cmake .
make
./RaytracerTest
time ./Raytracer > output.ppm

