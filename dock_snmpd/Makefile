#
# Warning: you may need more libraries than are included here on the
# build line.  The agent frequently needs various libraries in order
# to compile pieces of it, but is OS dependent and we can't list all
# the combinations here.  Instead, look at the libraries that were
# used when linking the snmpd master agent and copy those to this
# file.
#

CC=gcc -std=c99 -lhiredis -levent -lnetsnmp

NETSNMPCONFIG=net-snmp-config

NETSNMPCFLAGS := (shell $(NETSNMPCONFIG) --base-cflags)

OBJS1=snmpdemoapp.o
OBJS2=example-daemon.o nstAgentSubagentObject.o batteryAgentSubagentObject.o hiredis/hiredis.o hiredis/sds.o hiredis/net.o hiredis/read.o
OBJS3=asyncapp.o
TARGETS=example-daemon snmpdemoapp asyncapp

CFLAGS=-I. `net-snmp-config --cflags`
ANOTHERFLAG=-std=c99
BUILDLIBS=`net-snmp-config --libs `
BUILDAGENTLIBS=`net-snmp-config --agent-libs`
LIBINCLUDES=-L/root/cli-ser-proj/hiredis

# shared library flags (assumes gcc)
DLFLAGS=-fPIC -shared

all: $(TARGETS)

snmpdemoapp: $(OBJS1)
	$(CC) -o snmpdemoapp $(OBJS1) $(BUILDLIBS)

asyncapp: $(OBJS3)
	$(CC) -o asyncapp $(OBJS3) $(BUILDLIBS)

example-daemon: $(OBJS2)
	$(CC) -o example-daemon $(OBJS2) $(LIBINCLUDES) $(BUILDAGENTLIBS)

clean:
	rm $(OBJS2) $(OBJS2) $(TARGETS)

nstAgentPluginObject.so: nstAgentPluginObject.c Makefile
	$(CC) $(CFLAGS) $(DLFLAGS) -c -o nstAgentPluginObject.o nstAgentPluginObject.c
	$(CC) $(CFLAGS) $(DLFLAGS) -o nstAgentPluginObject.so nstAgentPluginObject.o

