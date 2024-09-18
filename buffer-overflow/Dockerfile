FROM --platform=linux/amd64 mcr.microsoft.com/devcontainers/cpp:0-debian-11

# Install package to compile 32-bit binaries
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get -y install --no-install-recommends \
    curl file gcc-multilib g++-multilib python3 python3-pip \
    && rm -rf /var/lib/apt/lists/*

RUN pip install pwn

RUN cd /root

RUN curl -s -o checksec https://raw.githubusercontent.com/slimm609/checksec.sh/2.6.0/checksec

RUN chmod u+x checksec