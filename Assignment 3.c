//Sharanya Raghunath 11250416 

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t;
typedef unsigned short int uint16_t;

FILE *f;

int main() {
	unsigned int i;
	char buf[200];
	uint16_t ir = 0;
	uint8_t n0, n1, n2, n3, b0, b1, pc = 0, r[16], m[256];
	for (i = 0; i < sizeof(r)/sizeof(r[0]); ++i) r[i] = 0;
	for (i = 0; i < sizeof(m)/sizeof(m[0]); ++i) m[i] = 0;
	f = fopen("a3.txt", "r");
	if (f == NULL) {
		printf("Error! Cannot open the file.\n");
		exit(99);
	}
	while (fgets(buf, sizeof(buf), f) != NULL) {
      uint16_t t;
      long v;
      char *e;
		v = strtol(buf, &e, 16);
		if (v < 0 || v > 0xFFFF) {
			printf("PC=%X : %lX is negative or more than 16 bits in size.\n", (unsigned int) pc, v);
			return 0;
		}
		t = (uint16_t) v;
		m[pc++] = t >> 8;
		m[pc++] = t & 0xFF;
	}
	fclose(f);
	pc = 0;
	b0 = m[pc++];
	b1 = m[pc--];
	do {
		ir = b0 << 8 | b1; n0 = b0 >> 4; n1 = b0 & 0xF; n2 = b1 >> 4; n3 = b1 & 0xF;
		printf("%02X %04X -", (unsigned int) pc, (unsigned int) ir);
		for (i = 0; i < sizeof(r)/sizeof(r[0]); ++i)
			printf(" %02X", (unsigned int) r[i]);
		putchar('\n');
		pc += 2;
		switch (n0) {
		case 0x0:
		case 0x6:
		case 0xC:
		case 0xE:
		case 0xF:
			break;
		case 0x1:
			r[n1] = m[b1];
			break;
		case 0x2:
			r[n1] = b1;
			break;
		case 0x3:
			m[b1] = r[n1];
			break;
		case 0x4:
			r[n3] = r[n2];
			break;
		case 0x5:
			r[n3] = r[n1] + r[n2];
			break;
		case 0x7:
			r[n3] = r[n1] | r[n2];
			break;
		case 0x8:
			r[n3] = r[n1] & r[n2];
			break;
		case 0x9:
			r[n3] = r[n1] ^ r[n2];
			break;
		case 0xA:
			for (i = 0; i < n3; ++i)
				r[n1] = (r[n1] >> 1) | ((r[n1] & 1) << 7);
			break;
        case 0xB:
            if (r[n1] == r[0]) pc = b1;
            break;
        case 0xD:
            if (r[n1] > r[0]) pc = b1;
            break;
        }
		b0 = m[pc++];
		b1 = m[pc--];        
	} while(n0 != 0xC);
	return 0;
} 
