#!/bin/bash

docker run -it -v "${PWD}:/code" cpp:latest "ci/build.sh"
