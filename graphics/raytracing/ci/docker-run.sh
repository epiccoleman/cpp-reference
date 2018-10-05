#!/bin/bash

docker run -t -v "${PWD}":/code cpp:latest "ci/build.sh"
