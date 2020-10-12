/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.int_watch.conf,v 5.0 2002/04/20 07:30:13 hardaker Exp $
 */

#include <net-snmp/net-snmp-config.h>
#include <net-snmp/net-snmp-includes.h>
#include <net-snmp/agent/net-snmp-agent-includes.h>
#include "batteryAgentSubagentObject.h"


/*---------------------------------------------------------------------------------------------------*/

/* Make sure those next includes files are at this path, and that you've got the files */
#include "hiredis/hiredis.h"
#include "hiredis/async.h"
#include "hiredis/adapters/libevent.h"

/*---------------------------------------------------------------------------------------------------*/
//redis connection
static redisContext *c;
redisContext **con = &c;

void connectToRedis(void)
{
    const char *hostname = "newNetwork";
    int port = 6739;
    struct timeval timeout = { 1, 50000 }; // 1.5 seconds
    c = redisConnectWithTimeout(hostname, port, timeout);
    // didn't connected to redis
    /*if(c == NULL || c->err)
    {
     	if(c)
	{
            DEBUGMSGTL(("batteryObject", "Connection error: %s\n", c->errstr));
            redisFree(c);
        }
        else
        {
            DEBUGMSGTL(("batteryObject", "Connection error: can't allocate redis context\n"));
        }
    }
    else
    {
     	DEBUGMSGTL(("batteryObject", "Connection Successful\n"));
    }*/
}


void shutdownRedis(void)
{
    redisFree(c);
}

/*
 * the variable we want to tie an OID to.  The agent will handle all
 * * GET and SET requests to this variable changing it's value as needed.
 */

static int batteryObject_value = 4;
//static oid batteryObject_oid[] = { 1, 3, 6, 1, 4, 1, 8072, 2, 4, 1, 1, 1, 0 };

/** Initializes the sub_agent_test module */
void
init_batteryAgentSubagentObject(void)
{
//                                                             as in the MY-TUTORIAL-MIB.txt 
//                                                                         |
    static oid batteryObject_oid[] = { 1, 3, 6, 1, 4, 1, 8072, 2, 4, 1, 1, 4 };

    //DEBUGMSGTL(("batteryAgentSubagentObject", "Initializing\n"));

    netsnmp_register_scalar(
        netsnmp_create_handler_registration("batteryObject", handle_batteryObject,
                                            batteryObject_oid, OID_LENGTH(batteryObject_oid),
                                            HANDLER_CAN_RWRITE
        ));
}

int
handle_batteryObject(netsnmp_mib_handler *handler,
                               netsnmp_handler_registration *reginfo,
                               netsnmp_agent_request_info   *reqinfo,
                               netsnmp_request_info         *requests)
{
    int ret;
    /* we are never called for a GETNEXT if it's registered as a
       "instance", as it's "megically" handled for us. */

    /* a instance handler also only hands us one request at a time, so
       we don't need to loop over a list of requests; we'll only get one. */

    switch(reqinfo->mode)
    {
     	case MODE_GET:
            snmp_set_var_typed_value(requests->requestvb, ASN_INTEGER,
                                     &batteryObject_value,
                                     sizeof(batteryObject_value));
            break;
        case MODE_SET_ACTION:
            /* XXX: perform the value change here */
            if(requests->requestvb->type != ASN_INTEGER)
            {
             	netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGTYPE);
                return SNMP_ERR_WRONGTYPE;
            }

            if(*requests->requestvb->val.integer < 0 || *requests->requestvb->val.integer > 100)
            {
             	netsnmp_set_request_error(reqinfo, requests, SNMP_ERR_WRONGVALUE);
                return SNMP_ERR_WRONGVALUE;
            }
            batteryObject_value = *requests->requestvb->val.integer;
            SET_batteryObject_redis();
            break;

        default:
             /* we should never get here, so this is a really bad error */
             snmp_log(LOG_ERR, "unknown mode (%d) in handle_batteryObject\n", reqinfo->mode);
             return SNMP_ERR_GENERR;
    }
    return SNMP_ERR_NOERROR;
}

void GET_batteryObject_redis()
{
    //GET LOCAL MANAGE INFO

    redisReply *reply;
    reply = (redisReply*)(redisCommand(c, "GET batteryObjectField"));

    //if(reply->type == REDIS_REPLY_ERROR)
    //{
    // 	DEBUGSGTL(("batteryObject", "GET error: %s\n", reply->str));
    //}
    //else
    //{
     	if(reply->str == NULL)
        {
            memset(&batteryObject_value, 0, sizeof(batteryObject_value));
        }
	else
	{
            memmove(batteryObject_value, reply->str, sizeof(batteryObject_value));
        }
    //}
    freeReplyObject(reply);
}

void SET_batteryObject_redis()
{
    redisReply *reply;
    reply = (redisReply*)(redisCommand(*con, "SET batteryObjectField %d", batteryObject_value));
    //if(reply->type == REDIS_REPLY_ERROR)
    //{
    // 	DEBUGSGTL(("batteryObject", "SET error: %s\n", reply->str));
    //}
    freeReplyObject(reply);
}

