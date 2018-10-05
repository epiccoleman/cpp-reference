#!/bin/bash

ci/docker-build.sh

docker run -it -v "${PWD}:/code" cpp:latest "ci/build.sh"
