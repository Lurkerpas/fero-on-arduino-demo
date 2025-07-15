// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error spacesegment_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned spacesegment_initialized;

void spacesegment_RI_tm_To_PID(asn1SccPID dest_pid, 
      const asn1SccTestInteger *IN_reply
);
void spacesegment_RI_tm(
      const asn1SccTestInteger *IN_reply
);
void spacesegment_RI_tm(
      const asn1SccTestInteger *IN_reply
)
{
   // When no destination is specified, send to everyone (multicast)
   spacesegment_RI_tm_To_PID(PID_env, IN_reply
);
}

void spacesegment_RI_tm_To_PID(asn1SccPID dest_pid, 
      const asn1SccTestInteger *IN_reply
)
{
   int reply_error_code = 0;
   // Encode parameter reply using ASN.1 ACN
   
   static char IN_buf_reply[asn1SccTestInteger_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_reply =
      Encode_ACN_TestInteger
        ((void *)&IN_buf_reply,
          asn1SccTestInteger_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccTestInteger *)IN_reply,
          &reply_error_code);
   if (-1 == size_IN_buf_reply) {
      spacesegment_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      spacesegment_recent_error.u.encodeerror = reply_error_code;
      return;
   }


   // Send the message via the middleware API
   extern void vm_spacesegment_tm
     (asn1SccPID,
      void *, size_t);

   vm_spacesegment_tm
     (dest_pid,
      (void *)&IN_buf_reply, (size_t)size_IN_buf_reply);


  spacesegment_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void spacesegment_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void spacesegment_get_sender(asn1SccPID *sender_pid);
  spacesegment_get_sender(sender_pid);
}

void spacesegment_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = spacesegment_recent_error;
}

void spacesegment_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    spacesegment_RI_get_last_error(err);
}

