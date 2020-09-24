FROM polinux/snmpd
COPY ./instructions.sh /
COPY ./MY-TUTORIAL-MIB.txt /usr/share/snmp/mibs
COPY ./NET-SNMP-TUTORIAL-MIB.txt /usr/share/snmp/mibs
COPY ./mysubagent /
COPY ./batteryAgentSubagentObject.c /
COPY ./batteryAgentSubagentObject.h /
COPY ./example-daemon.c /
COPY -r ./hiredis /
COPY ./Makefile /
RUN chmod +x /instructions.sh
RUN yum install -y nano
ENTRYPOINT ["bash","/instructions.sh"]

