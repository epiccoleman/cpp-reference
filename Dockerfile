FROM ubuntu:18.04

RUN apt-get update -qq && apt-get upgrade -y && apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y tzdata
RUN apt-get install --fix-missing -y \
  build-essential \
  libgtest-dev \
  gdb \
  wget \
  software-properties-common \
  python-dev \
  libxml2-dev \
  libxslt-dev

# install gcc-8
RUN add-apt-repository ppa:ubuntu-toolchain-r/test && \
    apt-get update && \
    apt-get install -y gcc-8 g++-8

# install cmake 3.13
RUN cd /tmp && \
  wget --quiet https://github.com/Kitware/CMake/releases/download/v3.13.1/cmake-3.13.1.tar.gz && \
  tar -xzf cmake-3.13.1.tar.gz && \
  cd cmake-3.13.1 && \
  ./bootstrap && make && make install

# build and install gtest
RUN cd /usr/src/gtest && \
  cmake CMakeLists.txt && \
  make && \
  cp *.a /usr/lib

RUN echo "set nu" > ~/.vimrc && echo "inoremap jk <esc>" >> ~/.vimrc

RUN apt-get install -y vim-gtk
ENV APP_HOME /code

RUN mkdir $APP_HOME

WORKDIR $APP_HOME
