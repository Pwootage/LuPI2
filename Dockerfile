FROM scratch

WORKDIR /
COPY bin/lupi /sbin/init
COPY Plan9k /root/
ENTRYPOINT ["/sbin/init"]
