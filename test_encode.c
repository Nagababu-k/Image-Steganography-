#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "decode.h"
#include "types.h"

//Main Function
OperationType check_operation_type(char *argv[]);

int main(int argc,char *argv[])		//Collecting Command Line Arguements
{
	int ret,read,encode,decode;
	EncodeInfo encInfo;			//EncodeInfo Structure Variable
	DecodeInfo decInfo;			//DecodeInfo Structure Variable

	//validating whether required encoding and decoding options and arguements are passed or not

	if ( argc <= 1 )
	{
		printf("ERROR: Usage!\n");
		printf("USAGE: Encoding: %s -e <.bmp file> <.txt file> [output file]\n",argv[0]);
		printf("USAGE: Decoding: %s -d <.bmp file> [output file]\n",argv[0]);
		return 0;
	}

	//calling check_operation_type function

	ret = check_operation_type(argv);
	
	//validating whether required arguements for encoding are passed or not

	if ( ret == e_encode )
	{
		if ( argc <= 3 )
		{
			printf("ERROR: Usage!\n");
			printf("USAGE: Encoding: %s -e <.bmp file> <.txt file> [output file]\n",argv[0]);
			return 0;
		}
	}

	//validating whether required arguements for decoding are passed or not
	
	else if ( ret == e_decode )
	{
		if ( argc <= 2 )
		{
			printf("ERROR: Usage!\n");
			printf("USAGE: Decoding: %s -d <.bmp file> [output file]\n",argv[0]);
			return 0;
		}

	}

	//calling check_operation_type to check for which operation type is selected

	ret = check_operation_type(argv);

	//checking whether encode is passed or not
	
	if ( ret == e_encode )
	{
		//calling read_and_validate_encode_args function to validate the arguements are passed or not
		
		read = read_and_validate_encode_args(argv,&encInfo);

		//validating whether encoding arguements validation is success or not

		if ( read == e_success )
		{
			//calling do_encoding function to do encoding

			encode = do_encoding(&encInfo);	

			//Validating whether encoding process is success or not

			if ( encode == e_success )
			printf("INFO: ## Encoding Done Successfully ##\n");

			//printing an error and terminating the program if the encoding process is failed

			else
			{
				printf("ERROR: Encoding Process is Failure!\n");
				return 0;
			}
		}	

		//printing an error and terminating the program if the encoding arguements validation is failed

		else
		{
			printf("ERROR: Validation of Encoding Arguements is Failure!\n");
			return 0;
		}
	}

	//validating whether decode option is passed or not

	else if ( ret == e_decode )
	{
		//calling read_and_validate_decode_args function to validate the arguements are passed or not

		read = read_and_validate_decode_args(argv,&decInfo);

		//validating whether validation of decoding arguements is success or not

		if ( read == e_success )
		{

			//calling do_decoding function to do decoding
			
			decode = do_decoding(&decInfo);

			//validating whether decoding process is success or not

			if ( decode == e_success )
			printf("INFO: ## Decoding Done Successfully ##\n");

			//printing an error and terminating the program if the decoding process is failed

			else
			{
				printf("ERROR: Decoding Process is Failure!\n");
				return 0;
			}
		}

		//printing an error and terminating the program if the decoding arguements validation is failed

		else
		{
			printf("ERROR: Validation of Decoding Arguements is Failure!\n");
			return 0;
		}
	}

	//printing an error and terminating the program if an unsupported option is given

	else if ( ret == e_unsupported )
	{
		printf("ERROR: Unsupported Option!\n");
		printf("USAGE: Encoding: %s -e <.bmp file> <.txt file> [output file]\n",argv[0]);
		printf("USAGE: Decoding: %s -d <.bmp file> [output file]\n",argv[0]);
		return 0;
	}

    return 0;
}

//check_operation_type Function Definition

OperationType check_operation_type(char *argv[])
{
	//validating whether option given is -e or not

	if ( strcmp(argv[1],"-e") == 0 )
	return e_encode;

	//validating whether option given is -d or not

	else if ( strcmp(argv[1],"-d") == 0 )
	return e_decode;

	//validating whether if an unsupported option is given

	else
	return e_unsupported;
}


