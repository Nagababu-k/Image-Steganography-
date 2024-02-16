#ifndef ENCODE_H
#define ENCODE_H

#include "types.h"

// Structure to hold information for encoding
typedef struct {
    char *src_image_fname;
    char *secret_fname;
    char *stego_image_fname;
    FILE *fptr_src_image;
    FILE *fptr_secret;
    FILE *fptr_stego_image;
    char image_data[8];
    char extn_secret_file[32];
    uint size_secret_file;
    uint image_capacity;
} EncodeInfo;


// Function declarations
Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo);
Status do_encoding(EncodeInfo *encInfo);
Status open_files(EncodeInfo *encInfo);
Status check_capacity(EncodeInfo *encInfo);
uint get_image_size_for_bmp(FILE *fptr_image);
uint get_file_size(FILE *fptr);
Status copy_bmp_header(FILE *fptr_src_image, FILE *fptr_dest_image);
Status encode_magic_string(char *magic_string, EncodeInfo *encInfo);
Status encode_data_to_image(char *data, int size, EncodeInfo *encInfo);
Status encode_byte_to_lsb(char data, char *image_buffer);
Status encode_secret_file_extn_size(int size, EncodeInfo *encInfo);
Status encode_size_to_lsb(int size, EncodeInfo *encInfo);
Status encode_secret_file_extn(char *file_extn, EncodeInfo *encInfo);
Status encode_secret_file_size(long file_size, EncodeInfo *encInfo);
Status encode_secret_file_data(EncodeInfo *encInfo);
Status copy_remaining_img_data(EncodeInfo *encInfo);
Status close_files(EncodeInfo *encInfo);

#endif  // ENCODE_H

