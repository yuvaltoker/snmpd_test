FROM polinux/snmpd
COPY ./instructions.sh /
RUN chmod +x /instructions.sh
RUN yum install -y nano
ENTRYPOINT ["bash","/instructions.sh"]
