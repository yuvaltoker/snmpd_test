FROM polinux/snmpd
COPY ./instructions.sh /
COPY ./MY-TUTORIAL-MIB.txt /usr/share/snmp/mibs/
COPY ./NET-SNMP-TUTORIAL-MIB.txt /usr/share/snmp/mibs/
RUN chmod +x /instructions.sh
RUN yum install -y nano
ENTRYPOINT ["bash","/instructions.sh"]
