#ifndef FEE_PACKET_STRUCTURE_H
#define FEE_PACKET_STRUCTURE_H

#define FEE_PACKET_HEADER_OFFSET 	0 
#define FEE_PACKET_SIZE 			    100 
#define FEE_PACKET_HEADER_SIZE 		1 
#define SCIENCE_DATA_LENGTH		    10 
#define HOUSE_KEEPING_DATA		    5
#define	CONFIG_PARAM_ID 			    1
#define	CONFIG_PARAM_VAL			    1
#define CHECKSUM_SIZE				      100
#define CHECKSUM_VAL				      1	
#pragma pack(1)       /*eliminates byte padding */
union fee_paket
{
	struct
	{
		byte header; 
		byte science_data[SCIENCE_DATA_LENGTH]; 
		byte hk_data[HOUSE_KEEPING_DATA];
		byte config_param_id[CONFIG_PARAM_ID]; 
		byte config_param_val[CONFIG_PARAM_VAL];
		byte checksum[CHECKSUM_VAL];
	};
	byte arr[FEE_PACKET_SIZE];
};

#endif
