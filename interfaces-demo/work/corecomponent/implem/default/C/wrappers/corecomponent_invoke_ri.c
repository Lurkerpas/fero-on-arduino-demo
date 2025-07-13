// Implementation of the glue code in C handling required interfaces

#include "dataview-uniq.h" // Always required for the definition of the PID type
#include <stdlib.h>
#include "C_ASN1_Types.h"

static asn1SccT_Runtime_Error corecomponent_recent_error = { .kind = T_Runtime_Error_noerror_PRESENT };

extern unsigned corecomponent_initialized;

void corecomponent_RI_computep_To_PID(asn1SccPID dest_pid, 
      const asn1SccTestInteger *IN_a,
       const asn1SccTestInteger *IN_b,
       asn1SccTestInteger       *OUT_c
);
void corecomponent_RI_computep(
      const asn1SccTestInteger *IN_a,
       const asn1SccTestInteger *IN_b,
       asn1SccTestInteger       *OUT_c
);
void corecomponent_RI_computep(
      const asn1SccTestInteger *IN_a,
       const asn1SccTestInteger *IN_b,
       asn1SccTestInteger       *OUT_c
)
{
   // When no destination is specified, send to everyone (multicast)
   corecomponent_RI_computep_To_PID(PID_env, IN_a, IN_b, OUT_c
);
}

void corecomponent_RI_computep_To_PID(asn1SccPID dest_pid, 
      const asn1SccTestInteger *IN_a,
       const asn1SccTestInteger *IN_b,
       asn1SccTestInteger       *OUT_c
)
{

   size_t      size_OUT_buf_c = 0;

   // Send the message via the middleware API
   extern void vm_corecomponent_computep
     (asn1SccPID,
      void *, size_t,
      void *, size_t,
      void *, size_t *);

   vm_corecomponent_computep
     (dest_pid,
      (void *)IN_a, sizeof(asn1SccTestInteger),
      (void *)IN_b, sizeof(asn1SccTestInteger),
      (void *)OUT_c, &size_OUT_buf_c);


  corecomponent_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void corecomponent_RI_computeup_To_PID(asn1SccPID dest_pid, 
      const asn1SccTestInteger *IN_a,
       const asn1SccTestInteger *IN_b,
       asn1SccTestInteger       *OUT_c
);
void corecomponent_RI_computeup(
      const asn1SccTestInteger *IN_a,
       const asn1SccTestInteger *IN_b,
       asn1SccTestInteger       *OUT_c
);
void corecomponent_RI_computeup(
      const asn1SccTestInteger *IN_a,
       const asn1SccTestInteger *IN_b,
       asn1SccTestInteger       *OUT_c
)
{
   // When no destination is specified, send to everyone (multicast)
   corecomponent_RI_computeup_To_PID(PID_env, IN_a, IN_b, OUT_c
);
}

void corecomponent_RI_computeup_To_PID(asn1SccPID dest_pid, 
      const asn1SccTestInteger *IN_a,
       const asn1SccTestInteger *IN_b,
       asn1SccTestInteger       *OUT_c
)
{

   size_t      size_OUT_buf_c = 0;

   // Send the message via the middleware API
   extern void vm_corecomponent_computeup
     (asn1SccPID,
      void *, size_t,
      void *, size_t,
      void *, size_t *);

   vm_corecomponent_computeup
     (dest_pid,
      (void *)IN_a, sizeof(asn1SccTestInteger),
      (void *)IN_b, sizeof(asn1SccTestInteger),
      (void *)OUT_c, &size_OUT_buf_c);


  corecomponent_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}



void corecomponent_RI_tm_To_PID(asn1SccPID dest_pid, 
      const asn1SccTestStruct *IN_response
);
void corecomponent_RI_tm(
      const asn1SccTestStruct *IN_response
);
void corecomponent_RI_tm(
      const asn1SccTestStruct *IN_response
)
{
   // When no destination is specified, send to everyone (multicast)
   corecomponent_RI_tm_To_PID(PID_env, IN_response
);
}

void corecomponent_RI_tm_To_PID(asn1SccPID dest_pid, 
      const asn1SccTestStruct *IN_response
)
{
   int response_error_code = 0;
   // Encode parameter response using ASN.1 ACN
   
   static char IN_buf_response[asn1SccTestStruct_REQUIRED_BYTES_FOR_ACN_ENCODING] = {0};
   int size_IN_buf_response =
      Encode_ACN_TestStruct
        ((void *)&IN_buf_response,
          asn1SccTestStruct_REQUIRED_BYTES_FOR_ACN_ENCODING,
          (asn1SccTestStruct *)IN_response,
          &response_error_code);
   if (-1 == size_IN_buf_response) {
      corecomponent_recent_error.kind = T_Runtime_Error_encodeerror_PRESENT;
      corecomponent_recent_error.u.encodeerror = response_error_code;
      return;
   }


   // Send the message via the middleware API
   extern void vm_corecomponent_tm
     (asn1SccPID,
      void *, size_t);

   vm_corecomponent_tm
     (dest_pid,
      (void *)&IN_buf_response, (size_t)size_IN_buf_response);


  corecomponent_recent_error.kind = T_Runtime_Error_noerror_PRESENT;
}

// Get the PID of the sender function. The actual function is defined in _vm_if.c
// as the sender PID is received together with incoming PI calls
void corecomponent_RI_get_sender(asn1SccPID *sender_pid)
{
  extern void corecomponent_get_sender(asn1SccPID *sender_pid);
  corecomponent_get_sender(sender_pid);
}

void corecomponent_RI_get_last_error(asn1SccT_Runtime_Error* err)
{
    *err = corecomponent_recent_error;
}

void corecomponent_get_last_error(asn1SccT_Runtime_Error* err, const asn1SccPID* dest)
{
    corecomponent_RI_get_last_error(err);
}

