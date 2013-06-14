/*
 * Description: Sample read only ini parser
 *     History: yang@haipo.me, 2013/06/13, create
 */

# pragma once

# include <stdint.h>
# include <netinet/in.h>

struct ini_arg
{
    char  *name;
    char  *value;
    struct ini_arg *next;
};

struct ini_section
{
    char  *name;
    struct ini_arg *args;
    struct ini_section *next;
};

typedef struct ini_section ini_t;

/*
 * Load a ini config file to memory, return NULL if fail.
 */
ini_t *ini_load(char *path);

/*
 * Return value:
 * If the combination of section and name found in config file, return 0.
 * Return 1 if not found, the *value will be the default_value.
 *
 * Fail return -1;
 */

/*
 * Read string from ini config handle.
 * The string is allocated using malloc, so, you need free it after use.
 */ 
int ini_read_str(ini_t *handle,
        char *section, char *name, char **value, char *default_value);

/*
 * Read string from ini config handle.
 * If the real length of value is greater than or equal to n, n - 1
 * characters and a null terminator will be copied to value.
 */
int ini_read_strn(ini_t *handle,
        char *section, char *name, char *value, size_t n, char *default_value);

/*
 * Read int or unsigned int or stdint from ini config handle.
 * Support octal or hexadecimal base ("0" or "0x"/"0X" respectively).
 */
int ini_read_int(ini_t *handle,
        char *section, char *name, int *value, int default_value);

int ini_read_unsigned(ini_t *handle,
        char *section, char *name, unsigned *value, unsigned default_value);

int ini_read_int8(ini_t *handle,
        char *section, char *name, int8_t *value, int8_t default_value);

int ini_read_uint8(ini_t *handle,
        char *section, char *name, uint8_t *value, uint8_t default_value);

int ini_read_int16(ini_t *handle,
        char *section, char *name, int16_t *value, int16_t default_value);

int ini_read_uint16(ini_t *handle,
        char *section, char *name, uint16_t *value, uint16_t default_value);

int ini_read_int32(ini_t *handle,
        char *section, char *name, int32_t *value, int32_t default_value);

int ini_read_uint32(ini_t *handle,
        char *section, char *name, uint32_t *value, uint32_t default_value);

int ini_read_int64(ini_t *handle,
        char *section, char *name, int64_t *value, int64_t default_value);

int ini_read_uint64(ini_t *handle,
        char *section, char *name, uint64_t *value, uint64_t default_value);

/*
 * Read float/double from ini config handle.
 */
int ini_read_float(ini_t *handle,
        char *section, char *name, float *value, float default_value);

int ini_read_double(ini_t *handle,
        char *section, char *name, double *value, double default_value);

/*
 * Read a ipv4 addr such as: 127.0.0.1:8080
 */
int ini_read_ipv4_addr(ini_t *handle,
        char *section, char *name, struct sockaddr_in *addr, char *default_value);

/* free a ini config handle */
void ini_free(ini_t *handle);
