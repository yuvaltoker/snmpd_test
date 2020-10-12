FROM polinux/snmpd
RUN mkdir new_snmpd_test
RUN mkdir new_snmpd_test/hiredis
COPY ./instructions.sh /new_snmpd_test/
COPY ./MY-TUTORIAL-MIB.txt /usr/share/snmp/mibs
COPY ./NET-SNMP-TUTORIAL-MIB.txt /usr/share/snmp/mibs
COPY ./mysubagent /new_snmpd_test/
COPY ./batteryAgentSubagentObject.c /new_snmpd_test/
COPY ./batteryAgentSubagentObject.h /new_snmpd_test/
COPY ./nstAgentSubagentObject.c /new_snmpd_test/
COPY ./nstAgentSubagentObject.h /new_snmpd_test/
COPY ./example-daemon.c /new_snmpd_test/
ADD ./hiredis /new_snmpd_test/hiredis/
COPY ./Makefile /new_snmpd_test/
RUN chmod +x /new_snmpd_test/instructions.sh
RUN yum install -y make
RUN yum install -y nano
RUN yum install -y net-snmp-utils
RUN yum install -y gcc
RUN yum install -y net-snmp-devel
RUN yum install -y libevent-devel
RUN yum install -y http://repo.okay.com.mx/centos/7/x86_64/release/okay-release-1-1.noarch.rpm
RUN yum install -y hiredis
RUN yum install -y hiredis-devel
ENTRYPOINT ["bash","/new_snmpd_test/instructions.sh"]

