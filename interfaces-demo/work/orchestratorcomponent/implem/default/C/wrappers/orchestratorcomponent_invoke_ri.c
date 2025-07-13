// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error orchestratorcomponent_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned orchestratorcomponent_initialized;

void orchestratorcomponent_RI_tc_To_PID(asn1SccPID dest_pid, 
      const asn1SccTestInteger *IN_request
);
void orchestratorcomponent_RI_tc(
      const asn1SccTestInteger *IN_request
);
void orchestratorcomponent_RI_tc(
      const asn1SccTestInteger *IN_request
)
{
   // When no destination is specified, send to everyone (multicast)
   orchestratorcomponent_RI_tc_To_PID(PID_env, IN_request
);
}

void orchestratorcomponent_RI_tc_To_PID(asn1SccPID dest_pid, 
      const asn1SccTestInteger *IN_request
)
{
   int request_error_code = 0;
   // Encode parameter request using ASN.1 ACN
   
   static char IN_buf_request[asn1SccTestInteger_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_request =
      Encode_ACN_TestInteger
        ((void *)&IN_buf_request,
          asn1SccTestInteger_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccTestInteger *)IN_request,
          &request_error_code);
   if (-1 == size_IN_buf_request) {
      orchestratorcomponent_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      orchestratorcomponent_recent_error.u.encodeerror = request_error_code;
      return;
   }


   // Send the message via the middleware API
   extern void vm_orchestratorcomponent_tc
     (asn1SccPID,
      void *, size_t);

   vm_orchestratorcomponent_tc
     (dest_pid,
      (void *)&IN_buf_request, (size_t)size_IN_buf_request);


  orchestratorcomponent_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void orchestratorcomponent_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void orchestratorcomponent_get_sender(asn1SccPID *sender_pid);
  orchestratorcomponent_get_sender(sender_pid);
}

void orchestratorcomponent_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = orchestratorcomponent_recent_error;
}

void orchestratorcomponent_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    orchestratorcomponent_RI_get_last_error(err);
}

