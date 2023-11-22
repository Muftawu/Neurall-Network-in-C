// File containing training data 

#if !defined(DATA)
#define DATA

typedef float sample[][2];

sample data1 = {
	{12.3, 45.6},
	{88.9, 17.6},
	{63.6, 102.2},
	{4.2, 9.96},
};

// predicting where a person of certain age
// will boy insurance from a company

sample data = {
	{22, 0},
	{25, 0},
	{47, 1},
	{52, 0},
	{46, 1},
	{56, 1},
	{55, 0},
	{60, 1},
	{62, 1},
	{61, 1},
	{18, 0},
	{28, 0},
	{27, 0},
	{29, 0},
	{49, 1},
};

sample data3 = {
	{2, 4},
	{4, 8},
	{8, 16},
	{16, 33},
};


#endif // DATA
