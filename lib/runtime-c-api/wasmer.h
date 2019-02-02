#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef enum {
  WASMER_CALL_OK = 1,
  WASMER_CALL_ERROR = 2,
} wasmer_call_result_t;

typedef enum {
  WASMER_COMPILE_OK = 1,
  WASMER_COMPILE_ERROR = 2,
} wasmer_compile_result_t;

enum wasmer_value_tag {
  WASM_I32,
  WASM_I64,
  WASM_F32,
  WASM_F64,
};
typedef uint32_t wasmer_value_tag;

typedef struct wasmer_import_object_t wasmer_import_object_t;

typedef struct wasmer_instance_t wasmer_instance_t;

typedef union {
  int32_t I32;
  int64_t I64;
  float F32;
  double F64;
} wasmer_value;

typedef struct {
  wasmer_value_tag tag;
  wasmer_value value;
} wasmer_value_t;

void wasmer_import_object_destroy(wasmer_import_object_t *import_object);

wasmer_import_object_t *wasmer_import_object_new(void);

wasmer_call_result_t wasmer_instance_call(wasmer_instance_t *instance,
                                          const char *name,
                                          const wasmer_value_t *params,
                                          int params_len,
                                          wasmer_value_t *results,
                                          int results_len);

void wasmer_instance_destroy(wasmer_instance_t *instance);

wasmer_compile_result_t wasmer_instantiate(wasmer_instance_t **instance,
                                           uint8_t *wasm_bytes,
                                           uint32_t wasm_bytes_len,
                                           wasmer_import_object_t *import_object);
