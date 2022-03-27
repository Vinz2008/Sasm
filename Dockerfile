FROM buildpack-deps:buster-curl
RUN apt-get update && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends gcc make libc6-dev nano && \ 
    apt-get clean && rm -rf /var/cache/apt/archives/* && \
    rm -rf /var/lib/apt/lists/*
COPY . /sasm-src
WORKDIR /sasm-src
RUN make && make install && \
    useradd -ms /bin/bash user && \
    rm -rf /sasm-src
USER user
WORKDIR /home/user
CMD [ "bash" ]
