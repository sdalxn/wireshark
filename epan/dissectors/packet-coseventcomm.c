/* packet-coseventcomm.c
 *
 * $Id$
 *
 * Routines for IDL dissection
 *
 * Autogenerated from idl2wrs
 * Copyright 2001 Frank Singleton <frank.singleton@ericsson.com>
 */


/*
 * Wireshark - Network traffic analyzer
 * By Gerald Combs
 * Copyright 1999 - 2012 Gerald Combs
 */

/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */


#include "config.h"

#include <gmodule.h>

#include <string.h>
#include <glib.h>
#include <epan/packet.h>
#include <epan/proto.h>
#include <epan/dissectors/packet-giop.h>
#include <epan/expert.h>

#ifdef _MSC_VER
/* disable warning: "unreference local variable" */
#pragma warning(disable:4101)
#endif


/* Initialise the protocol and subtree pointers */
static int proto_coseventcomm = -1;
static gint ett_coseventcomm = -1;


/* Initialise the initial Alignment */
static guint32  boundary = GIOP_HEADER_SIZE;  /* initial value */

static int hf_operationrequest = -1;/* Request_Operation field */

        /* Operation filters */
static int hf_CosEventComm_PushConsumer_push_data = -1;
static int hf_CosEventComm_PullSupplier_pull_return = -1;
static int hf_CosEventComm_PullSupplier_try_pull_return = -1;
static int hf_CosEventComm_PullSupplier_try_pull_has_event = -1;
        /* User exception filters */
        /* Expert info filters */
static expert_field ei_coseventcomm_unknown_giop_msg = EI_INIT;
static expert_field ei_coseventcomm_unknown_exception = EI_INIT;
static expert_field ei_coseventcomm_unknown_reply_status = EI_INIT;


static proto_tree *start_dissecting(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset);


/*  Begin Exception Helper Functions  */



/*  End Exception Helper Functions  */

/*
 * Main delegator for exception handling
 *
 */
static gboolean
decode_user_exception(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *ptree _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
    proto_tree *tree _U_;

    if (!header->exception_id)
        return FALSE;


    return FALSE;    /* user exception not found */
}

/*
 * IDL:omg.org/CosEventComm/PushConsumer/push:1.0
 */
static void
decode_CosEventComm_PushConsumer_push(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
    switch(header->message_type) {
    case Request:
        get_CDR_any(tvb, pinfo, tree, item, offset, stream_is_big_endian, boundary, header);

        break;
    case Reply:
        switch(header->rep_status) {
        case NO_EXCEPTION:
            /* Function returns void */

            break;
        case USER_EXCEPTION:
            break;
        default:
            /* Unknown Exception */
            expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
            break;
        }   /* switch(header->rep_status) */

        break;
    default:
        /* Unknown GIOP Message */
        expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
        break;
    } /* switch(header->message_type) */
}

/*
 * IDL:omg.org/CosEventComm/PushConsumer/disconnect_push_consumer:1.0
 */
static void
decode_CosEventComm_PushConsumer_disconnect_push_consumer(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
    switch(header->message_type) {
    case Request:
        break;
    case Reply:
        switch(header->rep_status) {
        case NO_EXCEPTION:
            /* Function returns void */

            break;
        case USER_EXCEPTION:
            break;
        default:
            /* Unknown Exception */
            expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
            break;
        }   /* switch(header->rep_status) */

        break;
    default:
        /* Unknown GIOP Message */
        expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
        break;
    } /* switch(header->message_type) */
}

/*
 * IDL:omg.org/CosEventComm/PushSupplier/disconnect_push_supplier:1.0
 */
static void
decode_CosEventComm_PushSupplier_disconnect_push_supplier(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
    switch(header->message_type) {
    case Request:
        break;
    case Reply:
        switch(header->rep_status) {
        case NO_EXCEPTION:
            /* Function returns void */

            break;
        case USER_EXCEPTION:
            break;
        default:
            /* Unknown Exception */
            expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
            break;
        }   /* switch(header->rep_status) */

        break;
    default:
        /* Unknown GIOP Message */
        expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
        break;
    } /* switch(header->message_type) */
}

/*
 * IDL:omg.org/CosEventComm/PullSupplier/pull:1.0
 */
static void
decode_CosEventComm_PullSupplier_pull(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
    switch(header->message_type) {
    case Request:
        break;
    case Reply:
        switch(header->rep_status) {
        case NO_EXCEPTION:
            get_CDR_any(tvb, pinfo, tree, item, offset, stream_is_big_endian, boundary, header);

            break;
        case USER_EXCEPTION:
            break;
        default:
            /* Unknown Exception */
            expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
            break;
        }   /* switch(header->rep_status) */

        break;
    default:
        /* Unknown GIOP Message */
        expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
        break;
    } /* switch(header->message_type) */
}

/*
 * IDL:omg.org/CosEventComm/PullSupplier/try_pull:1.0
 */
static void
decode_CosEventComm_PullSupplier_try_pull(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
    switch(header->message_type) {
    case Request:
        break;
    case Reply:
        switch(header->rep_status) {
        case NO_EXCEPTION:
            get_CDR_any(tvb, pinfo, tree, item, offset, stream_is_big_endian, boundary, header);

            proto_tree_add_boolean(tree, hf_CosEventComm_PullSupplier_try_pull_has_event, tvb, *offset-1, 1, get_CDR_boolean(tvb,offset));

            break;
        case USER_EXCEPTION:
            break;
        default:
            /* Unknown Exception */
            expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
            break;
        }   /* switch(header->rep_status) */

        break;
    default:
        /* Unknown GIOP Message */
        expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
        break;
    } /* switch(header->message_type) */
}

/*
 * IDL:omg.org/CosEventComm/PullSupplier/disconnect_pull_supplier:1.0
 */
static void
decode_CosEventComm_PullSupplier_disconnect_pull_supplier(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
    switch(header->message_type) {
    case Request:
        break;
    case Reply:
        switch(header->rep_status) {
        case NO_EXCEPTION:
            /* Function returns void */

            break;
        case USER_EXCEPTION:
            break;
        default:
            /* Unknown Exception */
            expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
            break;
        }   /* switch(header->rep_status) */

        break;
    default:
        /* Unknown GIOP Message */
        expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
        break;
    } /* switch(header->message_type) */
}

/*
 * IDL:omg.org/CosEventComm/PullConsumer/disconnect_pull_consumer:1.0
 */
static void
decode_CosEventComm_PullConsumer_disconnect_pull_consumer(tvbuff_t *tvb _U_, packet_info *pinfo _U_, proto_tree *tree _U_, proto_item *item _U_, int *offset _U_, MessageHeader *header, const gchar *operation _U_, gboolean stream_is_big_endian _U_)
{
    switch(header->message_type) {
    case Request:
        break;
    case Reply:
        switch(header->rep_status) {
        case NO_EXCEPTION:
            /* Function returns void */

            break;
        case USER_EXCEPTION:
            break;
        default:
            /* Unknown Exception */
            expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_exception, "Unknown exception %d", header->rep_status);
            break;
        }   /* switch(header->rep_status) */

        break;
    default:
        /* Unknown GIOP Message */
        expert_add_info_format(pinfo, item, &ei_coseventcomm_unknown_giop_msg, "Unknown GIOP message %d", header->message_type);
        break;
    } /* switch(header->message_type) */
}

/*
 * Called once we accept the packet as being for us; it sets the
 * Protocol and Info columns and creates the top-level protocol
 * tree item.
 */
static proto_tree *
start_dissecting(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset)
{

    proto_item *ti = NULL;
    proto_tree *tree = NULL;            /* init later, inside if(tree) */

    col_set_str(pinfo->cinfo, COL_PROTOCOL, "COSEVENTCOMM");

    /*
     * Do not clear COL_INFO, as nothing is being written there by
     * this dissector yet. So leave it as is from the GIOP dissector.
     * TODO: add something useful to COL_INFO
     *     col_clear(pinfo->cinfo, COL_INFO);
     */

    if (ptree) {
        ti = proto_tree_add_item(ptree, proto_coseventcomm, tvb, *offset, -1, ENC_NA);
        tree = proto_item_add_subtree(ti, ett_coseventcomm);
    }
    return tree;
}

static proto_item*
process_RequestOperation(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, MessageHeader *header, const gchar *operation)
{
    proto_item *pi;
    if(header->message_type == Reply) {
        /* fill-up info column */
        col_append_fstr(pinfo->cinfo, COL_INFO, " op = %s",operation);
    }
    /* fill-up the field */
    pi=proto_tree_add_string(ptree, hf_operationrequest, tvb, 0, 0, operation);
    PROTO_ITEM_SET_GENERATED(pi);
    return pi;
}

static gboolean
dissect_coseventcomm(tvbuff_t *tvb, packet_info *pinfo, proto_tree *ptree, int *offset, MessageHeader *header, const gchar *operation, gchar *idlname)
{
    proto_item *item _U_;
    proto_tree *tree _U_;
    gboolean stream_is_big_endian = is_big_endian(header); /* get endianess */

    /* If we have a USER Exception, then decode it and return */
    if ((header->message_type == Reply) && (header->rep_status == USER_EXCEPTION)) {
       return decode_user_exception(tvb, pinfo, ptree, offset, header, operation, stream_is_big_endian);
    }

    switch(header->message_type) {

    case Request:
    case Reply:

        if (strcmp(operation, "push") == 0
            && (!idlname || strcmp(idlname, "CosEventComm/PushConsumer") == 0)) {
           item = process_RequestOperation(tvb, pinfo, ptree, header, operation);  /* fill-up Request_Operation field & info column */
           tree = start_dissecting(tvb, pinfo, ptree, offset);
           decode_CosEventComm_PushConsumer_push(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
           return TRUE;
        }

        if (strcmp(operation, "disconnect_push_consumer") == 0
            && (!idlname || strcmp(idlname, "CosEventComm/PushConsumer") == 0)) {
           item = process_RequestOperation(tvb, pinfo, ptree, header, operation);  /* fill-up Request_Operation field & info column */
           tree = start_dissecting(tvb, pinfo, ptree, offset);
           decode_CosEventComm_PushConsumer_disconnect_push_consumer(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
           return TRUE;
        }

        if (strcmp(operation, "disconnect_push_supplier") == 0
            && (!idlname || strcmp(idlname, "CosEventComm/PushSupplier") == 0)) {
           item = process_RequestOperation(tvb, pinfo, ptree, header, operation);  /* fill-up Request_Operation field & info column */
           tree = start_dissecting(tvb, pinfo, ptree, offset);
           decode_CosEventComm_PushSupplier_disconnect_push_supplier(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
           return TRUE;
        }

        if (strcmp(operation, "pull") == 0
            && (!idlname || strcmp(idlname, "CosEventComm/PullSupplier") == 0)) {
           item = process_RequestOperation(tvb, pinfo, ptree, header, operation);  /* fill-up Request_Operation field & info column */
           tree = start_dissecting(tvb, pinfo, ptree, offset);
           decode_CosEventComm_PullSupplier_pull(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
           return TRUE;
        }

        if (strcmp(operation, "try_pull") == 0
            && (!idlname || strcmp(idlname, "CosEventComm/PullSupplier") == 0)) {
           item = process_RequestOperation(tvb, pinfo, ptree, header, operation);  /* fill-up Request_Operation field & info column */
           tree = start_dissecting(tvb, pinfo, ptree, offset);
           decode_CosEventComm_PullSupplier_try_pull(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
           return TRUE;
        }

        if (strcmp(operation, "disconnect_pull_supplier") == 0
            && (!idlname || strcmp(idlname, "CosEventComm/PullSupplier") == 0)) {
           item = process_RequestOperation(tvb, pinfo, ptree, header, operation);  /* fill-up Request_Operation field & info column */
           tree = start_dissecting(tvb, pinfo, ptree, offset);
           decode_CosEventComm_PullSupplier_disconnect_pull_supplier(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
           return TRUE;
        }

        if (strcmp(operation, "disconnect_pull_consumer") == 0
            && (!idlname || strcmp(idlname, "CosEventComm/PullConsumer") == 0)) {
           item = process_RequestOperation(tvb, pinfo, ptree, header, operation);  /* fill-up Request_Operation field & info column */
           tree = start_dissecting(tvb, pinfo, ptree, offset);
           decode_CosEventComm_PullConsumer_disconnect_pull_consumer(tvb, pinfo, tree, item, offset, header, operation, stream_is_big_endian);
           return TRUE;
        }

        break;

    case CancelRequest:
    case LocateRequest:
    case LocateReply:
    case CloseConnection:
    case MessageError:
    case Fragment:
       return FALSE;      /* not handled yet */

    default:
       return FALSE;      /* not handled yet */

    }   /* switch */


    return FALSE;

}  /* End of main dissector  */


/* Register the protocol with Wireshark */
void proto_register_giop_coseventcomm(void)
{
   /* setup list of header fields */
   static hf_register_info hf[] = {
        /* field that indicates the currently ongoing request/reply exchange */
		{&hf_operationrequest, {"Request_Operation","giop-coseventcomm.Request_Operation",FT_STRING,BASE_NONE,NULL,0x0,NULL,HFILL}},
        /* Operation filters */
        {&hf_CosEventComm_PullSupplier_try_pull_has_event, {"has_event","giop-coseventcomm.PullSupplier.try_pull.has_event",FT_BOOLEAN,8,NULL,0x01,NULL,HFILL}},
        /* Attribute filters */
        /* Struct filters */
        /* User exception filters */
        /* Union filters */

   };

   static ei_register_info ei[] = {
      { &ei_coseventcomm_unknown_giop_msg, { "giop-coseventcomm.unknown_giop_msg", PI_PROTOCOL, PI_WARN, "Unknown GIOP message", EXPFILL }},
      { &ei_coseventcomm_unknown_exception, { "giop-coseventcomm.unknown_exception", PI_PROTOCOL, PI_WARN, "Unknown exception", EXPFILL }},
      { &ei_coseventcomm_unknown_reply_status, { "giop-coseventcomm.unknown_reply_status", PI_PROTOCOL, PI_WARN, "Unknown reply status", EXPFILL }},
   };

   /* setup protocol subtree array */

   static gint *ett[] = {
      &ett_coseventcomm,
   };

   expert_module_t* expert_coseventcomm;


   /* Register the protocol name and description */
   proto_coseventcomm = proto_register_protocol("Coseventcomm Dissector Using GIOP API" , "COSEVENTCOMM", "giop-coseventcomm" );
   proto_register_field_array(proto_coseventcomm, hf, array_length(hf));
   proto_register_subtree_array(ett, array_length(ett));

   expert_coseventcomm = expert_register_protocol(proto_coseventcomm);
   expert_register_field_array(expert_coseventcomm, ei, array_length(ei));
}

/* register me as handler for these interfaces */
void proto_reg_handoff_giop_coseventcomm(void)
{
    
    /* Register for Explicit Dissection */
    register_giop_user_module(dissect_coseventcomm, "COSEVENTCOMM", "CosEventComm/PullConsumer", proto_coseventcomm );     /* explicit dissector */
    
    /* Register for Explicit Dissection */
    register_giop_user_module(dissect_coseventcomm, "COSEVENTCOMM", "CosEventComm/PullSupplier", proto_coseventcomm );     /* explicit dissector */
    
    /* Register for Explicit Dissection */
    register_giop_user_module(dissect_coseventcomm, "COSEVENTCOMM", "CosEventComm/PushConsumer", proto_coseventcomm );     /* explicit dissector */
    
    /* Register for Explicit Dissection */
    register_giop_user_module(dissect_coseventcomm, "COSEVENTCOMM", "CosEventComm/PushSupplier", proto_coseventcomm );     /* explicit dissector */
    
    /* Register for Heuristic Dissection */
    register_giop_user(dissect_coseventcomm, "COSEVENTCOMM" ,proto_coseventcomm);     /* heuristic dissector */
}

