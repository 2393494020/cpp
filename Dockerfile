FROM ubuntu
RUN apt-get update && apt-get install -y vim zip unzip
# for c++
RUN apt-get install -y g++ autoconf automake libtool cmake zlib1g-dev pkg-config libssl-dev