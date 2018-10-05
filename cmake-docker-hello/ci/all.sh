#!/bin/bash

ci/docker-build.sh

docker run -it -v "${PWD}:/kata" cpp:latest "ci/build.sh"
