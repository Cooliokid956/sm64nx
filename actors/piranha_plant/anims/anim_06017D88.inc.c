// 0x06017C50
static const s16 piranha_plant_seg6_animvalue_06017C50[] = {
	 0x0000,  0x000e,  0x0003,  0x3fff, -0x7b5d, -0x7df9,  0x7c46,  0x7688, 
	-0x0a23, -0x088d, -0x0511, -0x0195, -0x0101, -0x00d9, -0x0080, -0x0028, 
	-0x7e4b,  0x7f83,  0x7ab5,  0x75e7, -0x214e, -0x0466,  0x6705,  0x1b6d, 
	-0x0871,  0x2b07, -0x3fa3, -0x1ed8, -0x3fff, -0x1ed8, -0x3fa3,  0x0234, 
	 0x023f,  0x0257,  0x026f,  0x0919,  0x0917,  0x0910,  0x090a,  0x2370, 
	 0x23a2,  0x2410,  0x247e, -0x1ed8, -0x3fff, -0x1ed8,  0x00e8,  0x00d0, 
	 0x009c,  0x0068,  0x09ba,  0x09bb,  0x09be,  0x09c2,  0x139b,  0x1336, 
	 0x1259,  0x117b,  0x01dd,  0x019a,  0x0104,  0x006f, -0x077b, -0x0784, 
	-0x0798, -0x07ab, -0x1938, -0x17cb, -0x14a8, -0x1186,  0x3db1,  0x0000, 
	
};

// 0x06017CE0
static const u16 piranha_plant_seg6_animindex_06017CE0[] = {
    0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0000, 0x0001, 0x0003, 0x0001, 0x0000,
    0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x0046,
    0x0004, 0x003A, 0x0004, 0x003E, 0x0004, 0x0042,
    0x0004, 0x002E, 0x0004, 0x0032, 0x0004, 0x0036,
    0x0004, 0x001F, 0x0004, 0x0023, 0x0004, 0x0027,
    0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x001E,
    0x0001, 0x0000, 0x0001, 0x0000, 0x0004, 0x0004,
    0x0001, 0x0000, 0x0001, 0x0000, 0x0001, 0x001A,
    0x0004, 0x0008, 0x0004, 0x000C, 0x0004, 0x0010,
    0x0001, 0x002B, 0x0001, 0x002C, 0x0001, 0x002D,
    0x0001, 0x0014, 0x0001, 0x0015, 0x0001, 0x0016,
    0x0001, 0x001B, 0x0001, 0x001C, 0x0001, 0x001D,
    0x0001, 0x0017, 0x0001, 0x0018, 0x0001, 0x0019,
};

// 0x06017D88
static const struct Animation piranha_plant_seg6_anim_06017D88 = {
	Animation::Flags::NONE,
    0,
    0,
    0,
    0x04,
    ANIMINDEX_NUMPARTS(piranha_plant_seg6_animindex_06017CE0),
    piranha_plant_seg6_animvalue_06017C50,
    piranha_plant_seg6_animindex_06017CE0,
    0,
};